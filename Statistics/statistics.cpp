//--------------------------------------------------                                                
//  This program generates and prints 100 random    
//  integers between user-specified limits. 
//  minIntInRange <= random integer <= maxIntInRange 
//  The random integers are printed to the console
//  10 random integers are printed per line
//  After printing a blank line the program prints
//  The mean of the random integers
//  The variance of the random integers
//--------------------------------------------------
//  Author:  Sunny Chowdhury    
//--------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define SIZEOFARRAY 100

int main() {
	int numGenerated[SIZEOFARRAY];
	unsigned int seed;
	int minIntInRange;
	int maxIntInRange;
	int index;
	double total;
	double mean;
	double variance;
	double totalVariance;
	double stdDev;

	total = 0.0;
	variance = 0.0;
	totalVariance = 0.0;
	stdDev = 0.0;

	for (int i = 0; i < SIZEOFARRAY; i++) {
		numGenerated[i] = 0;
		//cout << numGenerated[i] << endl;
	}

	cout << "Enter a positive integer seed for random number generation :";
	cin >> seed;

	//initialize the random number generator
	srand(seed);

	cout << "Enter the smallest and largest integer" << endl;
	cout << "defining the range of the random numbers" << endl;
	cout << "smallest <= random number <= largest" << endl;
	cout << "smallest integer :";
	cin >> minIntInRange;
	cout << "largest integer :";
	cin >> maxIntInRange;


	if (minIntInRange > maxIntInRange) {
		cerr << "The minimum integer in the range must be <=";
		cerr << " the maximum integer in the range" << endl;
		system("pause");
		return 1;
	}

	// Generate the SIZE_OF_ARRAY random integer
	// scale desired integer into the range
	for (index = 0; index < SIZEOFARRAY; index++) {
		numGenerated[index] = rand();
		numGenerated[index] %= (maxIntInRange - minIntInRange + 1);
		numGenerated[index] += minIntInRange;
	}

	cout << "The random numbers are: " << endl;
	for (index = 0; index < SIZEOFARRAY; index++) {
		cout << setw(5) << numGenerated[index];
		if (index % 10 == 9) cout << endl;
	}

	cout << endl << endl;
	for (index = 0; index < SIZEOFARRAY; index++) {
		total += numGenerated[index];

	}
	mean = total / SIZEOFARRAY;
	cout << "The mean of the random numbers is " << fixed << setprecision(2) << mean << endl;


	for (index = 0; index < SIZEOFARRAY; index++) {
		totalVariance += pow((numGenerated[index] - mean), 2.0);
	}
	variance = totalVariance / (SIZEOFARRAY - 1);
	cout << "The variance of the random numbers is " << fixed << setprecision(4) << variance << endl;

	stdDev = sqrt(variance);
	cout << "The standard deviation of the random numbers is " << fixed << setprecision(5) << stdDev << endl;

	system("pause");
	return 0;
}





