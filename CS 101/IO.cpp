#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void input()
{
    cout << "Enter 1 to open Microsoft Excel";
    int a;
    while(1)
    {
        cin >> a;
        if(a==1)
        {
            system("start INPUT.xlsx");
            break;
        }
        else cout << "Enter a valid number";
    }
    while(1)
    {
        cout << "Enter 2 after saving and closing MS Excel, after inputting your desired matrix";
        cin >> a;
        if (a==2) break;
        else cout << "Enter a valid number"<<endl;
    }
}

int main()
{

}

