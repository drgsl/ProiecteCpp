#include <iostream>

using namespace std;

int v[1001];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin>>v[i];
    }

    for(int i = 0; i<n; i ++)
    {
        if(v[i] % 2 == 0)
        {
            for(int j = i; j<n; j++)
            {
                v[j] = v[j+1];
            }
            n--;
            i--;
        }
    }

        for(int i = 0; i<n; i ++)
            cout << v[i] << ' ';
    return 0;
}
