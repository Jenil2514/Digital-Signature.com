// Write a program that has two classes Binary and Octal. Both the class
// have a private variable of type int in decimal format. They have member
// functions to convert a decimal number to binary and convert a decimal
// number to octal respectively. Write a friend function friendly to both
// classes which takes one number from each of the class and adds them.
// Then use the member functions to output the binary and octal form of the
// resultant outputs. You can use any other member attributes or member
// functions if you require.
#include <iostream>
#include <bitset>

class Octal; // Forward declaration of Octal class

class Binary {
private:
    int decimal;

public:
    Binary(int dec) : decimal(dec) {}

    std::string toBinary() const {
        return std::bitset<32>(decimal).to_string();
    }

    friend int addDecimal(const Binary& bin, const Octal& oct); // Friend function declaration
};

class Octal {
private:
    int decimal;

public:
    Octal(int dec) : decimal(dec) {}

    std::string toOctal() const {
        std::string octal = "";
        int temp = decimal;
        while (temp != 0) {
            octal = std::to_string(temp % 8) + octal;
            temp /= 8;
        }
        return octal;
    }

    friend int addDecimal(const Binary& bin, const Octal& oct); // Friend function declaration
};

// Friend function definition
int addDecimal(const Binary& bin, const Octal& oct) {
    return bin.decimal + oct.decimal;
}

int main() {
    Binary bin(14);
    Octal oct(14);

    int sum = addDecimal(bin, oct);

    std::cout << "Binary: " << bin.toBinary() << std::endl;
    std::cout << "Octal: " << oct.toOctal() << std::endl;
    std::cout << "Sum in Decimal: " << sum << std::endl;

    return 0;
}
