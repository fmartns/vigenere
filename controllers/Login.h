#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class Login : public drogon::HttpSimpleController<Login> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/GetLogin", Post); // Responde a requisições POST
    PATH_LIST_END
};
