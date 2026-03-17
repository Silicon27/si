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

        template<typename... Args>
        void trace(const char* fmt, Args&&... args) { 
            log(log_level::TRACE, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        void debug(const char* fmt, Args&&... args) { 
            log(log_level::DEBUG, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        void info(const char* fmt, Args&&... args) { 
            log(log_level::INFO, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        void warn(const char* fmt, Args&&... args) { 
            log(log_level::WARN, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        void error(const char* fmt, Args&&... args) { 
            log(log_level::ERROR, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        void fatal(const char* fmt, Args&&... args) { 
            log(log_level::FATAL, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void log(log_level level, const char* fmt, Args&&... args) {
            char buffer[1024];
            std::snprintf(buffer, sizeof(buffer), fmt, std::forward<Args>(args)...);

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
