#include "application.hpp"

#include <spdlog/spdlog.h>

#ifdef OS_UNIX
#include <csignal>
#endif

#ifdef OS_WINDOWS
#include <Windows.h>

BOOL WINAPI console_handler(DWORD) {
    Application::stop();
    return TRUE;
}
#endif

void Application::setup_signals() {
#ifdef OS_WINDOWS
    SetConsoleCtrlHandler(console_handler, TRUE);
#endif

#ifdef OS_UNIX
    struct sigaction sga {
    };
    sga.sa_handler = [] (int) {
        stop();
    };
    sigemptyset(&sga.sa_mask);
    sga.sa_flags = 0;
    sigaction(SIGINT, &sga, nullptr);
    sigaction(SIGTERM, &sga, nullptr);
    sigaction(SIGHUP, nullptr, nullptr);
    sigaction(SIGCHLD, nullptr, nullptr);
#endif
}

void Application::run() {
    spdlog::flush_on(spdlog::level::info);

    SPDLOG_INFO("starting backend");
    server.get("/*", [] (auto *res, [[maybe_unused]] auto *req) {
        res->end("Hello, World!");
    }).listen(3000, listen_handler).run();
}

void Application::listen_handler(const us_listen_socket_t *listen_socket) {
    if (listen_socket != nullptr) {
        SPDLOG_INFO("listening on port 3000");
    }
}

void Application::stop() {
    SPDLOG_WARN("stopping backend");
    uWS::App old_app(server.close());
}
