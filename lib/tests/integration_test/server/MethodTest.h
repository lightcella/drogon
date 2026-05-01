#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class MethodTest : public drogon::HttpController<MethodTest>
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(MethodTest::get, "/api/method/test", Get);
    ADD_METHOD_TO(MethodTest::post, "/api/method/test?test={}", Post);
    ADD_METHOD_TO(MethodTest::getReg, "/api/method/{}/test", Get);
    ADD_METHOD_TO(MethodTest::postReg, "/api/method/{}/test?test={}", Post);
    ADD_METHOD_VIA_REGEX(MethodTest::getReg,
                         "/api/method/regex/(.*)/test",
                         Get);
    ADD_METHOD_VIA_REGEX(MethodTest::postRegex,
                         "/api/method/regex/(.*)/test",
                         Post);
    ADD_METHOD_TO(MethodTest::handlePropfind, "/api/method/webdav", Propfind);
    ADD_METHOD_TO(MethodTest::handleMkcol, "/api/method/webdav", Mkcol);
    ADD_METHOD_TO(MethodTest::handleCopy, "/api/method/webdav", Copy);
    ADD_METHOD_TO(MethodTest::handleMove, "/api/method/webdav", Move);
    METHOD_LIST_END

    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void post(const HttpRequestPtr &req,
              std::function<void(const HttpResponsePtr &)> &&callback,
              std::string str);

    void getReg(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                std::string regStr);
    void postReg(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string regStr,
                 std::string str);
    void postRegex(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string regStr);

    void handlePropfind(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback);
    void handleMkcol(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback);
    void handleCopy(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
    void handleMove(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
};
