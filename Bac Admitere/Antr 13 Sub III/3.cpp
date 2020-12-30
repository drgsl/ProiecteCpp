#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    int prev2 = 1;
    int prev = 2;
    int pres = (3*prev) - (2*prev2);
    int poz = 3;

    while(pres<x)
    {
        prev2 = prev;
        prev = pres;
        pres = (3*prev) - (2*prev2);
        poz++;
    }

    while(poz)
    {
        cout<<pres<<" ";
        pres /=2;
        poz--;
    }
}
