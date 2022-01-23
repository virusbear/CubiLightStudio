//
// Created by Virusbear on 23.01.2022.
//

#ifndef CUBILIGHTSTUDIO_LOG_H
#define CUBILIGHTSTUDIO_LOG_H

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace CubiLight {
    class Log {
    public:
        explicit Log(const std::string& name);
        ~Log();

        void Trace(const std::string& msg);
        void Info(const std::string& msg);
        void Warn(const std::string &msg);
        void Error(const std::string &msg);
        void Fatal(const std::string &msg);
    private:
        std::shared_ptr<spdlog::logger> logger;
    };
}



#endif //CUBILIGHTSTUDIO_LOG_H
