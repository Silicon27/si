//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_FILE_SINK_H
#define SI_LIB_LOG_FILE_SINK_H

#include "../../compat/sconfig.h"
#include "sink.h"
#include <cstdio>

SI_NAMESPACE_START
    class file_sink : public log_sink {
    public:
        explicit file_sink(const char* filename) {
            file_ = std::fopen(filename, "a");
        }

        ~file_sink() override {
            if (file_) {
                std::fclose(file_);
            }
        }

        void log(log_level level, const char* message) override {
            if (!should_log(level) || !file_) return;

            std::fprintf(file_, "[%s] %s\n", log_level_to_string(level), message);
        }

        void flush() override {
            if (file_) {
                std::fflush(file_);
            }
        }

        bool is_open() const { return file_ != nullptr; }

    private:
        std::FILE* file_ = nullptr;
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_FILE_SINK_H
