#include "HelloController.h"
#include <drogon/drogon.h>

void HelloController::sayHello(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("<h1>Hello from custom controller!</h1>");
    callback(resp);
}
