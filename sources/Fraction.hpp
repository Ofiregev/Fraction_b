#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <string>
using namespace std;
     
namespace ariel {
    class Fraction {
        private:
            int num;
            int den;
        public:
            Fraction();
            Fraction(int num, int den);
            Fraction(float float_frac);
            Fraction get_fraction();
            int getNumerator();
            int getDenominator();
            void set_n(int num);
            void set_d(int den);
            friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator+(float float_frac, const Fraction& frac);
            friend Fraction operator+(const Fraction& frac, float float_frac);
            friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator-(float float_frac, const Fraction& frac);
            friend Fraction operator-(const Fraction& frac, float float_frac);
            friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator*(float float_frac, const Fraction& frac);
            friend Fraction operator*(const Fraction& frac, float float_frac);
            friend Fraction operator/(const Fraction& frac1, const Fraction& frac2) ;
            friend Fraction operator/(float float_frac, const Fraction& frac);
            friend Fraction operator/(const Fraction& frac, float float_frac);
            friend bool operator==(const Fraction& frac1, const Fraction& frac2);
            friend bool operator==(const Fraction& frac, float float_frac);
            friend bool operator==(float float_frac, const Fraction& frac);
            friend bool operator!=(const Fraction& frac1, const Fraction& frac2);

            friend bool operator>(const Fraction& fracf1, const Fraction& frac2);
            friend bool operator>(const Fraction& frac, float float_frac);
            friend bool operator>(float float_frac, const Fraction& frac);
            friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
            friend bool operator>=(const Fraction& frac, float float_frac);
            friend bool operator>=(float float_frac, const Fraction& frac);
            friend bool operator<(const Fraction& frac1, const Fraction& frac2);
            friend bool operator<(const Fraction& frac, float float_frac);
            friend bool operator<(float float_frac, const Fraction& frac);
            friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
            friend bool operator<=(const Fraction& frac, float float_frac);
            friend bool operator<=(float float_frac, const Fraction& frac);
            Fraction& operator++();   // prefix increment operator
            Fraction& operator--();   // prefix decrement operator
            Fraction operator++(int); // postfix increment operator
            Fraction operator--(int); // postfix decrement operator 
            friend std::ostream &operator<<(std::ostream &stream, const Fraction &frac);
            friend std::istream& operator>>(std::istream& ios, Fraction& frac); // input stream operator
            void reduce();
            int gcd(int num, int den);
            std::string toString() const;
    };
}

    


#endif