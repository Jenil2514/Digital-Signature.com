// Write a class to represent a vector (a series of float values). Include mem-
// ber functions to perform the following tasks:

// (a) To modify the value of a given element.
// (b) To display the vector in the form (10, 20, 30,..) Create a

// Create a constructor that initializes a vector to all 0 vector, a parameter-
// ized constructor to initialize a vector to user-supplied values and a copy

// constructor to copy one vector to another. Again you are allowed to fix the
// dimension of the vector. Name your sourcefile as Lab2_23_yourrollno.cpp
#include <iostream>
using namespace std;
class Vector
{
private:
    float *Vec; // Dynamic array 
    int size;   // Size of the vector

public:
    // Constructor to initialize vector with all 0 values
    Vector(int size)
    {
        this->size = size;
        Vec = new float[size];
        for (int i = 0; i < size; i++)
        {
            Vec[i] = 0.0f;
        }
    }

    // Parameterized constructor to initialize vector with user-supplied values
    Vector(int size, float *values)
    {
        this->size = size;
        Vec = new float[size];
        for (int i = 0; i < size; i++)
        {
            Vec[i] = values[i];
        }
    }

    // Copy constructor to copy one vector to another
    Vector(const Vector &other)
    {
        size = other.size;
        Vec = new float[size];
        for (int i = 0; i < size; i++)
        {
            Vec[i] = other.Vec[i];
        }
    }

    // Member function to modify the value of a given element
    void setValue(int index, float value)
    {
        if (index >= 0 && index < size)
        {
            Vec[index] = value;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }

    // Member function to display the vector
    void display()
    {
        cout << "(";
        for (int i = 0; i < size; i++)
        {
            cout << Vec[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
};
int main()
{
    //  vector with all 0 values
    Vector v1(5);

    // vector with user-supplied values
    float values[] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    Vector v2(5, values);

    // Copy v2 to v3
    Vector v3 = v2;

    // Modify values of v1
    v1.setValue(0, 1.0f);
    v1.setValue(2, 3.0f);

    // Display vectors
    cout << "v1: ";
    v1.display();
    cout << "v2: ";
    v2.display();
    cout << "v3: ";
    v3.display();

    return 0;
}
