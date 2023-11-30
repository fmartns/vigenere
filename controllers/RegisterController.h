#include "RegisterController.h"

void RegisterController::postRegister(const drogon::HttpRequestPtr &req, 
                                      std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    auto username = req->getParameter("username");
    auto password = req->getParameter("password");
    // Implemente a lógica para registrar o usuário, por exemplo, inserindo no banco de dados
    auto response = drogon::HttpResponse::newHttpResponse();
    response->setBody("Registro concluído!");
    callback(response);
}
