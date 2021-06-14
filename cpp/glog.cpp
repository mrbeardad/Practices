#include <glog/logging.h>
#include <iostream>

#include "mine.hpp"

int main(int argc, char* argv[])
{
    FLAGS_logtostderr = 1;
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "test";

    return 0;
}

