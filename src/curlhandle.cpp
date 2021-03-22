#include "curlhandle.h"

CurlHandle::CurlHandle() : curlPtr(curl_easy_init(), deleter)
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl_easy_setopt(curlPtr.get(), CURLOPT_WRITEFUNCTION, dataHandler);
    curl_easy_setopt(curlPtr.get(), CURLOPT_WRITEDATA, &m_fetchData);
}

void CurlHandle::setUrl(std::string url)
{
    curl_easy_setopt(curlPtr.get(), CURLOPT_URL, url.c_str());
}

std::string CurlHandle::getFetchData()
{
    return m_fetchData;
}

CURLcode CurlHandle::fetch()
{
    return curl_easy_perform(curlPtr.get());
}

extern "C" std::size_t CurlHandle::dataHandler(const char* buffer, std::size_t size,
                                               std::size_t nmemb, std::string* userData)
{
    if (!userData){
        std::cout << "UserData nullptr";
        return 0;
    }

    userData->append(buffer, size*nmemb);
//    std::cout << "userData " << *userData << "\n";
    return size * nmemb;
}


