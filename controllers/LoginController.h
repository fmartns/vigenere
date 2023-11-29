#pragma once
#include <drogon/HttpSimpleController.h>

class LoginController : public drogon::HttpSimpleController<LoginController> {
public:
    virtual void asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/login", drogon::Post); // Use POST para segurança
    PATH_LIST_END
};
