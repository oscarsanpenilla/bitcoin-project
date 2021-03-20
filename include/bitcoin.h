#ifndef BITCOIN_H
#define BITCOIN_H

#include "curlhandle.h"

class Bitcoin
{
public:
    Bitcoin();
    void fetchBitcoinData();

private:
    CurlHandle m_curlHandle;
    static constexpr const char *API_URL = "https://blockchain.info/ticker";
};

#endif // BITCOIN_H
