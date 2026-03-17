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
            log_message(level, buffer);
        }

        void log_message(log_level level, const char* message) {
            if (backtrace_enabled_) {
                add_to_backtrace(level, message);
            }

            for (auto& sink : sinks_) {
                sink->log(level, message);
            }
        }

        void enable_backtrace(size_t n) {
            backtrace_size_ = n;
            backtrace_buffer_.clear();
            backtrace_buffer_.reserve(n);
            backtrace_enabled_ = true;
            backtrace_pos_ = 0;
        }

        void dump_backtrace() {
            if (!backtrace_enabled_ || backtrace_buffer_.empty()) return;

            bool was_enabled = backtrace_enabled_;
            backtrace_enabled_ = false;

            log_message(log_level::INFO, "****************** Dumping backtrace ******************");
            size_t count = backtrace_buffer_.size();
            for (size_t i = 0; i < count; ++i) {
                size_t idx = (backtrace_pos_ + i) % count;
                auto& entry = backtrace_buffer_[idx];
                for (auto& sink : sinks_) {
                    sink->log(entry.level, entry.message.c_str());
                }
            }
            log_message(log_level::INFO, "*******************************************************");

            backtrace_enabled_ = was_enabled;
        }

        void flush() {
            for (auto& sink : sinks_) {
                sink->flush();
            }
        }

    private:
        struct backtrace_entry {
            log_level level;
            std::string message;
        };

        void add_to_backtrace(log_level level, const char* message) {
            if (backtrace_buffer_.size() < backtrace_size_) {
                backtrace_buffer_.push_back({level, message});
            } else {
                backtrace_buffer_[backtrace_pos_] = {level, message};
                backtrace_pos_ = (backtrace_pos_ + 1) % backtrace_size_;
            }
        }

        std::vector<std::shared_ptr<log_sink>> sinks_;
        std::vector<backtrace_entry> backtrace_buffer_;
        size_t backtrace_size_ = 0;
        size_t backtrace_pos_ = 0;
        bool backtrace_enabled_ = false;
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
