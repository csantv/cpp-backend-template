#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <uWebSockets/App.h>

class Application {
public:
    static void run();
    static void stop();
    static void setup_signals();

    static void listen_handler(const us_listen_socket_t *listen_socket);

    inline static uWS::App server;

private:
    us_listen_socket_t *listen_socket_ = nullptr;
};

#endif //APPLICATION_HPP
