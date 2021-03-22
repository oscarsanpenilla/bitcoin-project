#include <iostream>
#include <memory>
#include <functional>
#include <array>
#include <cstdio>

#include "curl/curl.h"
#include "bitcoin.h"
#include "json.hpp"



using namespace std;
using namespace nlohmann;

int main(int argc, char const *argv[])
{

    cout << "Bitcoin Project" << '\n';

    try {
        Bitcoin bitcoin;
        json bitcoinJsonData = bitcoin.fetchJsonBitcoinData();
        cout << "1 BTC = " << "\n";
        for (auto it = bitcoinJsonData.begin(); it != bitcoinJsonData.end(); ++it){
            printf("\t(%3s)%10d %s\n", it.key().c_str(), it.value()["last"].get<int>(),
                    it.value()["symbol"].get<std::string>().c_str());
        }
    }  catch (...) {
        cerr << "Failed to Fetch bitcoin exchange rates" << '\n';
    }
    return 0;
}
