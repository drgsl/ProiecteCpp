#include <iostream>

using namespace std;

int a[10][10];

int main()
{
a[0][0] = 1;
    for(int j =1; j<5; j++)
    {
        a[0][j] = a[0][j-1]+4;
    }

    for(int j = 0; j<5; j++)
    {
        for(int i = 1; i<4; i++)
        {
            a[i][j] = a[i-1][j]+1;
        }
    }

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }

}
