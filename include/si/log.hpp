//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_HPP
#define SI_LIB_LOG_HPP

#include "../compat/sconfig.h"
#include "../impl/log/level.h"
#include "../impl/log/color.h"
#include "../impl/log/sink.h"
#include "../impl/log/stdout_sink.h"
#include "../impl/log/file_sink.h"
#include "../impl/log/logger.h"

SI_NAMESPACE_START
    inline logger& default_logger() {
        static logger l;
        static bool initialized = false;
        if (!initialized) {
            auto sink = std::make_shared<stdout_sink>();
            l.add_sink(sink);
            initialized = true;
        }
        return l;
    }

    template<typename... Args>
    void trace(const char* fmt, Args&&... args) {
        default_logger().trace(fmt, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void debug(const char* fmt, Args&&... args) {
        default_logger().debug(fmt, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void info(const char* fmt, Args&&... args) {
        default_logger().info(fmt, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void warn(const char* fmt, Args&&... args) {
        default_logger().warn(fmt, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void error(const char* fmt, Args&&... args) {
        default_logger().error(fmt, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void fatal(const char* fmt, Args&&... args) {
        default_logger().fatal(fmt, std::forward<Args>(args)...);
    }
SI_NAMESPACE_END

#endif //SI_LIB_LOG_HPP
