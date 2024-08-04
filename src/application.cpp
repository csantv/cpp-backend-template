#include "application.hpp"

#include <spdlog/spdlog.h>

void Application::run() {
    spdlog::flush_on(spdlog::level::info);

    SPDLOG_INFO("starting backend");
    server.get("/*", [] (auto *res, [[maybe_unused]] auto *req) {
        res->end("Hello, World!");
    }).listen(3000, listen_handler).run();
}

void Application::listen_handler(us_listen_socket_t *listen_socket) {
    if (socket != nullptr) {
        listen_socket_ = listen_socket;
        SPDLOG_INFO("listening on port 3000");
    }
}

void Application::stop() {
    SPDLOG_WARN("stopping backend");
    uWS::App old_app(server.close());
}
