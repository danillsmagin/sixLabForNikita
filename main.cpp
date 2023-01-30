#include <complex>
#include <conio.h>
#include <iostream>
#include <istream>
#include <windows.h>

using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex() {// конструктор по умолчанию
        this->real = 0;
        this->imag = 0;
    }

    Complex(double r, double i) {// перегруженный конструктор
        if(r>abs(1000000)){
            throw -1;
        }
        else if(i>abs(1000000)){
            throw -2;
        }
        this->real = r;
        this->imag = i;
    }

    Complex(const Complex &compnum) {//конструктор копирования
        this->real = compnum.real;
        this->imag = compnum.imag;
    }

    friend Complex operator+(Complex &number1, Complex &number2);

    friend Complex operator-(Complex &number1, Complex &number2);

    friend Complex operator*(Complex &number1, Complex &number2);

    friend Complex operator/(Complex &number1, Complex &number2);

    friend bool operator==(const Complex &complexNumber1, const Complex &complexNumber2);

    friend bool operator!=(const Complex &complexNumber1, const Complex &complexNumber2);

    friend ostream &operator<<(ostream &out, const Complex &complex);

    friend istream &operator>>(istream &in, Complex &complex);

    void comparisonComplexNumbers() {
        if (real == imag)
            cout << "Complex numbers equal" << endl;
        else
            cout << "Complex numbers equal" << endl;
    }

    ~Complex() = default;
};

bool operator==(const Complex &number1, const Complex &number2) {
    return (number1.real == number2.real && number1.imag == number2.imag);
}

bool operator!=(const Complex &number1, const Complex &number2) {
    return !(number1 == number2);
}

ostream &operator<<(ostream &out, const Complex &number1) {
    if (number1.imag < 0) {
        out << "Complex number: " << number1.real << " - " << abs(number1.imag) << "i" << endl;
    } else if (number1.imag == 0) {
        out << "Complex number: " << number1.real << endl;
    } else if (number1.imag > 0) {
        out << "Complex number: " << number1.real << " + " << number1.imag << "i" << endl;
    }
    return out;
}

istream &operator>>(istream &in, Complex &number1) {
    cout << "Enter real and imaginary part: ";
    in >> number1.real >> number1.imag;
    if (number1.real>abs(1000000)){
        throw -1;
    }
    else if(number1.imag > abs(1000000)){
        throw -2;
    }
    return in;
}

Complex operator+(Complex &number1, Complex &number2) {//Перегруженный опертор +(сумма)
    Complex result;
    result.real = (number1.real + number2.real);
    result.imag = (number1.imag + number2.imag);
    return result;
}

Complex operator-(Complex &number1, Complex &number2) {//Перегруженный опертор +(сумма)
    Complex result;
    result.real = (number1.real - number2.real);
    result.imag = (number1.imag - number2.imag);
    return result;
}

Complex operator*(Complex &number1, Complex &number2) {
    Complex result;
    result.real = (number1.real * number2.real) - (number1.imag * number2.imag);
    result.imag = (number1.real * number2.imag) + (number1.imag * number2.real);
    return result;
}

Complex operator/(Complex &number1, Complex &number2) {
    Complex result;
    result.real = ((number1.real * number2.real + number1.imag * number2.imag) /
                   (pow(number2.real, 2) + pow(number2.imag, 2)));
    result.imag = ((number1.imag * number2.real - number1.real * number2.imag) /
                   (pow(number2.real, 2) + pow(number2.imag, 2)));
    return result;
}

int main() {
    Complex complex1(0, 0), complex2(0, 0), complex3(0, 0);

    try {
        cout << "first complex number" << endl;
        cin >> complex1;
        cout << complex1;
        cout << "second complex number" << endl;
        cin >> complex2;
        cout << complex2;
    } catch (int error) {
        if (error==-1){
            cout<<"real part > 1000000"<<endl;
        }
        else if(error==-2){
            cout<<"imag part > 1000000"<<endl;
        }
        return 0;
    }
    int n;
    cout << "Choose number from 1 to 6" << endl;
    cout << "1. Addition complex numbers" << endl;
    cout << "2. Difference complex numbers" << endl;
    cout << "3. Product complex numbers" << endl;
    cout << "4. Division complex numbers" << endl;
    cout << "5. Comparison complex numbers" << endl;
    cout << "6. Exit" << endl;

    do {
        cin >> n;
        switch (n) {

            case 1:
                complex3 = complex1 + complex2;
                cout << "Result addition complex number this " << complex3 << endl;
                _getch();
                break;
            case 2:
                complex3 = complex1 - complex2;
                cout << "Result difference complex number this " << complex3 << endl;
                break;
            case 3:
                complex3 = complex1 * complex2;
                cout << "Result product complex number this " << complex3 << endl;
                _getch();
                break;
            case 4:
                complex3 = complex1 / complex2;
                cout << "Result division complex number this " << complex3 << endl;
                _getch();
                break;
            case 5:
                if (complex1 == complex2)
                    cout << "Complex numbers equal" << endl;
                else if (complex1 != complex2)
                    cout << "Complex numbers not equal" << endl;
                _getch();
                break;
            case 6:
                cout << "Press enter if u wont close this window";
                _getch();
                return 0;
            default:
                cout << "Choose number from 1 to 6!!!!!!!" << endl;
        }
        if (n != 6)
            system("pause");
    } while (n != 6);
}
