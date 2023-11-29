#include "LoginController.h"

void LoginController::asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    // Aqui você deve verificar o nome de usuário e a senha
    // Se estiverem corretos, crie uma sessão e redirecione para a página principal
    // Para simplificar, vamos assumir que qualquer usuário é válido
    auto session = req->getSession();
    session->insert("username", req->getParameter("username"));
    auto resp = drogon::HttpResponse::newRedirectionResponse("/index.html");
    callback(resp);
}
