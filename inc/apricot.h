#include <mutex>
#include "sio_client.h"
#include "sio_socket.h"
#include <condition_variable>

#ifndef __APRICO_H__
    #define __APRICO_H__

class Apricot {
  private:
    std::mutex _lock;
    std::condition_variable_any _cond;
    bool _connected = false;
    sio::client &_client;
    sio::socket::ptr _socket;
    void onConnected();

  public:
    Apricot(sio::client &client);
    ~Apricot();
    void bindEvents();
    void connect(std::string const &uri);
    const sio::client &getClient() const;
    const sio::socket::ptr &getSocket() const;
};

#endif
