#include <iostream>
#include <cstring>
using namespace std;

char S[101], voc[] = "aeiou";
int ok;
int main()
{
    cin.getline(S, 101);
    int len = strlen(S)-1;
    int poz = -1;
    for(int i = len; i>=0;i--)
    {
        if(strchr(voc, S[i]))
        {
            ok  = 1;
            poz = i;
            break;
        }
    }

    strcpy(S+poz, S+poz+1);

    if(ok == 0)
        cout<<"NU EXISTA";
    else
        cout<<S;

    return 0;
}
