#include <iostream>

#include "util/logger.h"

using namespace syh;

int main() {
    Logger::instance()->open("test.log");
    Logger::instance()->set_max_size(1024);

    Logger::instance()->log(Logger::INFO, __FILE__, __LINE__, "hello, %s", "world");

    debug("answer is %d", 42);
    info("answer is %d", 42);
    warn("answer is %d", 42);
    error("answer is %d", 42);
    fatal("answer is %d", 42);

    Logger::instance()->set_level(Logger::INFO);
    debug("hey %s", "Jude");
    info("hey %s", "Jude");
    warn("hey %s", "Jude");
    error("hey %s", "Jude");
    fatal("hey %s", "Jude");

    debug("don't make it bad");
    info("don't make it bad");
    warn("don't make it bad");
    error("don't make it bad");
    fatal("don't make it bad");

    return 0;
}
