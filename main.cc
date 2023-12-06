#include <drogon/drogon.h>
#include <controllers/Login.h>
#include <controllers/Register.h>
#include <CheckSessionController.h>

using namespace drogon;

int main() {

    drogon::app().enableSession(1200);

    drogon::app().loadConfigFile("../config.json");

    app().run();
    return 0;
}
