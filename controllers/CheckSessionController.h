#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class CheckSessionController : public HttpSimpleController<CheckSessionController> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // Defina a rota para este controlador
    PATH_ADD("/CheckSession", Get);
    PATH_LIST_END
};
