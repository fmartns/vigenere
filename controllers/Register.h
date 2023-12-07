#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;
using namespace std;

class Register : public drogon::HttpSimpleController<Register> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/GetRegister", Post);
    PATH_LIST_END
};
