#include <iostream>
using namespace std;

class staff

{
public:
    int code;
    char name[20];

    void getinfo()
    {

        cout << "Enter Code for  : " << endl;
        cin >> code;

        cout << "Enter Name for  : " << endl;
        cin >> name;
    }
};
class erf : public staff
{
    public:
    void display()
    {
        cout << "code" << code;
        cout << "name" << name;
    }
};

int main()
{

    erf e[2];
    for (int i = 0; i < 2; i++)
    {
        e[i].getinfo();
    }
    for (int i = 0; i < 2; i++)
    {
        e[i].display();
    }

    return 0;
}