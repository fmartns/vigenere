#include "RegisterController.h"
#include <unordered_map>
#include <mutex>

extern std::unordered_map<std::string, std::string> users;
extern std::mutex usersMutex;

void RegisterController::asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    auto username = req->getParameter("username");
    auto password = req->getParameter("password");

    {
        std::lock_guard<std::mutex> guard(usersMutex);
        if (users.find(username) == users.end()) {
            users[username] = password;
            auto resp = drogon::HttpResponse::newRedirectionResponse("/login");
            callback(resp);
            return;
        }
    }

    auto resp = drogon::HttpResponse::newRedirectionResponse("/register");
    callback(resp);
}
