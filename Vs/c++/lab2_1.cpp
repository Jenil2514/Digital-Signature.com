// 1. Write a program that has two classes Binary and Octal. Both the class
// have a private variable of type int in decimal format. They have member
// functions to convert a decimal number to binary and convert a decimal
// number to octal respectively. Write a friend function friendly to both
// classes which takes one number from each of the class and adds them.
// Then use the member functions to output the binary and octal form of the
// resultant outputs. You can use any other member attributes or member
// functions if you require. Name your sourcefile as Lab2_21_yourrollno.cpp

#include <iostream>
using namespace std;

class binary;
class Octal
{
private:
    int num2;

public:
    Octal(int dec) : num2(dec) {}
    void cvtOc()
    {

        int rem;
        int oct[255];
        int i = 0;
        while (num2 != 0)
        {
            if (num2 % 8 == 1)
            {
                oct[i] = 1;
                i++;
                break;
            }
            else
            {
                rem = num2 % 8;
                num2 = num2 / 8;
                oct[i] = rem;
            }

            i++;
        }
        oct[i] = '\0';
        for (int j = i - 1; j >= 0; j--)
        {
            cout << "Octal : " << oct[j];
        }
    }
    friend int sum(const Octal &, const binary &);
};

class binary
{
private:
    int num1;

public:
    binary(int dec) : num1(dec) {}
    friend int sum(const Octal &, const binary &);

    void cvtBi()
    {
        int rem, i = 0, bin[255];
        while (num1 != 0)
        {
            if (num1 == 1)
            {
                bin[i] = 1;
                i++;
                break;
            }
            else
            {
                rem = num1 % 2;
                num1 = num1 / 2;
                bin[i] = rem;
            }
            i++;
        }
        bin[i] = '\0';
        cout << endl;
        for (int j = i - 1; j >= 0; j--)
        {
            cout << "Binary : " << bin[j];
        }
    }
};
int sum(const Octal &o1, const binary &b1)
{
    return o1.num2 + b1.num1;
}
int main()
{
    Octal o(14);
    binary b(14);
    

    return 0;
}