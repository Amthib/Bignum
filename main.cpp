#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(0);

    for(; prout < 50; ++prout)
        cout << "p " << prout << endl << "pdiv2 " << (prout / 2) << endl;

    return 0;
}
