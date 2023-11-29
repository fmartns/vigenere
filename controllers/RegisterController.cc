#include "RegisterController.h"

void RegisterController::asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    // Aqui você deve implementar a lógica para registrar um novo usuário
    // Para simplificar, vamos redirecionar diretamente para a página de login
    auto resp = drogon::HttpResponse::newRedirectionResponse("/login.html");
    callback(resp);
}
