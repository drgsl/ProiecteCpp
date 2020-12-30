#include <iostream>
#include <cstring>
using namespace std;

char s[500];

char *p;
char aux[21];

int main()
{

    int n;
    cin >> n;
    for(int i = 0; i<=n; i++)
    {
        cin.getline(aux, 20);
        strcat(s, " ");
        strcat(s, aux);
    }
    //cout<<s;


    p = strtok(s, " ");

    while(p)
    {
        int ok = 1;
        for(int i = 0; i<=strlen(aux); i++)
            if(strcmp(p[i], aux[i]) !=0)
            {
                ok = 0;
            }
        if(ok == 1)
            cout<<p<<endl;


        p = strtok(NULL, " ");
    }
}
