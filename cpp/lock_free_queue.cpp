#ifdef BOOST_LOCK_FREE_QUEUE
// 摘抄自boost::lock_free::queue
// push的核心原子操作为：CAS(tail->next, nullptr, newTail)和CAS(tail, tail, newTail)
// pop 的核心原子操作为：CAS(head, head, head->next)
bool do_push(T const & t)
{
    node * n = pool.template construct<true, Bounded>(t, pool.null_handle());
    handle_type node_handle = pool.get_handle(n);

    if (n == NULL)
        return false;

    for (;;) {
        // 获取tail
        tagged_node_handle tail = tail_.load(memory_order_acquire);
        node * tail_node = pool.get_pointer(tail);
        // 获取tail->next
        tagged_node_handle next = tail_node->next.load(memory_order_acquire);
        node * next_ptr = pool.get_pointer(next);
        // 重新读取tail
        tagged_node_handle tail2 = tail_.load(memory_order_acquire);
        // 检测在两次获取tail期间是否存在其他线程正在执行push
        if (BOOST_LIKELY(tail == tail2)) {
            // 若tail->next为空指针，说明此时还无其他线程正在执行push
            if (next_ptr == 0) {
                // 待插入的数据节点
                tagged_node_handle new_tail_next(node_handle, next.get_next_tag());
                // 进行抢占，将tail->next更新为新插入节点
                if ( tail_node->next.compare_exchange_weak(next, new_tail_next) ) {
                    // 然后将tail更新
                    tagged_node_handle new_tail(node_handle, tail.get_next_tag());
                    tail_.compare_exchange_strong(tail, new_tail);
                    return true;
                }
            }
            // 若tail->next非空指针，说明此时正有线程执行push，已更新tail->next但还未更新tail
            else {
                // 帮助那个线程更新tail为tail->next
                tagged_node_handle new_tail(pool.get_handle(next_ptr), tail.get_next_tag());
                tail_.compare_exchange_strong(tail, new_tail);
            }
        }
    }
}

template <typename U>
bool pop (U & ret)
{
    for (;;) {
        // 获取head
        tagged_node_handle head = head_.load(memory_order_acquire);
        node * head_ptr = pool.get_pointer(head);
        // 获取tail与head->next
        tagged_node_handle tail = tail_.load(memory_order_acquire);
        tagged_node_handle next = head_ptr->next.load(memory_order_acquire);
        node * next_ptr = pool.get_pointer(next);
        // 重新获取head
        tagged_node_handle head2 = head_.load(memory_order_acquire);
        // 检测两次获取head期间是否存在其他线程正在执行pop
        if (BOOST_LIKELY(head == head2)) {
            // 空队列
            if (pool.get_handle(head) == pool.get_handle(tail)) {
                // 真的空队列
                if (next_ptr == 0)
                    return false;
                // 或者有其他线程处于enqueue中间态，帮其更新tail
                tagged_node_handle new_tail(pool.get_handle(next), tail.get_next_tag());
                tail_.compare_exchange_strong(tail, new_tail);

            } else {
                if (next_ptr == 0)
                    /* this check is not part of the original algorithm as published by michael and scott
                     *
                     * however we reuse the tagged_ptr part for the freelist and clear the next part during node
                     * allocation. we can observe a null-pointer here.
                     * */
                    continue;
                // 将pop元素返回
                detail::copy_payload(next_ptr->data, ret);
                // next作为new_head
                tagged_node_handle new_head(pool.get_handle(next), head.get_next_tag());
                // 若此时head_仍等于head，则表示无其他线程抢占pop，即new_head有效
                if (head_.compare_exchange_weak(head, new_head)) {
                    pool.template destruct<true>(head);
                    return true;
                }
            }
        }
    }
}

template<typename T>
void push(const T& elem)
{
    auto* newNode = new Node{elem, nullptr};
    for ( ; ; ) {
        auto* tail = tail_.load();
        if ( !tail_->next.compare_exchange_weak(nullptr, newNode) ) {
            ;
        } else {
            tail_->compare_exchange_strong(tail, newNode);
            return;
        }
    }
}

bool pop(Node& ret)
{
    auto* head = head_.load();
    auto* next = head->next_;
    auto* tail = tail_.load();
    for ( ; ; ) {
        if ( head == tail ) {
            if ( next == nullptr )
                return false;
            auto* dummy = new Node{};
            head_.compare_exchange_strong()
        }
    }
}
#endif


