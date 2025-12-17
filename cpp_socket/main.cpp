#include<iostream>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "http_server.h"
int main(){
  using namespace http;
  TcpServer server = TcpServer("0.0.0.0", 8080);
  return 0;
}
