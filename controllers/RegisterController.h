#pragma once
#include <drogon/HttpController.h>

class RegisterController: public drogon::HttpController<RegisterController> {
public:
    METHOD_LIST_BEGIN
    // Adicionar métodos para requisição aqui
    METHOD_ADD(RegisterController::postRegister, "/register", drogon::Post);
    METHOD_LIST_END

    void postRegister(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};
