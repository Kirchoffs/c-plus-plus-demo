#include "logger.h"

#include <iostream>
#include <stdexcept>
#include <time.h>
#include <stdarg.h>

namespace syh {

const char* Logger::levels_[] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

Logger* Logger::instance_ = nullptr;

Logger::Logger() {}

Logger::~Logger() {
    close();
}

Logger* Logger::instance() {
    if (instance_ == nullptr) {
        instance_ = new Logger();
    }
    return instance_;
}

void Logger::open(const string& filename) {
    filename_ = filename;
    fout_.open(filename_, ios::app);
    if (fout_.fail()) {
        throw std::logic_error("failed to open log file " + filename_);
    }

    fout_.seekp(0, ios::end);
    current_size_ = fout_.tellp();
}

void Logger::close() {
    if (fout_.is_open()) {
        fout_.close();
    }
}

void Logger::log(Level level, const char* file, int line, const char* format, ...) {
    if (level < level_) {
        return;
    }

    if (fout_.fail()) {
        throw std::logic_error("log file is not opened");
    }

    time_t ticks = time(nullptr);
    struct tm* tm = localtime(&ticks);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    
    const char* header_format = "%s %s %s:%d ";
    int size = snprintf(nullptr, 0, header_format, timestamp, levels_[level], file, line);
    current_size_ += size;
    char* header = new char[size + 1];
    snprintf(header, size + 1, header_format, timestamp, levels_[level], file, line);
    header[size] = '\0';
    fout_ << header;
    delete[] header;

    va_list args;
    va_start(args, format);
    size = vsnprintf(nullptr, 0, format, args);
    current_size_ += size;
    va_end(args);

    char* buffer = new char[size + 1];
    va_start(args, format);
    vsnprintf(buffer, size + 1, format, args);
    va_end(args);
    fout_ << buffer;
    delete[] buffer;

    fout_ << endl;
    fout_.flush();

    if (max_size_ > 0 && current_size_ >= max_size_) {
        rotate();
    }
}

void Logger::set_level(Level level) {
    level_ = level;
}

void Logger::set_max_size(int max_size) {
    max_size_ = max_size;
}

void Logger::rotate() {
    close();

    time_t ticks = time(nullptr);
    struct tm* tm = localtime(&ticks);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", tm);
    string old_filename = filename_ + "." + timestamp;
    if (rename(filename_.c_str(), old_filename.c_str()) != 0) {
        throw std::logic_error("failed to rename log file " + filename_);
    }

    open(filename_);
}

};
