#include <iostream>

using namespace std;

int v[255];

int main()
{
    char c = '4';

    if(c >= 'a' && c <= 'z')
        cout<<c <<" este litera mica"<<endl;
    else
        cout << c << " nu este litera mica"<<endl;

    for(int i = 'a'; i<='z'; i++){
        cout << v[i] << " ";
    }
        return 0;
}
