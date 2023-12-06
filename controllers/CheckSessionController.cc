#include "CheckSessionController.h"
#include <json/json.h>

void CheckSessionController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    auto session = req->getSession();
    Json::Value ret;

    // Verifique se a sessão tem um nome de usuário
    if (session->find("username")) {
        // Usuário está logado
        ret["loggedIn"] = true;
        ret["username"] = session->get<std::string>("username");
        LOG_INFO << "Usuário autenticado: " << session->get<std::string>("username");
    } else {
        // Usuário não está logado
        ret["loggedIn"] = false;
        LOG_INFO << "Nenhuma sessão de usuário encontrada";
    }

    auto response = HttpResponse::newHttpJsonResponse(ret);
    callback(response);
}
