/**
 * Copyright (c) 2020-2021 Heachen Bear & Contributors
 * File: t.cpp
 * License: GPLv3
 * Author: Heachen Bear <mrbeardad@qq.com>
 * Date: 09.02.2021
 * Last Modified Date: 14.03.2021
 * Last Modified By: Heachen Bear <mrbeardad@qq.com>
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "mine.hpp"


/*! \class GetLineView
 *  \brief Brief class description
 *
 *  Detailed description
 */
class GetLineView
{
    const std::string* view_;
    size_t curIdx_;
public:
    explicit GetLineView(const std::string& str)
        : view_{&str}, curIdx_{} {  }

    const std::string* reset(const std::string* newPtr)
    {
        std::swap(newPtr, view_);
        return newPtr;
    }

    bool operator()(std::string_view& oneline)
    {
        auto posNL = view_->find('\n', curIdx_);
        if ( posNL != std::string::npos ) {
            oneline = std::string_view{view_->data() + curIdx_, view_->data() + posNL};
            curIdx_ = posNL + 1;
            return true;
        } else if ( curIdx_ < view_->size() ) {
            oneline = std::string_view{view_->data() + curIdx_, view_->data() + view_->size()};
            curIdx_ = posNL; // 防止下次再次进行搜索
            return false;
        } else {
            return false;
        }
    }
};


int main()
{
    std::cout << 1.1e1 << std::endl;

    return 0;
}

