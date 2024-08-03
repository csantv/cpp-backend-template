#include "application.hpp"

#include <spdlog/spdlog.h>

void Application::run() {
    app.get("/*", [] (auto *res, [[maybe_unused]] auto *req) {
        res->end("Hello, World!");
    }).listen(3000, [] (auto *listen_socket) {
        if (listen_socket != nullptr) {
            SPDLOG_INFO("listening on port 3000");
        }
    }).run();
}

void Application::stop() {
    uWS::App old_app(app.close());
}
