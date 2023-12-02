#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>

using namespace drogon;
using namespace drogon::orm;

void registerUser(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto username = req->getParameter("user");
    auto password = req->getParameter("password");

    auto client = app().getDbClient();
    client->execSqlAsync("INSERT INTO users (user, password) VALUES (?, ?)", 
                         username, password, 
                         [callback](const Result &r){ 
                             callback(HttpResponse::newRedirectionResponse("/login"));
                         }, 
                         [callback](const DrogonDbException &e){ 
                             callback(HttpResponse::newHttpResponse(HttpStatusCode::k500InternalServerError, ContentType::CT_TEXT_PLAIN));
                         });
}

int main()
{
    app().addListener("0.0.0.0", 80)
        .registerHandler("/register", registerUser, {Post})
        .run();
    return 0;
}

