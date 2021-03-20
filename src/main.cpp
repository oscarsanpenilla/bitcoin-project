#include <iostream>
#include <memory>
#include <functional>
#include <array>
#include <cstdio>

#include "curl/curl.h"
#include "bitcoin.h"
#include "json.hpp"



using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Bitcoin Project" << '\n';
    Bitcoin bitcoin;
    bitcoin.fetchBitcoinData();

    return 0;
}
