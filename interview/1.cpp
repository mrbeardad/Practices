#include <gtest/gtest.h>

typedef struct RingQueue {
    unsigned char *buffer;    // 指向该队列的指针 
    unsigned char *rptr;      // 读指针
    unsigned char *wptr;      // 写指针
    unsigned char *end;       // 指向RingQueue的内存尾部
    int size;  // 被分配的RingQueue结构的内存空间大小
} RingQueue;

// 初始化，为队列分配大小为size的内存空间
int ring_queue_init(RingQueue *rq, int size)
{
    try {
        rq->buffer = new unsigned char[size]{};
    } catch (...) {
        return -1;
    }
    rq->end = rq->buffer + size;
    rq->rptr = rq->buffer;
    rq->wptr = rq->buffer;
    rq->size = 0;
    return size;
}

// 释放内存
void ring_queue_free(RingQueue *rq)
{
    delete [] rq->buffer;
}

// 获取队列中的数据长度，返回值为数据长度
int ring_queue_size(RingQueue *rq)
{

    return rq->size;
}

// 写队列，返回0表示成功
int ring_queue_write(RingQueue *rq, const unsigned char *buf, int buf_size)
{
    // 如果空闲空间过小
    if ( buf_size > rq->end - rq->buffer - rq->size )
        return -1;

    rq->size += buf_size;
    int idx(rq->wptr - rq->buffer);
    for ( int bufIdx{}; bufIdx < buf_size; ) {
        rq->buffer[idx] = buf[bufIdx];
        ++bufIdx;
        idx = (idx + 1) % (rq->end - rq->buffer);
    }
    rq->wptr = rq->buffer + idx;
    return 0;
}

// 读队列，返回0表示成功
int ring_queue_read(RingQueue *rq, void *dest_buf, int buf_size)
{
    if ( rq->size == 0 )
        return -1;

    int origSize{rq->size};
    int idx(rq->rptr - rq->buffer);
    int bufIdx{};
    for ( ; bufIdx < buf_size && rq->size > 0; ) {
        reinterpret_cast<char*>(dest_buf)[bufIdx] = rq->buffer[idx];
        ++bufIdx;
        --rq->size;
        idx = (idx + 1) % (rq->end - rq->buffer);
    }
    rq->rptr = rq->buffer + idx;
    // 返回读取的真实长度
    if ( bufIdx == buf_size )
        return buf_size;
    else
        return origSize;
}

TEST(Test, TestCase)
{
    RingQueue rque{};
    std::vector<unsigned char> buf{'0','1','2','3','4','5','6','7','8','9'};
    EXPECT_EQ(ring_queue_init(&rque, 10), 10);

    EXPECT_EQ(ring_queue_read(&rque, buf.data(), 10), -1);

    EXPECT_EQ(ring_queue_write(&rque, buf.data(), 10), 0);
    EXPECT_EQ(ring_queue_read(&rque, buf.data(), 10), 10);

    std::vector<unsigned char> buf2{'0','1','2','3','4','5','6','7','8','9'};
    EXPECT_EQ(buf, buf2);

    EXPECT_EQ(ring_queue_size(&rque), 0);

    std::cout << "\e[31mfuck:\e[m " << rque.size << std::endl;
    EXPECT_EQ(ring_queue_write(&rque, buf.data(), 3), 0);
    std::cout << "\e[31mfuck:\e[m " << rque.size << std::endl;
    EXPECT_EQ(ring_queue_read(&rque, buf.data() + 1, 9), 3);
    std::cout << "\e[31mfuck:\e[m " << rque.size << std::endl;

    std::vector<unsigned char> buf3{'0','0','1','2','4','5','6','7','8','9'};
    EXPECT_EQ(buf, buf3);

}
