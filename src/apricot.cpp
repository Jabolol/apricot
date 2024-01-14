#include "../inc/apricot.h"
#include <iostream>

Apricot::Apricot(sio::client &client) : _client(client)
{
    client.set_open_listener(std::bind(&Apricot::onConnected, this));
}

Apricot::~Apricot()
{
    _client.sync_close();
    _client.clear_con_listeners();
}

void Apricot::onConnected()
{
    _lock.lock();
    _cond.notify_all();
    _connected = true;
    _lock.unlock();
}

void handleMessage(std::string const &name, sio::message::ptr const &data,
    bool isAck, sio::message::list &ack_resp)
{
}

void Apricot::bindEvents()
{
    auto messageHandler = [&](std::string const &name,
                              sio::message::ptr const &data, bool isAck,
                              sio::message::list &ack_resp) {
        _lock.lock();
        std::cout << "<< " << data->get_string() << std::endl;
        _lock.unlock();
    };
    _socket->on("echo", sio::socket::event_listener_aux(messageHandler));
}

const sio::client &Apricot::getClient() const
{
    return _client;
}

const sio::socket::ptr &Apricot::getSocket() const
{
    return _socket;
}

void Apricot::connect(std::string const &uri)
{
    _client.connect(uri);
    _lock.lock();
    if (!_connected) {
        std::cout << "waiting..." << std::endl;
        _cond.wait(_lock);
    }
    _lock.unlock();
    _socket = _client.socket();
}
