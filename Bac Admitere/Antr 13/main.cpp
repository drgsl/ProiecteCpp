#include <iostream>

using namespace std;

void Metoda2();
int x;

void f(int n)
{
    if(n > x)
        return;
    f(n*2);
    cout << n << " ";
}

int main()
{
    cin >> x;
    f(1);
    Metoda2();
}

void Metoda2()
{
    int prev1 = 1;
    int prev2 = 2;
    int act = 0;

    while(act < x)
    {
        act = 3*prev2 - 2*prev1;
        int aux = prev2;
        prev2 = act;
        prev1 = aux;
    }

    while (act >= 1)
    {
        cout << act << " ";
        act /= 2;
    }
}
