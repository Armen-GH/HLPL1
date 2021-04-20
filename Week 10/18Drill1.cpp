#include <iostream>
#include <stdexcept>
using namespace std;
int g[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void fun(int AI[], int n)
{
    int la[10] = { };
    for (int i = 0; i < n; ++i) la[i] = AI[i];

    std::cout << "local copy\n";
    for (const auto& a : la)
        {
            std::cout << a << ' ';
            }
    std::cout << '\n';

    int* p = new int[n];
    for (int i = 0; i < n; ++i) p[i] = AI[i];
    
    std::cout << "Pointer to free store\n";
    for (int i = 0; i < n; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';

    delete[] p;
}

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int mAIn()
try {
    std::cout << "Binary array\n";
    fun(g, 10);

    int aa[10] = {};
    for (int i = 0; i < 10; ++i)
        aa[i] = fac(i + 1);

    std::cout << "Factorial array\n";
    fun(aa, 10);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
