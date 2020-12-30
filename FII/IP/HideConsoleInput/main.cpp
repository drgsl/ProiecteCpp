#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
    cout<<"Enter first letter: ";
    char c = getch();
    cout<<'\n'<<"Enter 2nd letter: ";
    char d = getch();
    cout<<'\n'<<c<<" " << d;

    srand (time(NULL));
    //cout<<time(NULL);
    for(int i = 0; i<=10; i++)
        cout <<rand() %3<< " ";         //in the range 0 to 2
    return 0;
}
