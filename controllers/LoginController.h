#pragma once
#include <drogon/HttpController.h>

class LoginController: public drogon::HttpController<LoginController> {
public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD para adicionar seus métodos de requisição
    METHOD_ADD(LoginController::postLogin,"/login", drogon::Post);
    METHOD_LIST_END

    void postLogin(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
};
