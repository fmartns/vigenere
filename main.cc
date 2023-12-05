
#include <drogon/drogon.h>
#include "controllers/Login.h"
#include "controllers/Register.h"

using namespace drogon;

int main() {

    drogon::app().loadConfigFile("../config.json");

    app().run();
    return 0;
}
