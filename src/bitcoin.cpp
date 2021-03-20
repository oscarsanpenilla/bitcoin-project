#include "bitcoin.h"

Bitcoin::Bitcoin() : m_curlHandle()
{
    m_curlHandle.setUrl(API_URL);
}

void Bitcoin::fetchBitcoinData()
{
    m_curlHandle.fetch();
}