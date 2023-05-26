#include <iostream>
#include <vector>

class Vector;

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

    // Member function to set matrix elements
    void setElement(int row, int col, double value) {
        if (row < rows && col < cols) {
            data[row][col] = value;
        }
    }

    // Friend function declaration
    friend Vector MatVecMultiply(const Matrix& mat, const Vector& vec);
};

class Vector {
private:
    int size;
    std::vector<double> data;

public:
    // Constructor
    Vector(int size) : size(size), data(size, 0.0) {}

    // Member function to set vector elements
    void setElement(int index, double value) {
        if (index < size) {
            data[index] = value;
        }
    }

    // Friend function declaration
    friend Vector MatVecMultiply(const Matrix& mat, const Vector& vec);

    // Friend function to display vector elements
    friend void displayVector(const Vector& vec);
};

// Member function of Matrix class to perform matrix vector multiplication
Vector MatVecMultiply(const Matrix& mat, const Vector& vec) {
    Vector result(mat.rows); // Create a vector to store the result

    if (mat.cols == vec.size) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                result.data[i] += mat.data[i][j] * vec.data[j];
            }
        }
    } else {
        std::cout << "Matrix and vector dimensions do not match for multiplication." << std::endl;
    }

    return result;
}

// Friend function to display vector elements
void displayVector(const Vector& vec) {
    std::cout << "Vector: [";
    for (int i = 0; i < vec.size; i++) {
        std::cout << vec.data[i];
        if (i != vec.size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Create a matrix
    Matrix mat(3, 3);
    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(0, 2, 3);
    mat.setElement(1, 0, 4);
    mat.setElement(1, 1, 5);
    mat.setElement(1, 2, 6);
    mat.setElement(2, 0, 7);
    mat.setElement(2, 1, 8);
    mat.setElement(2, 2, 9);

    // Create a vector
    Vector vec(3);
    vec.setElement(0, 2);
    vec.setElement(1, 3);
    vec.setElement(2, 4);

    // Perform matrix vector multiplication
    Vector result = MatVecMultiply(mat, vec);

    // Display the result
    displayVector(result);

    return 0;
}
