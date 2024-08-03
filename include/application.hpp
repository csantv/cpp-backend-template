#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <uWebSockets/App.h>

class Application {
public:
    static void run();

    inline static uWS::App app;
};

#endif //APPLICATION_HPP
