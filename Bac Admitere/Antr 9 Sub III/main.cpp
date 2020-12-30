#include <iostream>

using namespace std;

//1
void suma ( int n, int &s)
{
    int fr[10];
    for(int i = 0; i<=10; i++)
    {
        fr[i] = 0;
    }
    while(n)
    {
        int uc = n%10;
        if(uc %2 == 1 && fr[uc] ==0)
        {
            s = s+uc;
            fr[uc]++;
        }
        n = n/10;
    }
}


int main()
{
    int s;
    suma(4713835, s);
    cout<<s <<endl;
    return 0;
}
