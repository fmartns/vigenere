#include <drogon/HttpController.h>
using namespace drogon;

class LoginController: public HttpController<LoginController> {
public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD para adicionar seus métodos de requisição
    METHOD_ADD(LoginController::postLogin,"/login", Post);
    METHOD_LIST_END

    // Método para lidar com a requisição POST de login
    void postLogin(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
        auto username = req->getParameter("username");
        auto password = req->getParameter("password");
        // Aqui você adiciona o código para verificar o usuário no banco de dados
        auto resp=HttpResponse::newHttpResponse();
        resp->setBody("Login bem-sucedido!");
        callback(resp);
    }
};
