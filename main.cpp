#include "Bignum.h"

using namespace std;

int main()
{
    Bignum nb(2, true); // = -2  true c'est le signe

	for(;;)
	{
		cout << nb << endl;
		nb *= nb;
	}

    return 0;
}
