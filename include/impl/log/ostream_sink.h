//
// Created by Junie on 2026-03-17.
//

#ifndef SI_LIB_LOG_OSTREAM_SINK_H
#define SI_LIB_LOG_OSTREAM_SINK_H

#include "../../compat/sconfig.h"
#include "sink.h"
#include <ostream>

SI_NAMESPACE_START
    class ostream_sink : public log_sink {
    public:
        explicit ostream_sink(std::ostream& os) : os_(os) {}

        void log(log_level level, const char* message) override {
            if (!should_log(level)) return;
            os_ << "[" << log_level_to_string(level) << "] " << message << std::endl;
        }

        void flush() override {
            os_.flush();
        }

    private:
        std::ostream& os_;
    };
SI_NAMESPACE_END

#endif //SI_LIB_LOG_OSTREAM_SINK_H
