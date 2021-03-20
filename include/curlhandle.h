#ifndef CURLHANDLE_H
#define CURLHANDLE_H

#include <memory>
#include <functional>
#include "curl/curl.h"

class CurlHandle
{
typedef std::unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;
private:
    CURL_ptr curlPtr;
    constexpr static auto deleter = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };

public:
    CurlHandle();

    void setUrl(std::string url);
    CURLcode fetch();
};

#endif //CURLHANDLE_H
