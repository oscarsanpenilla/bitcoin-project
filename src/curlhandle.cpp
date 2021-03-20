#include "curlhandle.h"


CurlHandle::CurlHandle() : curlPtr(curl_easy_init(), deleter)
{
    curl_global_init(CURL_GLOBAL_ALL);
}

void CurlHandle::setUrl(std::string url)
{
    curl_easy_setopt(curlPtr.get(), CURLOPT_URL, url.c_str());
}

CURLcode CurlHandle::fetch()
{
    return curl_easy_perform(curlPtr.get());
}
