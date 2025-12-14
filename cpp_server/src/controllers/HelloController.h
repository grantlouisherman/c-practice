#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class HelloController : public HttpController<HelloController> {
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(HelloController::sayHello, "/hello", Get);
    METHOD_LIST_END
    
      void sayHello(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback);
};
