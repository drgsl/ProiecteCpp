#include <iostream>

using namespace std;

void prodprim( int n, int &p )
{
    int d,m;
    p = 1;
    d = 2;
    while(n > 1)
    {
        if(n%d ==0)
        {
            m = 0;
            p= p* d;
            while(n%d == 0)
            {
                m++;
                n =n/ d;
            }
            d++;
        }
    }

}
    int n;
    int p = 1;

int main()
{
    cin >> n;
    prodprim(n, p);
    cout << p << endl;
    return 0;
}
