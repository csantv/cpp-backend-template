#include "signal.hpp"
#include <csignal>

namespace {
     void signal_handler(int) {
         uWS::App app(Application::app.close());
     }
}

void signal::setup_handlers() {
    struct sigaction sga {
    };
    sga.sa_handler = signal_handler;
    sigemptyset(&sga.sa_mask);
    sga.sa_flags = 0;
    sigaction(SIGINT, &sga, nullptr);
    sigaction(SIGTERM, &sga, nullptr);
    sigaction(SIGHUP, nullptr, nullptr);
    sigaction(SIGCHLD, nullptr, nullptr);
}