#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;
using namespace std;

class CheckSessionController : public HttpSimpleController<CheckSessionController> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/CheckSession", Get);
    PATH_LIST_END
};
