//
// Created by Virusbear on 23.01.2022.
//

#include "Log.h"

namespace CubiLight {
    Log::Log(const std::string& name) {
        logger = spdlog::stderr_color_mt(name);
        logger->set_pattern("%+");
        logger->set_level(spdlog::level::trace);
    }

    Log::~Log() {
        spdlog::drop(logger->name());
    }

    void Log::Trace(const std::string& msg) {
        logger->trace(msg);
    }

    void Log::Info(const std::string& msg) {
        logger->info(msg);
    }

    void Log::Warn(const std::string& msg) {
        logger->warn(msg);
    }

    void Log::Error(const std::string& msg) {
        logger->error(msg);
    }

    void Log::Fatal(const std::string& msg) {
        logger->critical(msg);
    }
}