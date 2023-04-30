#include <iostream>
#include <stdio.h>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <limits>
#include "Fraction.hpp"
namespace ariel
{
    // default constructor
    Fraction::Fraction()
    {
        this->num = 0;
        this->den = 1;
    }
    // constructor
    Fraction::Fraction(int a, int b)
    {
        if (b == 0)
        {
            throw std::invalid_argument("invalid_argument");
        }
        else if (a == 0)
        {
            this->num = 0;
            this->den = 1;
        }
        else
        {
            // if the user inserted a negative number in the den, flip the signs
            if (b < 0)
            {
                a = -a;
                b = -b;
            }
            this->num = a;
            this->den = b;
            this->reduce();
        }
    }

    // constructor for floats
    Fraction::Fraction(float f)
    {
        this->num = f * 1000; // we want the precision only three numbers after the point
        this->den = 1000;
        this->reduce();
    }
    // setters
    void Fraction::set_n(int a)
    {
        this->num = a;
    }
    void Fraction::set_d(int b)
    {
        if (b == 0)
        {
            throw std::runtime_error("invalid_argument");
        }
        this->den = b;
    }
    // getters
    Fraction Fraction::get_fraction()
    {
        return Fraction(this->getNumerator(), this->getDenominator());
    }
    int Fraction::getNumerator()
    {
        return this->num;
    }
    int Fraction::getDenominator()
    {
        return this->den;
    }

    Fraction operator+(const Fraction &f1, const Fraction &f2)
    {
        long long num = static_cast<long long>(f1.num) * static_cast<long long>(f2.den) +
                        static_cast<long long>(f2.num) * static_cast<long long>(f1.den);
        // check if there is an overflow
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("problamatic number!");
        }
        int d = f1.den * f2.den;
        Fraction new_fraction = Fraction(static_cast<int>(num), d);
        return new_fraction;
    }

    Fraction operator+(float d, const Fraction &f)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return t + f;
    }
    Fraction operator+(const Fraction &f, float d)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return t + f;
    }
    Fraction operator-(const Fraction &f1, const Fraction &f2)
    {
        long long num = static_cast<long long>(f1.num) * static_cast<long long>(f2.den) -
                        static_cast<long long>(f2.num) * static_cast<long long>(f1.den);
        // check if there is an overflow
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("problamatic number!");
        }
        int d = f1.den * f2.den;
        Fraction new_fraction = Fraction(static_cast<int>(num), d);
        return new_fraction;
    }

    Fraction operator-(float d, const Fraction &f)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return t - f;
    }
    Fraction operator-(const Fraction &f, float d)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return f - t;
    }

    Fraction operator*(const Fraction &f1, const Fraction &f2)
    {
        long long num = static_cast<long long>(f1.num) * static_cast<long long>(f2.num);
        // check if there is an overflow

        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("problamatic number!");
        }
        long long d = static_cast<long long>(f1.den) * static_cast<long long>(f2.den);
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("problamatic number!");
        }
        Fraction new_fraction = Fraction(static_cast<int>(num), static_cast<int>(d));
        return new_fraction;
    }

    Fraction operator*(float d, const Fraction &f)
    {
        Fraction t(d); // convert the float into fraction and use the function above

        return t * f;
    }

    Fraction operator*(const Fraction &f, float d)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return t * f;
    }

    Fraction operator/(const Fraction &f1, const Fraction &f2)
    {
        if (f2.num == 0)
        {
            throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        long long num = static_cast<long long>(f1.num) * static_cast<long long>(f2.den);
        long long den = static_cast<long long>(f1.den) * static_cast<long long>(f2.num);
        // check if there is an overflow
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
            den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("problamatic number!");
        }
        Fraction new_fraction = Fraction(static_cast<int>(num), static_cast<int>(den));
        return new_fraction;
    }

    Fraction operator/(float d, const Fraction &f)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return t / f;
    }
    Fraction operator/(const Fraction &f, float d)
    {
        Fraction t(d); // convert the float into fraction and use the function above
        return f / t;
    }
    // Check if two fractions are equal by comparing their floating-point approximations.
    bool operator==(const Fraction &f1, const Fraction &f2)
    {
        // Calculate the decimal value of each fraction by dividing the numerator by the denominator.
        float fractionValue1 = (float)f1.num / f1.den;
        float fractionValue2 = (float)f2.num / f2.den;

        // Convert the decimal value to a string and round it to 3 decimal places.
        std::string numStr1 = std::to_string(fractionValue1);
        std::string numStr2 = std::to_string(fractionValue2);
        float numRounded1 = std::stof(numStr1.substr(0, numStr1.find('.') + 4));
        float numRounded2 = std::stof(numStr2.substr(0, numStr2.find('.') + 4));

        // Return true if the rounded decimal values are equal, false otherwise.
        return numRounded1 == numRounded2;
    }
    // Check if two fraction anf float are equal
    bool operator==(const Fraction &f, float d)
    {
        float fractionValue = (float)f.num / f.den;
        std::string numStr = std::to_string(fractionValue);
        float numRounded = std::stof(numStr.substr(0, numStr.find('.') + 4));
        return numRounded == d;
    }
    
    bool operator==(float d, const Fraction &f)
    {
        float fractionValue = (float)f.num / f.den;
        std::string numStr = std::to_string(fractionValue);
        float numRounded = std::stof(numStr.substr(0, numStr.find('.') + 4));
        return numRounded == d;
    }

    // Check if two fractions are not equal by comparing their floating-point approximations.
    bool operator!=(const Fraction &f1, const Fraction &f2)
    {
        float fractionValue1 = (float)f1.num / f1.den;
        float fractionValue2 = (float)f2.num / f2.den;
        std::string numStr1 = std::to_string(fractionValue1);
        std::string numStr2 = std::to_string(fractionValue1);
        float numRounded1 = std::stof(numStr1.substr(0, numStr1.find('.') + 4));
        float numRounded2 = std::stof(numStr2.substr(0, numStr2.find('.') + 4));

        return numRounded1 == numRounded2;
    }

    bool operator>(const Fraction &f1, const Fraction &f2)
    {
        int n_a = f1.num * f2.den;
        int n_b = f2.num * f1.den;

        // Compare the numerators of the two fractions
        return n_a > n_b;
    }
    bool operator>(const Fraction &f, float d)
    {
        Fraction t(d);
        return f > t;
    }
    bool operator>(float d, const Fraction &f)
    {
        Fraction t(d);
        return t > f;
    }
    bool operator>=(const Fraction &f1, const Fraction &f2)
    {

        int n_a = f1.num * f2.den;
        int n_b = f2.num * f1.den;

        // Compare the numerators of the two fractions
        return n_a >= n_b;
    }
    bool operator>=(const Fraction &f, float d)
    {
        Fraction t(d);
        return f >= t;
    }
    bool operator>=(float d, const Fraction &f)
    {
        Fraction t(d);
        return t >= f;
    }
    bool operator<(const Fraction &f1, const Fraction &f2)
    {
        int n_a = f1.num * f2.den;
        int n_b = f2.num * f1.den;

        // Compare the numerators of the two fractions
        return n_a < n_b;
    }
    bool operator<(const Fraction &f, float d)
    {
        Fraction t(d);
        return f < t;
    }
    bool operator<(float d, const Fraction &f)
    {
        Fraction t(d);
        return t < f;
    }
    bool operator<=(const Fraction &f1, const Fraction &f2)
    {

        int n_a = f1.num * f2.den;
        int n_b = f2.num * f1.den;
        // Compare the numerators of the two fractions
        return n_a <= n_b;
    }
    bool operator<=(const Fraction &f, float d)
    {
        Fraction t(d);
        return f <= t;
    }
    bool operator<=(float d, const Fraction &f)
    {
        Fraction t(d);
        return t <= f;
    }
    //increas the fraction by 1 and return a reference to the new fraction
    Fraction &Fraction::operator++()
    {
        this->num = this->num + this->den; 
        this->reduce();

        return *this;
    }
    //decreas the fraction by 1 and return a reference to the new fraction
    Fraction &Fraction::operator--()
    {
        this->num = this->num - this->den;
        this->reduce();
        return *this;
    }
    //increas the fraction by 1 and return a reference to the old fraction
    Fraction Fraction::operator++(int)
    {
        Fraction old_fraction = *this;
        ++(*this);
        return old_fraction;
    }
    //decreas the fraction by 1 and return a reference to the new fraction
    Fraction Fraction::operator--(int)
    {
        Fraction old_fraction = *this;
        --(*this);
        return old_fraction;
    }


    std::ostream &operator<<(std::ostream &os, const Fraction &f)
    {
        Fraction t = f;
        // if the denominator is negative flip signs
        if (t.getDenominator() < 0)
        {
            t.set_n(-t.getNumerator());
            t.set_d(-t.getDenominator());
        }
        os << t.getNumerator() << "/" << t.getDenominator();
        return os;
    }

    std::istream &operator>>(std::istream &is, Fraction &f)
    {
        int num = 0, denom = 1;
        int sign = 1;
        bool in_num = true;

        // Read the numerator
        if (!(is >> num))
        {
            // Failed to read numerator
            throw std::runtime_error("Failed to read numerator");
        }

        // Check for negative sign
        char c = is.peek();
        if (c == '-')
        {
            sign = -1;
            is.ignore(1);
        }

        // Read the denominator
        if (!(is >> denom))
        {
            // Failed to read denominator
            throw std::runtime_error("Failed to read denominator");
        }

        if (denom == 0)
        {
            // Denominator cannot be zero
            throw std::runtime_error("Denominator cannot be zero");
        }

        f.set_n(num * sign);
        f.set_d(denom);

        return is;
    }

    void Fraction::reduce()
    {
        // Keep track of the signs of the numerator and denominator
        int num_sign = 1;
        int denom_sign = 1;

        if (this->num < 0)
        {
            num_sign = -1;
            this->num = -this->num;
        }

        if (this->den < 0)
        {
            denom_sign = -1;
            this->den = -this->den;
        }

        // Find the greatest common divisor of the numerator and denominator
        int gcd = this->gcd(this->num, this->den);

        // Divide the numerator and denominator by the gcd to reduce the fraction
        this->num = num_sign * (this->num / gcd);
        this->den = denom_sign * (this->den / gcd);
    }

    int Fraction::gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    string Fraction::toString() const
    {
        return std::to_string(this->num) + '/' + std::to_string(this->den);
    }

}