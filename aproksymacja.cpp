// https://github.com/ejalowiec/nm-approximation
#include <iostream>
#include <fstream>
//#include <mkl_lapack.h>
//#include <math.h>


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
		matrixA[i] = new double[2]{ 0.0 };

	double** matrixB = new double*[2];
	for (int i = 0; i < 2; ++i)
		matrixB[i] = new double[1]{ 0.0 };


	// creating equations 2x2 to calculate h(xi)

	matrixA[0][0] = size;
	
	for (int i = 0; i < size; ++i) {
		matrixA[0][1] += arr[i][0];
	}

	for (int i = 0; i < size; ++i) {
		matrixA[1][1] += arr[i][0] * arr[i][0];
	}

	matrixA[1][0] = matrixA[0][1];

	for (int i = 0; i < size; ++i) {
		matrixB[0][0] += arr[i][1];
	}

	for (int i = 0; i < size; ++i) {
		matrixB[1][0] += arr[i][0]* arr[i][1];
	}

	//cout << matrixA[0][0] << endl;
	//cout << matrixA[0][1] << endl;
	//cout << matrixA[1][0] << endl;
	//cout << matrixA[1][1] << endl;
	//cout << matrixB[0][0] << endl;
	//cout << matrixB[1][0] << endl;

	// solving the linear equation (2x2) using the determinant matrix method

	double Wa = 0.0;
	double Wa0 = 0.0;
	double Wa1 = 0.0;
	double a0 = 0.0;
	double a1 = 0.0;

	Wa = (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
	//cout << "Wa: " << Wa << endl;
	Wa1 = (matrixA[0][0] * matrixB[1][0]) - (matrixB[0][0] * matrixA[1][0]);
	//cout << "Wa1: " << Wa1 << endl;
	Wa0 = (matrixB[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixB[1][0]);
	//cout << "Wa0: " << Wa0 << endl;

	a0 = Wa0 / Wa;
	//cout << "a0: " << a0 << endl;
	a1 = Wa1 / Wa;
	//cout << "a1: " << a1 << endl;

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
	// 3.
	cout << "Equation of the approximating linear function:\nh(x) = " << a1 << "x + " << a0 << endl;

	for (int i = 0; i < size; ++i) {
		delete[] arr[i];
	}

	for (int i = 0; i < 2; ++i) {
		delete[] matrixA[i];
		delete[] matrixB[i];
	}

	delete[] matrixA;
	delete[] matrixB;
}