#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>

using namespace drogon;
using namespace drogon::orm;

void loginUser(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto username = req->getParameter("user");
    auto password = req->getParameter("password");

    auto client = app().getDbClient();
    client->execSqlAsync("SELECT * FROM users WHERE user = ? AND password = ?", 
                         username, password, 
                         [callback](const Result &r){
                             if (!r.empty()) {
                                 callback(HttpResponse::newRedirectionResponse("/home")); // Substituir '/home' pela sua página inicial
                             } else {
                                 callback(HttpResponse::newRedirectionResponse("/login"));
                             }
                         }, 
                         [callback](const DrogonDbException &e){
                             callback(HttpResponse::newHttpResponse(HttpStatusCode::k500InternalServerError, ContentType::CT_TEXT_PLAIN));
                         });
}

int main()
{
    app().addListener("0.0.0.0", 80)
        .registerHandler("/login", loginUser, {Post})
        .run();
    return 0;
}

