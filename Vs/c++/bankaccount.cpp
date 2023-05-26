#include <bits/stdc++.h>
#include <string>
using namespace std ;

class account
{
public:

    string cus_name;
    long int acc_num;
    char acc_type;
    
};

class cur_acct : public account
{
public:
    int balance = 5000;
    void deposit_bal(int n)
    {
        balance += n;
    }
    void withdraw_bal(int k)
    {
        balance -= k;
    }
    void display_bal()
    {
        cout << "balance:" << balance << endl;
    }
    void interest(){
        cout << "Current account can not provides any interest." << endl;
        display_bal();
    }   
};

class sav_acct : public account
{
public:
int balance = 5000;
    void deposit_bal(int n)
    {
        balance += n;
    }
    void withdraw_bal(int k)
    {
        balance -= k;
    }
    void display_bal()
    {
        cout << "balance:" << balance << endl;
    }
    void interest(){
        float f = .06;
        deposit_bal(int(f*balance));
        cout << "The balance of your account with 4\% interest is :" << balance << endl;
    } 
};

int main()
{
    account A1;
    cout << "Enter name of account holder:" << endl;
    cin >> A1.cus_name;
    cout << "Enter account number:" << endl;
    cin >> A1.acc_num;
    cout << "Enter account type( s for saving & c for current):" << endl;
    cin >> A1.acc_type;

    int k;
    cur_acct C1;
    sav_acct S1;
    if (A1.acc_type == 'c')
    {    bool g;
        cout << "Do you want to do any task(Enter 1 for Yes, 0 for No)" << endl;
        cin >> g ; 
    while(g == true ){
    cout << " enter 1 for deposit the money\n enter 2 for display balance \n enter 3 for compute and deposit interest \n enter 4 for withdrawal \n enter 5 for Check for the minimum balance, impose penalty, necessary and update the balance." << endl;
    cin >> k;
    switch (k)
    {
    case 1:
        int t;
        cout << "enter amount to deposit:" << endl;
        cin >> t;
        C1.deposit_bal(t);
        C1.display_bal();
        break;
    case 2:
        C1.display_bal();
        break;
    case 3:
        C1.interest();
        break;
    case 4:
        int l;
        cout << "enter amount to withdraw" << endl;
        cin >> l;
        C1.withdraw_bal(l);
        C1.display_bal();
        break;
    case 5:
        if (C1.balance <= 1000)
        {
            cout << "Penalty Rs. 40" << endl;
            C1.withdraw_bal(40);
            C1.display_bal();
        }
        else
            cout << "No penalty" << endl;
        C1.display_bal();
    };
        cout << "Do you want to do any task(Enter 1 for Yes, 0 for No)" << endl;
        cin >> g ;
    }
    }


    if (A1.acc_type == 's')
    {    bool g;
        cout << "Do you want to do any task(Enter 1 for Yes 0 for No)" << endl;
        cin >> g ; 
    while(g == true ){
    cout << " enter 1 for deposit the money\n enter 2 for display balance \n enter 3 for compute and deposit interest \n enter 4 for withdrawal \n enter 5 for Check for the minimum balance, impose penalty, necessary and update the balance." << endl;
    cin >> k;
    switch (k)
    {
    case 1:
        int t;
        cout << "enter amount to deposit:" << endl;
        cin >> t;
        S1.deposit_bal(t);
        S1.display_bal();
        break;
    case 2:
        S1.display_bal();
        break;
    case 3:
        S1.interest();
        break;
    case 4:
        int l;
        cout << "enter amount to withdraw" << endl;
        cin >> l;
        S1.withdraw_bal(l);
        S1.display_bal();
        break;
    case 5:
        cout << "there is no panelty on minimum balance in saving account."<< endl;
        S1.display_bal();
    };
        cout << "Do you want to do any task(Enter 1 for Yes 0 for No)" << endl;
        cin >> g ;
    }
    }


    return 0;
}