#include <iostream>
using namespace std;

class Binary;// Forward declaration of class

class Octal
{
private:
    int decimal;

public:
    Octal(int d) : decimal(d)  //Initilization of private variable decimal
    {
        cout << "Num2 : " << decimal << endl;
    }
    void cvtOc(int n)// converting to Octal
    {
        int temp = n;
        int rem;
        int oct[255];
        int i = 0;
        while (n != 0)
        {
            if (n % 8 == 1)
            {
                oct[i] = 1;
                i++;
                break;
            }
            else
            {
                rem = n % 8;
                n = n / 8;
                oct[i] = rem;
            }

            i++;
        }
        oct[i] = '\0';
        //Output
        cout << endl
             << "Octal of " << temp << " : ";
        for (int j = i - 1; j >= 0; j--)
        {
            cout << oct[j];
        }
    }
    friend int Sum(Binary &, Octal &);// friend function to sum decimal from each classes
};
class Binary
{
private:
    int decimal;

public:
    Binary(int d) : decimal(d)  //Initilization of private variable decimal
    {
        cout << "Num1 : "
             << decimal;
    }
    void cvtBi(int n)// Converting To Binary
    {
        int temp = n;
        int rem, i = 0, bin[255];
        while (n != 0)
        {
            if (n == 1)
            {
                bin[i] = 1;
                i++;
                break;
            }
            else
            {
                rem = n % 2;
                n = n / 2;
                bin[i] = rem;
            }
            i++;
        }
        bin[i] = '\0';
        //Output
        cout << endl
             << "Binary of " << temp << " : ";
        for (int j = i - 1; j >= 0; j--)
        {
            cout << bin[j];
        }
    }
    friend int Sum(Binary &, Octal &);// friend function to sum decimal from each classes
};
int Sum(Binary &b1, Octal &o1)//Friend function defination
{
    return b1.decimal + o1.decimal;
}

int main()
{
    int sum;
    Binary b(14);
    cout << endl;
    Octal o(15);
    sum = Sum(b, o);
    cout << endl
         << "Sum is : "
         << sum;
    b.cvtBi(sum);
    o.cvtOc(sum);

    return 0;
}