#include <iostream>

using namespace std;

void putere(int n, int d, int p)
{

    int maxD;
    int maxP;


    for(int i = 2; i<=n; i++)
    {
        if(n%i == 0)
        {
            int ok = 1;
            for( int d = 2; d<=i; d++)
            {
                if(i%d == 0)
                {
                    break;
                    ok = 0;
                }
            }
            if(ok == 1)
            {
                int copie = n;
                while (copie!=0)
                {
                    p++;
                    if(copie % i !=0)
                        break;
                }
            }

        }

    }

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
