#include "Bignum.h"

using namespace std;

int main()
{
    unsigned long long int i(0);
    Bignum prout(10000000000000);

    //for(;;++i)
    //{
        cout << prout;
        prout *= 200000000000000;
        cout << prout;
    //}

    return 0;
}
