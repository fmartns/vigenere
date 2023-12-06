#include "Login.h"
#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>
#include <json/json.h>

void Login::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    if (req->getMethod() == drogon::HttpMethod::Post) {
        auto username = req->getParameter("username");
        auto password = req->getParameter("password");

        // Aqui você pode adicionar validação para os dados de entrada

        auto client = app().getDbClient();
        client->execSqlAsync(
            "SELECT * FROM users WHERE username = $1 AND password = $2",
            [req, callback](const drogon::orm::Result &r) {
                Json::Value ret;
                if (r.size() > 0) {
                    // Usuário encontrado e senha correta
                    ret["message"] = "Login bem-sucedido";
                    ret["success"] = true;

                    // Criar uma sessão para o usuário
                    auto session = req->getSession();
                    session->insert("username", r[0]["username"].as<std::string>());
                    // Você pode adicionar mais dados à sessão conforme necessário

                    LOG_INFO << "Sessão criada para o usuário: " << r[0]["username"].as<std::string>();
                    
                } else {
                    // Usuário não encontrado ou senha incorreta
                    ret["message"] = "Usuário ou senha incorretos";
                    ret["success"] = false;
                }
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
