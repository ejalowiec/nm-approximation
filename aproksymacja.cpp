// https://github.com/ejalowiec/nm-approximation
#include <iostream>
#include <fstream>
#include <mkl_lapack.h>


using namespace std;

int main() {

	// ---------------------- reading file ----------------------

	fstream file;
	file.open("ex1.txt", ios::in);

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










	// ---------------------- displaying results ----------------------
	// 1.
	cout << "Number of given points: " << size << endl;
	// 2.
	cout << "Node:     Value:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << arr[i][j] << "        ";
			if (j == 1)
				cout << "\n";
		}
	}
}