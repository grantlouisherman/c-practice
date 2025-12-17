#include "http_server.h"
#include <iostream>
#include <sstream>
#include <unistd.h>

const int BUFFER_SIZE = 30720;

namespace http {
  TcpServer::TcpServer(std::string ip_address, int port): m_ip_address(ip_address),
  m_port(port), m_socket(), m_new_socket(), m_incomingMessage(), m_socketAdress(),
  m_socketAdress_len(sizeof(m_socketAdress)), m_serverMessage(buildResponse()){
    m_socketAdress.sin_family = AF_INET;
    m_socketAdress.sin_port = htons(m_port);
    m_socketAdress.sin_addr.s_addr = inet_addr(m_ip_adress.c_str());
    if(startServer() != 0){
      std::ostringstream ss;
      ss << "Failed to start server with PORT: " << ntohs(m_ip_address.c_str());
      log(ss.str());
    }
  }
  TcpServer::~TcpServer(){
    closeServer();
  }
  int TcpServer::startServer(){
   m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket < 0){
      exitWithError("socket failed");
      return 1;
    }
    if(bind(m_socket, (sockdadr *)&m_socketAdress, m_socketAdress_len) < 0){
      exitWithError("cannot connect");
      return 1;
    }
    return 0;
  }
  void TcpServer::closeServer(){
    close(m_socket);
    close(m_new_socket);
    exit(0);
  }
  void log(const std::string &message){
    std::cout << message << std::endl;
  }
  void exitWithError(const std::string &errorMessage){
    log("ERROR: " + errorMessage);
    exit(1);
  }
}
