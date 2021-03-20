#include <iostream>
#include <memory>
#include <functional>
#include <array>
#include <cstdio>

#include "curl/curl.h"

using namespace std;

typedef unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;
class CurlHandle
{
private:
    CURL_ptr curlPtr;
    constexpr static auto deleter = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };

public:
    CurlHandle() : curlPtr(curl_easy_init(), deleter)
    {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    void setUrl(string url)
    {
        curl_easy_setopt(curlPtr.get(), CURLOPT_URL, url.c_str());
    }

    CURLcode fetch()
    {
        return curl_easy_perform(curlPtr.get());
    }
};

int main(int argc, char const *argv[])
{
    cout << "Bitcoin Project" << '\n';
    CurlHandle curlHandle;
    /* code */
    return 0;
}
