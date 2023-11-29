#include <drogon/HttpController.h>
#include <vector>
#include <utility>

using namespace std;
using namespace drogon;

class RegisterController : public HttpController<RegisterController> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(RegisterController::postRegister, "/registro", Post);
    METHOD_LIST_END

    static vector<pair<string, string>> usuarios;

    void postRegister(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
        auto nome = req->getParameter("nome");
        auto senha = req->getParameter("senha");

        // Verifica se o nome de usuário já existe
        for (const auto& usuario : usuarios) {
            if (usuario.first == nome) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(k400BadRequest);
                resp->setBody("Nome de usuário já existe!");
                callback(resp);
                return;
            }
        }

        // Adiciona o novo usuário
        usuarios.push_back(make_pair(nome, senha));

        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setBody("Usuário registrado com sucesso!");
        callback(resp);
    }
};

vector<pair<string, string>> RegisterController::usuarios;

void RegisterController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
}
