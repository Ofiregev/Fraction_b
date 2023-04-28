#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <string>
using namespace std;
     
namespace ariel {
    class Fraction {
        private:
            int n;
            int d;
        public:
            Fraction();
            Fraction(int a, int b);
            Fraction(float a);
            Fraction get_fraction();
            int getNumerator();
            int getDenominator();
            void set_n(int a);
            void set_d(int b);
            friend Fraction operator+(const Fraction& f1, const Fraction& f2);
            friend Fraction operator+(float d, const Fraction& f);
            friend Fraction operator+(const Fraction& f, float d);
            friend Fraction operator-(const Fraction& f1, const Fraction& f2);
            friend Fraction operator-(float d, const Fraction& f);
            friend Fraction operator-(const Fraction& f, float d);
            friend Fraction operator*(const Fraction& f1, const Fraction& f2);
            friend Fraction operator*(float d, const Fraction& f);
            friend Fraction operator*(const Fraction& f, float d);
            friend Fraction operator/(const Fraction& f1, const Fraction& f2) ;
            friend Fraction operator/(float d, const Fraction& f);
            friend Fraction operator/(const Fraction& f, float d);
            friend bool operator==(const Fraction& f1, const Fraction& f2);
            friend bool operator==(const Fraction& f, float d);
            friend bool operator==(float d, const Fraction& f);
            friend bool operator>(const Fraction& f1, const Fraction& f2);
            friend bool operator>(const Fraction& f, float d);
            friend bool operator>(float d, const Fraction& f);
            friend bool operator>=(const Fraction& f1, const Fraction& f2);
            friend bool operator>=(const Fraction& f, float d);
            friend bool operator>=(float d, const Fraction& f);
            friend bool operator<(const Fraction& f1, const Fraction& f2);
            friend bool operator<(const Fraction& f, float d);
            friend bool operator<(float d, const Fraction& f);
            friend bool operator<=(const Fraction& f1, const Fraction& f2);
            friend bool operator<=(const Fraction& f, float d);
            friend bool operator<=(float d, const Fraction& f);
            Fraction& operator++();   // prefix increment operator
            Fraction& operator--();   // prefix decrement operator
            Fraction operator++(int); // postfix increment operator
            Fraction operator--(int); // postfix decrement operator 
            friend std::ostream &operator<<(std::ostream &stream, const Fraction &f);
            friend std::istream& operator>>(std::istream& is, Fraction& f); // input stream operator
            void reduce();
            int gcd(int a, int b);
            std::string toString() const;
    };
}

    


#endif