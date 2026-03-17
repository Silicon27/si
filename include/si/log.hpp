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
    // Re-export key types if necessary, though they are already in si namespace
SI_NAMESPACE_END

#endif //SI_LIB_LOG_HPP
