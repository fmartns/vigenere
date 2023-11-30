#include <drogon/drogon.h>
#include "LoginController.h"
#include "RegisterController.h"

using namespace drogon;
using namespace std;

int main() {

    drogon::app().loadConfigFile("../config.json");
    drogon::app().run();
    return 0;
    
}
