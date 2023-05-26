// C++ program to demonstrate
// the use of rand()
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	// This program will create some sequence of
	// random numbers on every program run
	for (int i = 0; i < 8000; i++)
		cout << rand() << " ";

	return 0;
}
