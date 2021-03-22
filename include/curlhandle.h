#ifndef CURLHANDLE_H
#define CURLHANDLE_H

#include <memory>
#include <functional>
#include "curl/curl.h"
#include <iostream>

typedef std::unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;

class CurlHandle
{

public:
    CurlHandle();

    void setUrl(std::string url);
    std::string getFetchData();
    CURLcode fetch();


private:
    std::string m_fetchData;
    CURL_ptr curlPtr;
    constexpr static auto deleter = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };
    static size_t dataHandler(const char* buffer, std::size_t size,
                              std::size_t nmemb, std::string* userData);
};

#endif //CURLHANDLE_H
