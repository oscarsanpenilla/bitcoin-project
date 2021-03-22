#ifndef BITCOIN_H
#define BITCOIN_H

#include "curlhandle.h"
#include "json.hpp"


using json = nlohmann::json;

class Bitcoin
{

public:
    Bitcoin();
    void fetchBitcoinData();
    json fetchJsonBitcoinData();


private:
    CurlHandle m_curlHandle;
    static constexpr const char *API_URL = "https://blockchain.info/ticker";
};

#endif // BITCOIN_H
