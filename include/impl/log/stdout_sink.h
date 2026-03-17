//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_STDOUT_SINK_H
#define SI_LIB_LOG_STDOUT_SINK_H

#include "../../compat/sconfig.h"
#include "sink.h"
#include "color.h"
#include <cstdio>

SI_NAMESPACE_START
    class stdout_sink : public log_sink {
    public:
        void log(log_level level, const char* message) override {
            if (!should_log(level)) return;

            const char* color_code = "";
            switch (level) {
                case log_level::TRACE: color_code = log_color_to_ansi(log_color::WHITE); break;
                case log_level::DEBUG: color_code = log_color_to_ansi(log_color::CYAN); break;
                case log_level::INFO:  color_code = log_color_to_ansi(log_color::GREEN); break;
                case log_level::WARN:  color_code = log_color_to_ansi(log_color::YELLOW); break;
                case log_level::ERROR: color_code = log_color_to_ansi(log_color::RED); break;
                case log_level::FATAL: color_code = log_color_to_ansi(log_color::BRIGHT_RED); break;
                default: break;
            }

            std::printf("%s[%-5s]%s %s\n", color_code, log_level_to_string(level), log_color_to_ansi(log_color::RESET), message);
        }

        void flush() override {
            std::fflush(stdout);
        }
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_STDOUT_SINK_H
