#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class Vigenere : public drogon::HttpSimpleController<Vigenere> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // Defina a rota para o controlador Vigenere
    PATH_ADD("/vigenere", Post); // Responde a requisições POST
    PATH_LIST_END
};
