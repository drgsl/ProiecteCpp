#include <iostream>

using namespace std;

int M[21][21*21];

int main()
{
    int n = 4, k = 3;

    cin>>n>>k;

    for(int j = 1; j<=n; j++)
    {
        int copiek = 3;
        M[1][j] = j;
        for(int i = 2; i<=n*k; i++)
        {
            if(copiek > 1)
            {
                M[i][j] = M[i-1][j];
                copiek--;
            }
            else if(copiek <= 1)
            {
                M[i][j] = M[i-1][j] +1;
                copiek = k;
            }
        }
    }

    for(int i = 1; i<=n*k; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout << M[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
