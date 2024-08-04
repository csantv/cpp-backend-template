#include "application.hpp"

int main()
{
    Application::setup_signals();
    Application::run();
    return 0;
}
