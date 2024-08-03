#include "signal.hpp"
#include "application.hpp"

#include <Windows.h>
#include <iostream>

BOOL WINAPI console_handler(const DWORD signal) {
    if (signal == CTRL_C_EVENT || signal == CTRL_CLOSE_EVENT) {
        Application::stop();
        return TRUE;
    }
    return FALSE;
}

void signal::setup_handlers() {
    std::cout << "bruh" << std::endl;
    if (!SetConsoleCtrlHandler(console_handler, TRUE)) {
        std::cout << "could not setup console handlers" << std::endl;
    }
}
