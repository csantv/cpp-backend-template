#include "application.hpp"
#include "signal.hpp"

int main()
{
    signal::setup_handlers();
    Application::run();
    return 0;
}
