#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

namespace http {
  class TcpServer{
    public:
      TcpServer(std::string ip_address, int port);
      ~TcpServer();
      void startListen();

    private:
      std::string m_ip_address;
      int m_port;
      int m_socket;
      int m_new_socket;
      long m_incomingMessage;
      struct sockaddr_in m_socketAdress;
      unsigned int m_socketAdress_len;
      std::string m_serverMessage;

      int startServer();
      void closeServer();
      void log(const std::string &message);
      void exitWithError(const std::string &errorMessage);
      void acceptConnection(int &new_socket);
      std::string buildResponse();
      void sendResponse();
  };
} // namespace http
