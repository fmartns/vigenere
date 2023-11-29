#pragma once
#include <drogon/HttpSimpleController.h>

class RegisterController : public drogon::HttpSimpleController<RegisterController> {
public:
    virtual void asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/register", drogon::Post); // Use POST para segurança
    PATH_LIST_END
};
