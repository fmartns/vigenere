#include "CheckSessionController.h"
#include <json/json.h>

using namespace std;

void CheckSessionController::asyncHandleHttpRequest(const HttpRequestPtr& req, function<void (const HttpResponsePtr &)> &&callback) {
    auto session = req->getSession();
    Json::Value ret;

    if (session->find("username")) {
        ret["loggedIn"] = true;
        ret["username"] = session->get<string>("username");
        LOG_INFO << "Usuário autenticado: " << session->get<string>("username");
    } else {
        ret["loggedIn"] = false;
        LOG_INFO << "Nenhuma sessão de usuário encontrada";
    }

    auto response = HttpResponse::newHttpJsonResponse(ret);
    callback(response);
}
