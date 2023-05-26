// The following is the problem statement: There is a class called Person. It has
// the following public attributes: id, civil score(a number between 150 and 900)
// , monthly income, yrs of service remaining. Two classes are inherited privately
// from Person namely GovEmp and PrivEmp. GovEmp has an additional 0/1
// private attribute called Disci- plinaryAct and PrivEmp has rating( a number in
// the range including 0 and 4). You have to make 2 objects of GovEmp and 2
// objects of PrivEmp and initialize each using constructors that take values from
// the user. Now define a function LoanGrant() friendly to both the classes. There
// are two types of loans: individual and joint(for two persons). The function takes
// an argument whether the user wants to check for individual or joint loans and
// then prints a summary of loans for all 4 objects. The following are the rules for
// granting loans:
// 1. Personal Loan Govt Emp:
// (a) Govt Employee must not have disciplinary action in any case.
// (b) If monthly income ≥ 25000 and yrs ≥ 15 and cibil score ≥ 200, eligible
// for loan of INR 5 lakhs.
// (c) If monthly income ≥ 50000 and yrs ≥ 20 and cibil score ≥ 300, eligible
// for loan of INR 10 lakhs
// 2. Personal Loan Priv Emp:
// (a) Priv Employee must have rating of at least 3 or more in any case.
// (b) If monthly income ≥ 35000 and yrs ≥ 15 and cibil score ≥ 250, eligible
// for loan of INR 5 lakhs.
// (c) If monthly income ≥ 70000 and yrs ≥ 20 and cibil score ≥ 350, eligible
// for loan of INR 10 lakhs.

#include <iostream>
using namespace std;

class Person
{
public:
    int id, civil_sc, income, yrs;
};
class PrivEmp;
class GoveEmp : private Person
{
private:
    int Disci_plinaryAct;

public:
    GoveEmp()

    {
        cout << "Enter Id : " << endl;
        cin >> id;
        cout << "Enter Your civil score : " << endl;
        cin >> civil_sc;
        cout << "Enter Your income : " << endl;
        cin >> income;
        cout << "Enter No of years of your remaining service : " << endl;
        cin >> yrs;
        cout << "Enter Your Disciplinary Act No : 0/1 : " << endl;
        cin >> this->Disci_plinaryAct;
        // cout << Disci_plinaryAct << endl;
    }
    friend void Loangrant(GoveEmp g1, GoveEmp g2, PrivEmp p1, PrivEmp p2);
    // void display()
    // {
    // }
};
class PrivEmp : private Person
{
private:
    int rating;

public:
    PrivEmp()
    {
        cout << "Enter Id : " << endl;
        cin >> id;
        cout << "Enter Your civil score : " << endl;
        cin >> civil_sc;
        cout << "Enter Your income : " << endl;
        cin >> income;
        cout << "Enter No of years of your remaining service : " << endl;
        cin >> yrs;
        cout << "Enter Your Rating in range 0-4 : ";
        cin >> this->rating;
        cout << rating << endl;
    }
    friend void Loangrant(GoveEmp g1, GoveEmp g2, PrivEmp p1, PrivEmp p2);
};
void Loangrant(GoveEmp g1, GoveEmp g2, PrivEmp p1, PrivEmp p2)
{
    int choice;

    cout << "Which Type Loan you Want : 1 for Individual or 2 for Joint : " << endl;
    cin >> choice;
    // 1. Personal Loan Govt Emp:
    // (a) Govt Employee must not have disciplinary action in any case.
    // (b) If monthly income ≥ 25000 and yrs ≥ 15 and cibil score ≥ 200, eligible
    // for loan of INR 5 lakhs.
    // (c) If monthly income ≥ 50000 and yrs ≥ 20 and cibil score ≥ 300, eligible
    // for loan of INR 10 lakhs

    if (choice == 1)
    {
        cout << "Goverment Employ 1 : " << endl;
        if (g1.Disci_plinaryAct == 1)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (g1.Disci_plinaryAct == 0)
        {
            if (g1.income >= 25000 && g1.yrs >= 15 && g1.civil_sc >= 200)
            {
                cout << "Eligible For Loan of 5 Lakhs ." << endl;
            }
            else if (g1.income >= 50000 && g1.yrs >= 20 && g1.civil_sc >= 300)
            {
                cout << "Eligible For Loan 10 Lakhs ." << endl;
            }
        }
        cout << "Goverment Employ 2 : " << endl;
        if (g2.Disci_plinaryAct == 1)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (g2.Disci_plinaryAct == 0)
        {
            if (g2.income >= 25000 && g2.yrs >= 15 && g2.civil_sc >= 200)
            {
                cout << "Eligible For Loan of 5 Lakhs ." << endl;
            }
            else if (g2.income >= 50000 && g2.yrs >= 20 && g2.civil_sc >= 300)
            {
                cout << "Eligible For Loan 10 Lakhs ." << endl;
            }
        }
        // 2. Personal Loan Priv Emp:
        // (a) Priv Employee must have rating of at least 3 or more in any case.
        // (b) If monthly income ≥ 35000 and yrs ≥ 15 and cibil score ≥ 250, eligible
        // for loan of INR 5 lakhs.
        // (c) If monthly income ≥ 70000 and yrs ≥ 20 and cibil score ≥ 350, eligible
        // for loan of INR 10 lakhs.
        cout << endl
             << "Private Employ 1 : " << endl;
        if (p1.rating < 3)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (p1.rating == 4)
        {
            if (p1.income >= 35000 && p1.yrs >= 15 && p1.civil_sc >= 250)
            {
                cout << "Eligible For Loan 5 Lakhs : " << endl;
            }
            else if (p1.income >= 70000 && p1.yrs >= 20 && p1.civil_sc >= 350)
            {
                cout << "Eligible For Loan 10 Lakhs : " << endl;
            }
        }
        cout << "Private Employ 2 : " << endl;
        if (p2.rating < 3)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (p2.rating == 4)
        {
            if (p2.income >= 35000 && p2.yrs >= 15 && p2.civil_sc >= 250)
            {
                cout << "Eligible For Loan 5 Lakhs : " << endl;
            }
            else if (p2.income >= 70000 && p2.yrs >= 20 && p2.civil_sc >= 350)
            {
                cout << "Eligible For Loan 10 Lakhs : " << endl;
            }
        }
    }
    else if (choice == 2)
    {
        cout << endl;
        cout << "Goverment Employ 1 & 2 : " << endl;
        if (g1.Disci_plinaryAct == 1 || g2.Disci_plinaryAct == 1)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (g1.Disci_plinaryAct == 0 && g2.Disci_plinaryAct == 0)
        {
            if (g1.income >= 25000 && g1.yrs >= 15 && g1.civil_sc >= 200 && g2.income >= 25000 && g2.yrs >= 15 && g2.civil_sc >= 200)
            {
                cout << "Eligible For Loan of 5 Lakhs ." << endl;
            }
            else if (g1.income >= 50000 && g1.yrs >= 20 && g1.civil_sc >= 300 && g2.income >= 50000 && g2.yrs >= 20 && g2.civil_sc >= 300)
            {
                cout << "Eligible For Loan 10 Lakhs ." << endl;
            }
        }
        cout << "Private Employ 1 & 2 : " << endl;
        if (p1.rating < 3 || p2.rating < 3)
        {
            cout << "Loan Can not be granted : " << endl;
        }
        else if (p1.rating == 4 && p2.rating == 4)
        {
            if (p1.income >= 35000 && p1.yrs >= 15 && p1.civil_sc >= 250 && p2.income >= 35000 && p2.yrs >= 15 && p2.civil_sc >= 250)
            {
                cout << "Eligible For Loan 5 Lakhs : " << endl;
            }
            else if (p1.income >= 70000 && p1.yrs >= 20 && p1.civil_sc >= 350 && p2.income >= 70000 && p2.yrs >= 20 && p2.civil_sc >= 350)
            {
                cout << "Eligible For Loan 10 Lakhs : " << endl;
            }
        }
    }
}

int main()
{

    cout << "Goverment Employ 1 : " << endl;
    GoveEmp g1;

    cout << endl;
    cout << "Goverment Employ 2 : " << endl;
    GoveEmp g2;
    cout << endl;
    cout << "Private Employ 1 : " << endl;
    PrivEmp p1;
    cout << endl;
    cout << "Private Employ 2 : " << endl;
    PrivEmp p2;
    cout << endl;
    Loangrant(g1, g2, p1, p2);

    return 0;
}
