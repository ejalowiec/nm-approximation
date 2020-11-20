// https://github.com/ejalowiec/nm-approximation
#include <iostream>
#include <fstream>
#include <mkl_lapack.h>
#include <math.h>


using namespace std;

int main() {

	// ---------------------- reading file ----------------------

	fstream file;
	file.open("test.txt", ios::in);

	if (!file.good()) {
		cerr << "File does not exist";
		exit(0);
	}

	int size;
	file >> size;

	if (size <= 1) {
		cerr << "Number of nodes is too low";
		exit(0);
	}

	double** arr = new double*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new double[2];

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j)
			file >> arr[i][j];
	}

	file.close();

	// ---------------------- calculating h(x) for linear function ----------------------

	// create matrices to solve the equation: A*X = B

	double** matrixA = new double*[2];
	for (int i = 0; i < 2; ++i)
		matrixA[i] = new double[2];

	double** matrixB = new double*[2];
	for (int i = 0; i < 2; ++i)
		matrixB[i] = new double[1];


	// solving the linear equation (2x2) using the coefficient matrix method

	for (int i = 0; i < size; ++i) {


	}



	// ---------------------- displaying results ----------------------
	// 1.
	cout << "Number of given points: " << size << endl;
	// 2.
	cout << "Node:\t\tValue:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << arr[i][j] << "\t\t";
			if (j == 1)
				cout << "\n";
		}
	}
}