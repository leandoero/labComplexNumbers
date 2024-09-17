#include "labComplexNumbers.h"
Complex objResultForSum, objResultForSub, objResultForMul, objResultForDiv;

Complex::Complex(double a, double b) {			//конструктор инициализации
	real = new double{ a };
	imag = new double{ b };
}

Complex::Complex(const Complex& other) {//конструктор копирования
	real = new double{ *other.real };
	imag = new double{ *other.imag };
}

Complex Complex::operator+ (const Complex& other) {
	Complex newDateForSum{ *real + *other.real, *imag + *other.imag };
	return newDateForSum;
}
Complex Complex::operator- (const Complex& other) {
	Complex newDateForSub{ *real - *other.real, *imag - *other.imag };
	return newDateForSub;
}
Complex Complex::operator* (const Complex& other) {
	Complex newDateForMul{ (*real * *other.real) - (*imag * *other.imag), (*real * *other.imag) + (*imag * *other.real) };	//(ac - bd, ad + bc);
	return newDateForMul;
}
Complex Complex::operator/ (const Complex& other) {
	Complex newDateForDiv{ (*real * *other.real + *imag * *other.imag) / (*other.real * *other.real + *other.imag * *other.imag),
		(*imag * *other.real - *real * *other.imag) / (*other.real * *other.real + *other.imag * *other.imag) };
	return newDateForDiv;
}
Complex& Complex::operator=(const Complex& other) {
	if (*this == other) {
		return	*this;
	}
	*real = *other.real;
	*imag = *other.imag;

	return *this;
}


bool Complex::operator==(const Complex& other) {
	return ((*real == *other.real) && (*imag == *other.imag));
}

bool Complex::operator !=(const Complex& other) {
	return !((*real == *other.real) && (*imag == *other.imag));
}

bool Complex::operator<(const Complex& other) {
	if (real < other.real) {
		return 1;
	}
	else if (real == other.real && imag < other.imag) {
		return 1;
	}
}
bool Complex::operator>(const Complex& other) {
	if (real > other.real) {
		return 1;
	}
	else if ((real == other.real) && (imag > other.imag)) {
		return 1;
	}
}

bool Complex::operator >= (const Complex& other) {
	return (real >= other.real) && (imag >= other.imag);
}

bool Complex::operator <= (const Complex& other) {
	return (real <= other.real) && (imag <= other.imag);
}

double Complex::getReal() {
	return *real;
}
double Complex::getImag() {
	return *imag;
}

string Complex::ToString() {
	return to_string(getReal()) + "+ i * " + to_string(getImag());
}

Complex::~Complex() {
	delete real;
	delete imag;
}

ostream& operator<<(ostream& stream, Complex& complex) {
	stream << complex.ToString();
	return stream;
}

void forArithmeticOperations(int choice, Complex& result) {
	system("cls");
	double real, imag = 0;
	cout << "Введите действительную и мнимую часть первого числа : " << endl;
	while (true) {
		cout << "Ввод : ";
		cin >> real >> imag;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	Complex objFirst(real, imag);

	double realSecond, imagSecond = 0;
	cout << "Введите действительную и мнимую часть второго числа : " << endl;
	while (true) {
		cout << "Ввод : ";
		cin >> realSecond >> imagSecond;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	Complex objSecond(realSecond, imagSecond);
	if (choice == 1) {
		Complex ResultForSum{ objFirst + objSecond };
		result = ResultForSum;
	}
	else if (choice == 2) {
		Complex ResultForSub{ objFirst - objSecond };
		result = ResultForSub;
	}
	else if (choice == 3) {
		Complex ResultForMul{ objFirst * objSecond };
		result = ResultForMul;
	}
	else if (choice == 4) {
		Complex ResultForDiv{ objFirst / objSecond };
		result = ResultForDiv;
	}
}

string forComparisonOperations(int choice) {
	system("cls");
	double real, imag = 0;
	cout << "Введите действительную и мнимую часть первого числа : " << endl;
	while (true) {
		cout << "Ввод : ";
		cin >> real >> imag;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	Complex objFirst(real, imag);

	double realSecond, imagSecond = 0;
	cout << "Введите действительную и мнимую часть второго числа : " << endl;
	while (true) {
		cout << "Ввод : ";
		cin >> realSecond >> imagSecond;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	Complex objSecond(realSecond, imagSecond);
	if (choice == 1) {
		return (objFirst == objSecond) ? "true" : "false";
	}
	else if (choice == 2) {
		return (objFirst != objSecond) ? "true" : "false";
	}
	else if (choice == 3) {
		return (objFirst < objSecond) ? "true" : "false";
	}
	else if (choice == 4) {
		return (objFirst > objSecond) ? "true" : "false";
	}
	else if (choice == 5) {
		return (objFirst >= objSecond) ? "true" : "false";
	}
	else if (choice == 6) {
		return (objFirst <= objSecond) ? "true" : "false";
	}
}

void menu() {
	system("cls");
	cout << "1. Арифметические операции\n" <<
		"2. Операции сравнения\n" <<
		"3. Информация по объекту\n" <<
		"4. Выход из программы\n" << endl;
	unsigned int choice = 0;
	while (true) {
		cout << "Ввод : ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (choice < 5) {
			break;
		}
	}
	switch (choice)
	{
	case 1: {
		system("cls");
		unsigned int choice = 0;
		cout << "1. Сложение\n" <<
			"2. Вычитание\n" <<
			"3. Умножение\n" <<
			"4. Деление\n" <<
			"5. Выход в меню\n" << endl;
		while (true) {
			cout << "Ввод : ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (choice < 6) {
				break;
			}
		}
		switch (choice)
		{
		case 1: {
			forArithmeticOperations(choice, objResultForSum);
			menu();
			break;
		}
		case 2: {
			forArithmeticOperations(choice, objResultForSub);
			menu();
			break;
		}
		case 3: {
			forArithmeticOperations(choice, objResultForMul);
			menu();
			break;
		}
		case 4: {
			forArithmeticOperations(choice, objResultForDiv);
			menu();
			break;
		}
		case 5: {
			system("cls");
			menu();
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		system("cls");
		unsigned int choice = 0;
		cout << "1. == \n" <<
			"2. != \n" <<
			"3. < \n" <<
			"4. > \n" <<
			"5. >= \n" <<
			"6. <= \n" <<
			"7. Выход в меню\n" << endl;
		while (true) {
			cout << "Ввод : ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (choice < 8) {
				break;
			}
		}
		switch (choice)
		{
		case 1: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 2: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 3: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 4: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 5: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 6: {
			cout << forComparisonOperations(choice) << endl;
			system("pause");
			menu();
			break;
		}
		case 7: {
			system("cls");
			menu();
		}
		default:
			break;
		}
		break;
	}
	case 3: {
		system("cls");
		unsigned int choice = 0;
		cout << "1. Вывести информацию по сложению\n" <<
			"2. Вывести информацию по вычитанию\n" <<
			"3. Вывести информация по умножению\n" <<
			"4. Вывести информацию по делению\n"
			"5. Выход в меню\n" << endl;
		while (true) {
			cout << "Ввод : ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (choice < 6) {
				break;
			}
		}
		switch (choice)
		{
		case 1: {
			system("cls");
			cout << objResultForSum << endl;
			system("pause");
			menu();
			break;
		}
		case 2: {
			system("cls");
			cout << objResultForSub << endl;
			system("pause");
			menu();
			break;
		}
		case 3: {
			system("cls");
			cout << objResultForMul << endl;
			system("pause");
			menu();
			break;
		}
		case 4: {
			system("cls");
			cout << objResultForDiv << endl;
			system("pause");
			menu();
			break;
		}
		case 5: {
			menu();
			break;
		}
		default:
			break;
		}
		break;
	}
	case 4: {
		system("cls");
		cout << "Выход . . ." << endl;
		break;
	}
	default:
		break;
	}

}

