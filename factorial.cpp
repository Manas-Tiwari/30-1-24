/**
 *
 *  Program to calculate factorial of a number.
 *
 * */


#include<bits/stdc++.h>

using namespace std;

long long  int factorial(int num) {
	if (num == 0) return 1;
	long long int result = 1;
	for(int i = 1; i <= num; i++){
		result *= i;
	}
	return result;
}

int main() {
	int num;
	cout << "Enter numbr to calculate factorial: ";
	cin >> num;
	if (num < 0) {
		cout << "Factorial of negative numbers cannot be caluculated\n";
		return 0;
	}
	cout << "Factorial of " << num << ": "  << factorial(num) << endl;
	return 0;
}
