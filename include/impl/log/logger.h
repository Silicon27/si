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
#include "log_builder.h"

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

        // Overloads for log builder (operator<<)
        log_builder trace() { return log_builder(*this, log_level::TRACE); }
        log_builder debug() { return log_builder(*this, log_level::DEBUG); }
        log_builder info() { return log_builder(*this, log_level::INFO); }
        log_builder warn() { return log_builder(*this, log_level::WARN); }
        log_builder error() { return log_builder(*this, log_level::ERROR); }
        log_builder fatal() { return log_builder(*this, log_level::FATAL); }

        template<typename... Args>
        void log(log_level level, const char* fmt, Args&&... args) {
            char buffer[1024];
            std::snprintf(buffer, sizeof(buffer), fmt, std::forward<Args>(args)...);

            for (auto& sink : sinks_) {
                sink->log(level, buffer);
            }
        }

        void log_message(log_level level, const char* message) {
            for (auto& sink : sinks_) {
                sink->log(level, message);
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

    inline log_builder::log_builder(logger& l, log_level lvl) : logger_(l), level_(lvl) {}
    inline log_builder::~log_builder() {
        std::string s = oss_.str();
        if (!s.empty()) {
            logger_.log_message(level_, s.c_str());
        }
    }
SI_NAMESPACE_END

#endif //SI_LIB_LOG_LOGGER_H
