#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;
using namespace std;

class Vigenere : public drogon::HttpSimpleController<Vigenere> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/vigenere", Post);
    PATH_LIST_END
};
