#include <iostream>
using namespace std;

int baza(int n)
{
    int cifmax = 0;
    while(n)
    {
        int uc = n%10;
        if(uc > cifmax)
            cifmax = uc;
        n/=10;
    }
    return cifmax + 1;
}

int main()
{
    cout << baza(50731);
}
