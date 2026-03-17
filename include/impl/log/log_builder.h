//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_LOG_BUILDER_H
#define SI_LIB_LOG_LOG_BUILDER_H

#include "../../compat/sconfig.h"
#include "level.h"
#include <sstream>
#include <string>

SI_NAMESPACE_START
    class logger;

    class log_builder {
    public:
        log_builder(logger& l, log_level lvl);
        ~log_builder();

        template<typename T>
        log_builder& operator<<(const T& msg) {
            oss_ << msg;
            return *this;
        }

    private:
        logger& logger_;
        log_level level_;
        std::ostringstream oss_;
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_LOG_BUILDER_H
