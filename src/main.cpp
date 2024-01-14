#include <iostream>
#include <unistd.h>
#include "../inc/apricot.h"
#include "sio_client.h"

int main(void)
{
    sio::client client;
    Apricot apricot(client);

    apricot.connect("ws://localhost:3000");
    apricot.bindEvents();

    std::cout << "apricot :: echo server" << std::endl;
    std::cout << "type 'exit' to quit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    while (true) {
        std::string message;

        while (message.length() == 0) {
            std::getline(std::cin, message);
        }
        if (message == "exit") {
            std::cout << "-----------------------------------" << std::endl;
            break;
        }
        apricot.getSocket()->emit("echo", message);
    }

    return 0;
}
