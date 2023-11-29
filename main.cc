#include <drogon/drogon.h>
#include "LoginController.h"
#include "RegisterController.h"

using namespace drogon;
using namespace std;

int main() {

    //Load config file
    drogon::app().loadConfigFile("../config.json");

    // Configuração dos controladores
    drogon:app().registerController(LoginController());
    drogon:app().registerController(RegisterController());

    //drogon::app().loadConfigFile("../config.yaml");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
