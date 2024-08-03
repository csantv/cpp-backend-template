#include "signal.hpp"
#include "application.hpp"

#include <Windows.h>

BOOL WINAPI console_handler([[maybe_unused]] DWORD signal) {
    Application::stop();
    return TRUE;
}

void signal::setup_handlers() {
    SetConsoleCtrlHandler(console_handler, TRUE);
}
