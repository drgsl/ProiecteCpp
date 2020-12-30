#include <iostream>
#include <cstring>
using namespace std;

char *p;
char S[255];

int main()
{
    cin.getline(S, 255);

    p = strtok(S, " ");
    while(p){

        cout << p << " ";

        p = strtok(NULL, " ");
    }

    char c = '5';
    int a = c - '0';

    char c2 = '4';
    int a2 = (int)c2;
    cout<<c2;

    char punct = '.';
    if(strcmp(punct, "."))

        if ( punct == '.')

    return 0;
}
