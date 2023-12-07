#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;
using namespace std;

class Login : public drogon::HttpSimpleController<Login> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/GetLogin", Post);
    PATH_LIST_END
};
