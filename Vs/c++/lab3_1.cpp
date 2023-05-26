#include <iostream>
using namespace std;

class Account
{
public:
    long int Acc_no;
    int type;
    char name[20];
};
class cur_acct : public Account
{
private:
    int balance = 0;

public:
    int penalty = 0, min = 5000;

    void deposit(int add)
    {
        balance += add;
    }
    void withdrawl(int withdraw)
    {
        balance -= withdraw;
        if (balance < 5000)
        {
            cout << "Please deposit Money to your Account!! Balance less then 5000 Fine : 500/-" << endl;
            penalty += 500;
            balance -= penalty;

            cout << "balance : " << balance << endl;
        }
    };
    void display()
    {

        cout << "Your Current Balance :" << balance << endl;
    }
};
class sav_acct : public Account
{
private:
    int balance = 0;
    float rate = 6.7, in;

public:
    void deposit(int add)
    {
        balance += add;
    }
    void withdrawl(int withdraw)
    {
        balance -= withdraw;
    }
    void interest(int year)
    {
        in = (balance * rate * year) / 100;
        cout << "Your Interest with current balance = " << in << endl;
    }
    void display()
    {
        cout << "Your Current Balance :" << balance << endl;
    }
};
int main()
{
    int type;
    cur_acct ca;
    sav_acct sa;
    cout << "----------------------------------------------------" << endl;
    cout << "Enter 1 for Saving account And 2 For current Account : " << endl;
    cin >> type;
    if (type == 1)
    {
        while (true)
        {
            cout << endl;
            cout << endl
                 << "press 1 for deposit Money : " << endl;
            cout << "Press 2 for withdrawl : " << endl;
            cout << "Press 3 to show balance :  " << endl;
            cout << "Press 4 to see interest : " << endl;
            cout << "Press 5 To exit : " << endl;

            int choice;
            cout << "Enter choice : " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                int add;
                cout << "Enter amount : ";
                cin >> add;
                sa.deposit(add);
                sa.display();
                break;
            case 2:
                int withdraw;
                cout << "Enter amount : ";
                cin >> withdraw;
                sa.withdrawl(withdraw);
                sa.display();
                break;
            case 3:
                sa.display();
                break;
            case 4:
                int year;
                cout << "enter number of year : ";
                cin >> year;
                sa.interest(year);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid Choice : ";
            }
        }
    }
    else
    {
        while (true)
        {
            cout << endl;
            cout << "press 1 for deposit Money : " << endl;
            cout << "Press 2 for withdrawl : " << endl;
            cout << "Press 3 to show balance :  " << endl;
            cout << "Press 4 to see penalty : " << endl;
            cout << "Press 5 to show Minimum balance :  " << endl;
            cout << "Press 6 to exit : " << endl;
            int choice;
            cout << "Enter choice : " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                int add;
                cout << "Enter amount : ";
                cin >> add;
                ca.deposit(add);
                ca.display();
                break;
            case 2:
                int withdraw;
                cout << "Enter amount : ";
                cin >> withdraw;
                ca.withdrawl(withdraw);
                ca.display();
                break;
            case 3:
                ca.display();
                break;
            case 4:
                cout << "Your total penalty : " << ca.penalty << endl;
                break;
            case 5:
                cout << "Minimum Balance : " << ca.min << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Choice : " << endl;
            }
        }
    }

    return 0;
}