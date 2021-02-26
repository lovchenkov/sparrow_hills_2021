#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:

    Complex() {
    }

    Complex(const double real, const double imaginary) {
        _real = real;
        _imaginary = imaginary;
    }

    Complex(const Complex& copied) {
        _real = copied._real;
        _imaginary = copied._imaginary;
    }

    Complex& operator=(const Complex& copied) {
        _real = copied._real;
        _imaginary = copied._imaginary;
    }

    ~Complex() {
    }

    bool operator!=(const Complex& other) const {
        if(_real != other._real || _imaginary != other._imaginary){
            return true;
        }
        return false;
    }

    bool operator==(const Complex& other) const {
        if(_real == other._real && _imaginary == other._imaginary){
            return true;
        }
        return false;
    }

    Complex operator-() const {
        Complex answer(*this);
        answer._real = -_real;
        answer._imaginary = -_imaginary;
        return answer;
    }

    Complex operator+(const Complex& other) const {
        Complex answer(*this);
        answer._real += other._real;
        answer._imaginary += other._imaginary;
        return answer;
    }

    Complex operator-(const Complex& other) const {
        Complex answer(*this);
        answer._real -= other._real;
        answer._imaginary -= other._imaginary;
        return answer;
    }

    Complex operator*(const Complex& other) const {
        Complex answer(*this);
        answer._real = _real*other._real - _imaginary*other._imaginary;
        answer._imaginary = _real*other._imaginary + _imaginary*other._real;
        return answer;
    }

    Complex operator/(const Complex& other) const {
        Complex answer(*this);
        answer._real = (_real*other._real + _imaginary*other._imaginary)/(other._real*other._real + other._imaginary*other._imaginary);
        answer._imaginary =(- _real*other._imaginary + _imaginary*other._real)/(other._real*other._real + other._imaginary*other._imaginary);
        return answer;
    }

    double module() const {
        return sqrt(_real*_real + _imaginary*_imaginary);
    }

    double argument() const {
        return atan2(_real, _imaginary);
    }

    Complex Conjugate() const {
        Complex answer(*this);
        answer._imaginary = -_imaginary;
        return answer;
    }
    void print(){
        cout << _real << ' ' << _imaginary << endl;
    }

private:
    double _real, _imaginary;
};

int main() {
    int errors = 0, tests = 0;
    Complex a;

    Complex b(1, 2);
    Complex c(b);
    ++tests;
    if (b != c) {
        cout << "Error: b != c" << endl;
        ++errors;
    }

    Complex d(2, 3);
    ++tests;
    if (b == d) {
        cout << "Error: b == d" << endl;
        ++errors;
    }
    Complex e = d;
    ++tests;
    if (d != e) {
        cout << "Error: d != e" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(3, 4).module() != 5) {
        cout << "Error: |3 + 4i| != 5" << endl;
        ++errors;
    }

    ++tests;
    if (fabs(Complex(3, 4).argument() - 0.6435011087) > 0.0000001) {
        cout << "Error: arg(3 + 4i) != " << endl;
        ++errors;
    }

    ++tests;
    if (- Complex(1, -3) != Complex(-1, 3)) {
        cout << "Error: - Complex(1, -3) != Complex(-1, 3)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(1, -3) + Complex(4, 2) != Complex(5, -1)) {
        cout << "Error: Complex(1, -3) + Complex(4, 2) != Complex(5, -1)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(1, -3) - Complex(4, 2) != Complex(-3, -5)) {
        cout << "Error: Complex(1, -3) - Complex(4, 2) != Complex(-3, -5)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(4, 3) * Complex(1, -2) != Complex(10, -5)) {
        cout << "Error: Complex(4, 3) * Complex(1, -2) != Complex(10, -5)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(4, 3) / Complex(1, 2) != Complex(2, -1)) {
        cout << "Error: Complex(4, 3) / Complex(1, 2) != Complex(2, -1)" << endl;
        ++errors;
    }

    cout << "Number of tests: " << tests << ", number of errors: " << errors << endl;

    return 0;

}
