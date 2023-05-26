// Write a program that has two classes Matrix and Vector. Write a func-
// tion MatVecMultiply() which is a member function of class Matrix and a

// friend function of class Vector. The function should perform matrix vector
// multiplication and return the resultant vector as output. You can fix the
// dimensions of the matrix and vector or dynamically create that is upto
// you. You can have other member functions or attricbutes for the classes
// if required. Name your sourcefile as Lab2_22_yourrollno.cpp

#include <iostream>
using namespace std;
class vector;// Forward declaration 
class matrix
{
    int mat[3][3];// Matrix of 3*3

public:
    matrix()   // Getting values of Matrix by constructor 
    {
        cout << "enter matrix : ";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "index " << i << j << " : ";
                cin >> mat[i][j];
            }
        }
    }
    void MatVecMultiply(vector &);// Function for Multiplaction of Matrix and Vector
};
class vector
{
    int x, y, z;

public:
    void getvec()// Function to Get values of vector
    {
        cout << "enter vector :";
        cin >> x >> y >> z;
        cout << "Vector : (" << x << ", " << y << ", " << z << ")";
    }
    friend void matrix::MatVecMultiply(vector &v);// Friend of member function of class Matrix
};
void matrix::MatVecMultiply(vector &v) 
{
    int mul[3];
    for (int i = 0; i < 3; i++)    // Multiplication of Matrix and Vector 
    {

        mul[i] = (mat[i][0] * v.x) + (mat[i][1] * v.y) + (mat[i][2] * v.z);
    }
    cout << endl;
    // Output of multiplication
    cout << "Multiplaction is : (" << mul[0] << ", " << mul[1] << ", " << mul[2] << ")";
}
int main()
{
    matrix m;
    vector v;
    v.getvec();
    m.MatVecMultiply(v);
    return 0;
}
