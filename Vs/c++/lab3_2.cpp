// An educational institution wishes to maintain a database of its employ-
// ees. The database is divided into a number of classes whose hierarchical

// relationships are shown in the following figure. The figure also shows the

// minimum information required for each class. Specify all classes and de-
// fine functions to create the database and retrieve individual information

// as and when required.

#include <iostream>
using namespace std;

class staff
{
protected:
    int code;
    char name[20];

public:
    void getinfo()
    {

        cout << "Enter Code : " << endl;
        cin >> code;

        cout << "Enter Name : " << endl;
        cin >> name;
    }
};

class Teacher : public staff
{
private:
    char sub[20], publication[20];

public:
    void geteacherinfo()
    {

        cout << "Enter the Subject for Teacher : " << endl;

        cin >> sub;
        cout << "Enter Publication for Teacher : " << endl;
        cin >> publication;
    }
    void display1()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Name of Teacher : " << name << endl;
        cout << "Code : " << code << endl;
        cout << "Subject : " << sub << endl;
        cout << "Publication : " << publication << endl;
        cout << "---------------------------------------------------" << endl;
    }
};

class typist : public staff
{
protected:
    int speed;

public:
    void getspeed()
    {
        cout << "Enter speed of Typist  : " << endl;
        cin >> speed;
    }
};

class officer : public staff
{
private:
    char grade;

public:
    void getofficer()
    {

        cout << "Enter grade of officer : " << endl;
        cin >> grade;
    }
    void display2()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Name of Officer : " << name << endl;
        cout << "Code : " << code << endl;
        cout << "Grade : " << grade << endl;
        cout << "---------------------------------------------------" << endl;
    }
};

class Regular : public typist
{
public:
    void display3()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Name of Typist : " << name << endl;
        cout << "Code : " << code << endl;
        cout << "---------------------------------------------------" << endl;
    }
};

class Casual : public typist
{
private:
    int daily, wages;

public:
    void getcasual()
    {
        cout << "Enter daily payment of Typist : " << endl;
        cin >> daily;
        cout << "Enter wages for Typist : " << endl;
        cin >> wages;
    }
    void display4()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Name of Typist : " << name << endl;
        cout << "Code : " << code << endl;
        cout << "Speed : " << speed << endl;
        cout << "Daily : " << daily << endl;
        cout << "Wages : " << wages << endl;
        cout << "---------------------------------------------------" << endl;
    }
};

int main()
{
    int choice, num, type;
    while (true)
    {

        cout << "Want to enter Information or retrieve Information : " << endl
             << "1 for Enter 2 for exit :  ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter staff " << endl
                 << "1 For Teacher : " << endl
                 << "2 For typist : " << endl
                 << "3 For officer : " << endl
                 << "4 For Exit : " << endl;
            cin >> choice;

            cout << "Enter Number Of input : " << endl;
            cin >> num;

            Teacher t[num];
            officer o[num];
            Regular r[num];
            Casual c[num];

            switch (choice)
            {
            case 1:
                for (int i = 0; i < num; i++)
                {
                    t[i].getinfo();
                    t[i].geteacherinfo();
                }
                cout << endl
                     << "Entered Values : " << endl;
                for (int i = 0; i < num; i++)
                {
                    t[i].display1();
                }

                break;
            case 2:

                cout << "Enter the type of typist 1 for regular 2 for casual : " << endl;
                cin >> type;
                if (type == 1)
                {
                    for (int i = 0; i < num; i++)
                    {

                        r[i].getinfo();
                        r[i].getspeed();
                    }
                    cout << endl
                         << "Entered Values  : " << endl;
                    for (int i = 0; i < num; i++)
                    {
                        r[i].display3();
                    }
                }

                else if (type == 2)
                {
                    for (int i = 0; i < num; i++)
                    {
                        c[i].getinfo();
                        c[i].getspeed();
                        c[i].getcasual();
                    }

                    cout << endl
                         << "Entered Values : " << endl;
                    for (int i = 0; i < num; i++)
                    {
                        c[i].display4();
                    }
                }
                else
                    cout << "Invalid !!!";

                break;
            case 3:
                for (int i = 0; i < num; i++)
                {
                    o[i].getinfo();
                    o[i].getofficer();
                }
                cout << endl
                     << "Entered Values : " << endl;
                for (int i = 0; i < num; i++)
                {
                    o[i].display2();
                }
                break;
            case 4:
                return 0;

            default:
                cout << "Invalid choice !!! " << endl;
                break;
            }
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
            cout << "Invalid choice : " << endl;
    }

    return 0;
}