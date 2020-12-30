#include <iostream>
using namespace std;

int v[1000];
int n, aux, ok, index;

int main()
{

    cin>> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> aux;
        ok = 1;
        for(int j = 0; j< i; j++)
        {
            if(v[j] == aux)
                ok = 0;
        }
        if(ok == 1)
        {
            v[index] = aux;
            index++;
        }


    }

    for(int i = 0 ; i<index; i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}

