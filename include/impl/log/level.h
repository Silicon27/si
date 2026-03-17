//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_LEVEL_H
#define SI_LIB_LOG_LEVEL_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START
    enum class log_level {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        OFF
    };

    inline const char* log_level_to_string(log_level level) {
        switch (level) {
            case log_level::TRACE: return "TRACE";
            case log_level::DEBUG: return "DEBUG";
            case log_level::INFO:  return "INFO";
            case log_level::WARN:  return "WARN";
            case log_level::ERROR: return "ERROR";
            case log_level::FATAL: return "FATAL";
            default:               return "UNKNOWN";
        }
    }
SI_NAMESPACE_END

#endif //SI_LIB_LOG_LEVEL_H
