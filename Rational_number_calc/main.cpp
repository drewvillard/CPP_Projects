#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>

using namespace std;

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(); // default constructor
    Rational(int wholeNumber); // constructor with one argument
    Rational(int num, int den); // constructor with two arguments
    Rational(string strNum); // constructor with string argument
    std::vector<std::string> split(const string& input, const string& regex);
    void normalize(); // function to normalize the values stored
    // overloaded mathematical operators
    Rational operator+(Rational& r);
    Rational operator-(Rational& r);
    Rational operator*(Rational& r);
    Rational operator/(Rational& r);
    Rational& operator=(const Rational& r);
    // overloaded comparison operators
    bool operator>(Rational& r);
    bool operator<(Rational& r);
    bool operator==(Rational& r);
    // overloaded output operator
    friend ostream& operator<<(ostream& os,const Rational& r);
    //getters
    int getNumerator()const{return numerator;}
    int getDenominator()const{return denominator;}
};

Rational::Rational() {
    // initialize the object to 0/1
    this->numerator=0;
    this->denominator=1;
    cout << "----------------\ndefault constructor fired." << endl;
}

Rational::Rational(int wholeNumber) {
    // initialize the object to wholeNumber/1
    this->numerator=wholeNumber;
    this->denominator=1;
    cout << "---------------\nWhole number constructor fired." << endl;
}

Rational::Rational(int num, int den) {
    // initialize the object to num/den
    this->numerator=num;
    this->denominator=den;
    cout << "---------------\n2 Num Constructor fired." << endl;
}

//Split method
std::vector<std::string> Rational::split(const string& input, const string& regex){
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
    return {first, last};
}

Rational::Rational(string strNum) {
    // initialize the object based on the string strNum
    std::vector<std::string> tokens = split(strNum, "/");
    if (tokens.size() == 1) {
        numerator = stoi(tokens[0]);

        *this=Rational(numerator);
    } else if (tokens.size() == 2) {
        numerator = stoi(tokens[0]);
        denominator = stoi(tokens[1]);
    } else {
        throw std::invalid_argument("Invalid input string");
    }
    cout << "----------\nString Constructor fired." << endl;
}

void Rational::normalize() {
    // function to normalize the values stored
    // If the denominator is negative, make it positive and flip the sign of the numerator
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Divide the numerator and denominator by their greatest common divisor until they are relatively prime
    int commonDivisor = 2;
    while (commonDivisor <= abs(numerator) && commonDivisor <= denominator) {
        if (numerator % commonDivisor == 0 && denominator % commonDivisor == 0) {
            numerator /= commonDivisor;
            denominator /= commonDivisor;
        } else {
            commonDivisor++;
        }
    }
}

//Overloaded Methods
Rational Rational::operator+(Rational& r) {
    //overloaded addition operator
    int num = numerator * r.denominator + r.numerator * denominator;
    int den = denominator * r.denominator;
    Rational result(num,den);
    result.normalize();
    cout << "----------\noverload plus fired." << endl;
    return result;
}

Rational Rational::operator-(Rational& r) {
    // overloaded subtraction operator
    int num = numerator * r.denominator - r.numerator * denominator;
    int den = denominator * r.denominator;
    Rational result(num, den);
    result.normalize();
    cout << "----------\noverload minus fired." << endl;
    return result;
}

Rational Rational::operator*(Rational& r) {
    // overloaded multiplication operator
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    Rational result(num, den);
    result.normalize();
    cout << "----------\noverload multiplication fired." << endl;
    return result;
}

Rational Rational::operator/(Rational& r) {
    // overloaded division operator
    if (r.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    int num = numerator * r.denominator;
    int den = denominator * r.numerator;
    Rational result(num,den);
    result.normalize();
    cout << "----------\noverload division fired." << endl;
    return result;
}

Rational& Rational::operator=(const Rational& r) {
    // overloaded assignment operator
    if (this != &r) {
        numerator = r.numerator;
        denominator = r.denominator;
    }
    cout << "\n----------\noverload equals fired." << endl;
    return *this;
}

bool Rational::operator>(Rational& r) {
    // overloaded greater than operator
    cout << "\n----------\noverload greater than fired." << endl;
    if (numerator * r.denominator > r.numerator * denominator) {
        return true;
    } else {
        return false;
    }

}

bool Rational::operator<(Rational& r) {
    // overloaded less than operator
    cout << "\n----------\noverload less than fired." << endl;
    if (numerator * r.denominator <= r.numerator * denominator) {
        return true;
    } else {
        return false;
    }

}

bool Rational::operator==(Rational& r) {
    // overloaded equal to operator
    cout << "\n----------\noverload equals fired." << endl;
    if (numerator == r.numerator && denominator == r.denominator) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, const Rational& r) {
    // overloaded output operator
    os << r.getNumerator() << "/" << r.getDenominator();
    cout << "\n----------\noverload output fired." << endl;
    return os;
}

int main() {
    string firstRat;
    string secondRat;
    Rational r1, r2, result;

    cout << "\nRational Number Calculator\n";
    cout << "Enter q to quit.\n";

    while (true) {
        cout << "Enter The First Rational Number: ";
        getline(cin, firstRat);

        cout<<"Enter The Second Rational Number: ";
        getline(cin, secondRat);

        if (firstRat == "q" || secondRat == "q") {
            break;
        }

        try {
            r1 = Rational(firstRat);
            r2 = Rational(secondRat);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid input string: "<< endl;
            continue;
        }

        // perform the operations on r1 and r2
        result=(r1+r2);
        cout << "r1 + r2 = " << result<<endl;
        result=(r1-r2);
        cout << "r1 - r2 = " <<result<< endl;
        result=(r1*r2);
        cout << "r1 * r2 = " <<result<< endl;
        result=(r1/r2);
        cout << "r1 / r2 = " <<result<< endl;

        cout << "r1 > r2 is " << (r1 > r2 ? "true" : "false") << endl;
        cout << "\nr1 < r2 is " << (r1 < r2 ? "true" : "false") << endl;
        cout << "\nr1 == r2 is " << (r1 == r2 ? "true" : "false") << endl;

    return 0;
}

