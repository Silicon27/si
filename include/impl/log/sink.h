//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_SINK_H
#define SI_LIB_LOG_SINK_H

#include "../../compat/sconfig.h"
#include "level.h"

SI_NAMESPACE_START
    class log_sink {
    public:
        virtual ~log_sink() = default;
        virtual void log(log_level level, const char* message) = 0;
        virtual void flush() = 0;

        void set_level(log_level level) { level_ = level; }
        log_level get_level() const { return level_; }

        bool should_log(log_level level) const {
            return level >= level_;
        }

    protected:
        log_level level_ = log_level::TRACE;
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_SINK_H
