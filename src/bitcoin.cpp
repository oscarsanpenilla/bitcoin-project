#include "bitcoin.h"

Bitcoin::Bitcoin() : m_curlHandle()
{
    m_curlHandle.setUrl(API_URL);
}

void Bitcoin::fetchBitcoinData()
{
    m_curlHandle.fetch();
}

json Bitcoin::fetchJsonBitcoinData()
{
    m_curlHandle.fetch();
    return json::parse(m_curlHandle.getFetchData());
}
