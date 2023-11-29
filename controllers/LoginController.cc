#include "LoginController.h"
#include <drogon/HttpController.h>
#include <vector>
#include <utility>

using namespace std;
using namespace drogon;

class LoginController : public HttpController<LoginController> {
public:
    METHOD_LIST_BEGIN
    // Método para lidar com a requisição POST de login
    METHOD_ADD(LoginController::postLogin, "/login", Post);
    METHOD_LIST_END

    // Referência para a lista de usuários do RegisterController
    extern vector<pair<string, string>> usuarios;

    // Função para validar o login
    void postLogin(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
        auto nome = req->getParameter("nome");
        auto senha = req->getParameter("senha");

        // Verifica se o usuário existe na lista
        for (const auto& usuario : usuarios) {
            if (usuario.first == nome && usuario.second == senha) {
                // Usuário autenticado com sucesso
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(k200OK);
                resp->setBody("Login bem-sucedido!");
                callback(resp);
                return;
            }
        }

        // Falha na autenticação
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k401Unauthorized);
        resp->setBody("Falha no login!");
        callback(resp);
    }
};

// Definição da lista de usuários
vector<pair<string, string>> usuarios;

void LoginController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
}

