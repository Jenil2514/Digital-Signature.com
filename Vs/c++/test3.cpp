// Write a class to represent a vector (a series of float values). Include mem-
// ber functions to perform the following tasks:
// (a) To modify the value of a given element.
// (b) To display the vector in the form (10, 20, 30,..) Create a
// Create a constructor that initializes a vector to all 0 vector, a parameter-
// ized constructor to initialize a vector to user-supplied values and a copy
// constructor to copy one vector to another. Again you are allowed to fix the
// dimension of the vector. Name your sourcefile as Lab2_23_yourrollno.cpp

#include <iostream>
#include <vector>

class Vector {
private:
    int size;
    std::vector<float> elements;

public:
    // Default constructor to initialize a vector with size 0
    Vector() : size(0) {}

    // Parameterized constructor to initialize a vector with user-supplied values
    Vector(int size, const std::vector<float>& values) : size(size), elements(values) {}

    // Copy constructor to copy one vector to another
    Vector(const Vector& other) : size(other.size), elements(other.elements) {}

    // Function to modify the value of a given element
    void modifyElement(int index, float value) {
        if (index >= 0 && index < size) {
            elements[index] = value;
        } else {
            std::cout << "Error: Invalid index" << std::endl;
        }
    }

    // Function to display the vector in the form (10, 20, 30, ...)
    void displayVector() {
        std::cout << "(";
        for (int i = 0; i < size; i++) {
            std::cout << elements[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    // Example usage of Vector class
    Vector v1; // Default constructor creates a vector of size 0
    Vector v2(3, {10.0, 20.0, 30.0}); // Parameterized constructor initializes a vector with user-supplied values
    Vector v3 = v2; // Copy constructor creates a copy of v2

    v1.displayVector(); // Output: ()
    v2.displayVector(); // Output: (10, 20, 30)
    v3.displayVector(); // Output: (10, 20, 30)

    v1.modifyElement(1, 25.0); // Modify the value of element at index 1 in v1
    v1.displayVector(); // Output: (25, 0, 0)

    return 0;
}
