//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_LOGGER_H
#define SI_LIB_LOG_LOGGER_H

#include "../../compat/sconfig.h"
#include "sink.h"
#include <cstdio>
#include <cstdarg>
#include <vector>
#include <memory>

SI_NAMESPACE_START
    class logger {
    public:
        void add_sink(std::shared_ptr<log_sink> sink) {
            sinks_.push_back(sink);
        }

        void trace(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::TRACE, fmt, args); 
            va_end(args);
        }
        void debug(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::DEBUG, fmt, args); 
            va_end(args);
        }
        void info(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::INFO, fmt, args); 
            va_end(args);
        }
        void warn(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::WARN, fmt, args); 
            va_end(args);
        }
        void error(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::ERROR, fmt, args); 
            va_end(args);
        }
        void fatal(const char* fmt, ...) { 
            va_list args;
            va_start(args, fmt);
            log_valist(log_level::FATAL, fmt, args); 
            va_end(args);
        }

        void log_valist(log_level level, const char* fmt, va_list args) {
            char buffer[1024];
            vsnprintf(buffer, sizeof(buffer), fmt, args);

            for (auto& sink : sinks_) {
                sink->log(level, buffer);
            }
        }

        void flush() {
            for (auto& sink : sinks_) {
                sink->flush();
            }
        }

    private:
        std::vector<std::shared_ptr<log_sink>> sinks_;
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_LOGGER_H
