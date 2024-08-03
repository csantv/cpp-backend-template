#include "application.hpp"
//
// #include <csignal>
// #include <iostream>
//
// namespace {
//     void signal_handler(int) {
//         uWS::App app(Application::app.close());
//     }
// }

int main()
{
    // struct sigaction sga {
    // };
    // sga.sa_handler = signal_handler;
    // sigemptyset(&sga.sa_mask);
    // sga.sa_flags = 0;
    // sigaction(SIGINT, &sga, nullptr);
    // sigaction(SIGTERM, &sga, nullptr);
    // sigaction(SIGHUP, nullptr, nullptr);
    // sigaction(SIGCHLD, nullptr, nullptr);

    Application::run();
    return 0;
}
