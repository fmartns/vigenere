#include "LoginController.h"
#include <unordered_map>
#include <mutex>

// Simples banco de dados em memória para armazenar usuários e senhas
static std::unordered_map<std::string, std::string> users;
static std::mutex usersMutex;

void LoginController::asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    auto username = req->getParameter("username");
    auto password = req->getParameter("password");

    {
        std::lock_guard<std::mutex> guard(usersMutex);
        if (users.find(username) != users.end() && users[username] == password) {
            auto session = req->getSession();
            session->insert("username", username);
            auto resp = drogon::HttpResponse::newRedirectionResponse("/welcome");
            callback(resp);
            return;
        }
    }

    auto resp = drogon::HttpResponse::newRedirectionResponse("/login");
    callback(resp);
}
