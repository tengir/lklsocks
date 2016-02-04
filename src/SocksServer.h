#ifndef SOCKSSERVER_H_
#define SOCKSSERVER_H_

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "SocksConnection.h"

class SocksServer {
public:
    SocksServer(unsigned short port, boost::asio::io_service &io_service);
    virtual ~SocksServer();

protected:
    boost::asio::ip::tcp::acceptor acceptor;

    void startAccept();
    void handleAccept(SocksConnection::ptr_t connection, boost::system::error_code const &error);
};

#endif /* SOCKSSERVER_H_ */