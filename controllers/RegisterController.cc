#include <drogon/HttpController.h>
using namespace drogon;

class RegisterController: public HttpController<RegisterController> {
public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD para adicionar seus métodos de requisição
    METHOD_ADD(RegisterController::postRegister,"/register", Post);
    METHOD_LIST_END

    // Método para lidar com a requisição POST de registro
    void postRegister(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
        auto username = req->getParameter("username");
        auto password = req->getParameter("password");
        // Aqui você adiciona o código para inserir o usuário no banco de dados
        auto resp=HttpResponse::newHttpResponse();
        resp->setBody("Registro concluído!");
        callback(resp);
    }
};
