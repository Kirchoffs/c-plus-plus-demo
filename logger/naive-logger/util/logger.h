#pragma once

#include <string>
#include <fstream>

using namespace std;

namespace syh {

#define debug(format, ...) \
    Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define info(format, ...) \
    Logger::instance()->log(Logger::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define warn(format, ...) \
    Logger::instance()->log(Logger::WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define error(format, ...) \
    Logger::instance()->log(Logger::ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define fatal(format, ...) \
    Logger::instance()->log(Logger::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

class Logger {
public:
    enum Level {
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LEVEL_COUNT
    };

    static Logger* instance();
    void open(const string& filename);
    void close();
    void log(Level level, const char* file, int line, const char* format, ...);
    void set_level(Level level); 
    void set_max_size(int max_size);

private:
    Logger();
    ~Logger();

    void rotate();

private:
    string filename_;
    ofstream fout_;
    Level level_{DEBUG};
    int max_size_{0};
    int current_size_{0};
    static const char* levels_[LEVEL_COUNT];
    static Logger* instance_;
};

};
