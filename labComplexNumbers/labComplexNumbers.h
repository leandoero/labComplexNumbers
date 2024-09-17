#pragma once
#include <iostream>
#include <string>
using namespace std;

class Complex {
	double* real;
	double* imag;
public:
	Complex(double a = 0.0, double b = 0.0);
	Complex(const Complex& other);
	Complex operator+ (const Complex& other);
	Complex operator- (const Complex& other);
	Complex operator* (const Complex& other);
	Complex operator/ (const Complex& other);
	Complex& operator=(const Complex& other);
	bool operator==(const Complex& other);
	bool operator !=(const Complex& other);
	bool operator<(const Complex& other);
	bool operator>(const Complex& other);
	bool operator >= (const Complex& other);
	bool operator <= (const Complex& other);
	double getReal();
	double getImag();
	string ToString();
	~Complex();
};
ostream& operator<<(ostream& stream, Complex& complex);
void forArithmeticOperations(int choice, Complex& result);
string forComparisonOperations(int choice);
void menu();

