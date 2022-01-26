//
// Created by Virusbear on 23.01.2022.
//

#include "../include/Log.h"

namespace CubiLight {
    Log::Log(const std::string& name) {
        m_logger = spdlog::stderr_color_mt(name);
        m_logger->set_pattern("%+");
        m_logger->set_level(spdlog::level::trace);
    }

    Log::~Log() {
        spdlog::drop(m_logger->name());
    }

    void Log::Trace(const std::string& msg) {
        m_logger->trace(msg);
    }

    void Log::Info(const std::string& msg) {
        m_logger->info(msg);
    }

    void Log::Warn(const std::string& msg) {
        m_logger->warn(msg);
    }

    void Log::Error(const std::string& msg) {
        m_logger->error(msg);
    }

    void Log::Fatal(const std::string& msg) {
        m_logger->critical(msg);
    }
}