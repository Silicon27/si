//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_COLOR_H
#define SI_LIB_LOG_COLOR_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START
    enum class log_color {
        RESET       = 0,
        BLACK       = 30,
        RED         = 31,
        GREEN       = 32,
        YELLOW      = 33,
        BLUE        = 34,
        MAGENTA     = 35,
        CYAN        = 36,
        WHITE       = 37,
        BRIGHT_BLACK   = 90,
        BRIGHT_RED     = 91,
        BRIGHT_GREEN   = 92,
        BRIGHT_YELLOW  = 93,
        BRIGHT_BLUE    = 94,
        BRIGHT_MAGENTA = 95,
        BRIGHT_CYAN    = 96,
        BRIGHT_WHITE   = 97
    };

    inline const char* log_color_to_ansi(log_color color) {
        switch (color) {
            case log_color::RESET:      return "\033[0m";
            case log_color::BLACK:      return "\033[30m";
            case log_color::RED:        return "\033[31m";
            case log_color::GREEN:      return "\033[32m";
            case log_color::YELLOW:     return "\033[33m";
            case log_color::BLUE:       return "\033[34m";
            case log_color::MAGENTA:    return "\033[35m";
            case log_color::CYAN:       return "\033[36m";
            case log_color::WHITE:      return "\033[37m";
            case log_color::BRIGHT_BLACK:   return "\033[90m";
            case log_color::BRIGHT_RED:     return "\033[91m";
            case log_color::BRIGHT_GREEN:   return "\033[92m";
            case log_color::BRIGHT_YELLOW:  return "\033[93m";
            case log_color::BRIGHT_BLUE:    return "\033[94m";
            case log_color::BRIGHT_MAGENTA: return "\033[95m";
            case log_color::BRIGHT_CYAN:    return "\033[96m";
            case log_color::BRIGHT_WHITE:   return "\033[97m";
            default:                    return "";
        }
    }
SI_NAMESPACE_END

#endif //SI_LIB_LOG_COLOR_H
