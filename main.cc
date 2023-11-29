#include <drogon/drogon.h>
#include "LoginController.h"
#include "RegisterController.h"

using namespace drogon;
using namespace std;

int main() {

    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 80);

    //Load config file
    drogon::app().loadConfigFile("../config.json");

    drogon:app().registerController(LoginController());
    drogon:app().registerController(RegisterController());

        // Rota para servir a página de login
    drogon::app().registerHandler("/login",
        [](const drogon::HttpRequestPtr& req,
           std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("<html>...conteúdo de login.html...</html>");
            callback(resp);
        },
        {drogon::Get}); // Método GET

    // Rota para servir a página de registro
    drogon::app().registerHandler("/registro",
        [](const drogon::HttpRequestPtr& req,
           std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("<html>...conteúdo de registro.html...</html>");
            callback(resp);
        },
        {drogon::Get}); // Método GET

    //drogon::app().loadConfigFile("../config.yaml");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
