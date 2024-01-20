// program stworzony na bazie kodu z moodlea
#include <iostream>
#include <algorithm>

#include "wys.h"

namespace {
    int _n, _k, _g, _x;
    int ileGier, ileZapytan, maxZapytan, klamliwosc, seed;
    bool wyswietlKazdaGre;
    int klamstwa = 0;
}

void dajParametry(int &n, int &k, int &g) {
    std::cin >> _n >> _k >> _g >> klamliwosc >> wyswietlKazdaGre >> seed;
    n = _n;
    k = _k;
    g = _g;

    srand(seed);
    _x = rand() % n + 1;

    ileGier = ileZapytan;
    std::cout << "n = " << _n << ", k = " << _k << ", klamliwosc = " << klamliwosc << "%, seed = " << seed << "\n";
}

bool mniejszaNiz(int y) {
    ileZapytan++;
    if (klamstwa < _k && rand() % 100 < klamliwosc) {
        klamstwa++;
        return !(_x < y);
    } else return _x < y;
}

void odpowiedz(int x)
{
    klamstwa = 0;
    if (x != _x) {
        std::cout << "ZLE. Bledna odpowiedz w grze #" << ileGier << ": oczekiwano " << _x << " a uzyskano odpowiedz " << x << "\n\n";
        exit(1);
    }

    maxZapytan = std::max(maxZapytan, ileZapytan);

    if (wyswietlKazdaGre) std::cout << ileZapytan << " ";

    ++ileGier;

    if (ileGier == _g) {
        if (wyswietlKazdaGre) std::cout << "\n";
        std::cout << "OK. Zadano maksymalnie " << maxZapytan << " zapytan.\n\n";
        exit(0);
    }

    _x = rand() % _n + 1;
    ileZapytan = 0;
}
