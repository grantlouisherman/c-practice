#include <drogon/drogon.h>
#include "controllers/HelloController.h"
#include <iostream>
using namespace drogon;
int main(int argc, char* argvc[]) {
  std::cout << "Starting server .....";
  drogon::app()
        .addListener("0.0.0.0", 8088)
        .setDocumentRoot("./public") // Make sure this exists
        .run();
  std::cout << "Shutting down server ..";
 }
