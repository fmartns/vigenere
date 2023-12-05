#include "Register.h"
#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>
#include <json/json.h>

void Register::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    // Lida com requisições POST para registro de usuário
    if (req->getMethod() == drogon::HttpMethod::Post) {
        auto username = req->getParameter("username");
        auto password = req->getParameter("password");

        // Aqui você pode adicionar validação para os dados de entrada

        auto client = app().getDbClient();
        client->execSqlAsync(
            "INSERT INTO users (username, password) VALUES ($1, $2)",
            [callback](const drogon::orm::Result &r) {
                Json::Value ret;
                ret["message"] = "Usuário registrado com sucesso";
                auto response = HttpResponse::newHttpJsonResponse(ret);
                callback(response);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                Json::Value ret;
                ret["message"] = std::string("Erro no banco de dados: ") + e.base().what();
                auto response = HttpResponse::newHttpJsonResponse(ret);
                response->setStatusCode(k500InternalServerError);
                callback(response);
            },
            username, password
        );
        return;
    }

    // Se o método HTTP não for POST
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setStatusCode(k405MethodNotAllowed);
    callback(resp);
}
