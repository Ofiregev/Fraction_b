#include <iostream>
#include <stdio.h>
#include <numeric>
#include <iomanip>
#include <math.h>
#include "Fraction.hpp"
namespace ariel
{
    Fraction::Fraction()
    {
        this->n = 0;
        this->d = 1;
    }
    Fraction::Fraction(int a, int b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        else if (a == 0)
        {
            this->n = 0;
            this->d = 1;
        }
        else
        {
            this->n = a;
            this->d = b;
            this->reduce();
        }
    }
    Fraction::Fraction(float f)
    {
        this->n = f * 1000;
        this->d = 1000;
        this->reduce();
    }
    void Fraction::set_n(int a)
    {
        this->n = a;
    }
    void Fraction::set_d(int b)
    {
        this->d = b;
    }

    Fraction Fraction::get_fraction()
    {
        return Fraction(this->getNumerator(), this->getDenominator());
    }
    int Fraction::getNumerator()
    {
        return this->n;
    }
    int Fraction::getDenominator()
    {
        return this->d;
    }

    Fraction operator+(const Fraction &f1, const Fraction &f2)
    {
        // Calculate the sum of the two fractions
        int sum_of_n = (f1.n * f2.d) + (f1.d * f2.n);
        int sum_of_d = f1.d * f2.d;
        Fraction new_fraction = Fraction(sum_of_n, sum_of_d);
        new_fraction.reduce();
        return new_fraction;
    }

    Fraction operator+(float d, const Fraction &f)
    {
        Fraction t(d);
        return t + f;
    }
    Fraction operator+(const Fraction &f, float d)
    {
        Fraction t(d);
        return t + f;
    }
    Fraction operator-(const Fraction &f1, const Fraction &f2)
    {
        // Calculate the sum of the two fractions
        int dif_of_n = (f1.n * f2.d) - (f1.d * f2.n);
        int mul_of_d = f1.d * f2.d;
        Fraction new_fraction = Fraction(dif_of_n, mul_of_d);
        return new_fraction;
    }

    Fraction operator-(float d, const Fraction &f)
    {
        Fraction t(d);
        return t - f;
    }
    Fraction operator-(const Fraction &f, float d)
    {
        Fraction t(d);
        return f - t;
    }

    Fraction operator*(const Fraction &f1, const Fraction &f2)
    {
        int n = f1.n * f2.n;
        int d = f1.d * f2.d;
        Fraction new_fraction = Fraction(n, d);
        return new_fraction;
    }

    Fraction operator*(float d, const Fraction &f)
    {
        Fraction t(d);

        return t * f;
    }

    Fraction operator*(const Fraction &f, float d)
    {
        Fraction t(d);
        return t * f;
    }

    Fraction operator/(const Fraction &f1, const Fraction &f2)
    {
        if (f2.n == 0)
        {
            throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        int new_n = f1.n * f2.d;
        int new_d = f1.d * f2.n;
        Fraction res(new_n, new_d);
        return res;
    }
    Fraction operator/(float d, const Fraction &f)
    {
        Fraction t(d);
        return t / f;
    }
    Fraction operator/(const Fraction &f, float d)
    {
        Fraction t(d);
        return f / t;
    }
    bool operator==(const Fraction &f1, const Fraction &f2)
    {
        Fraction temp = f2;
        return (f1.n == temp.n) && (f1.d == temp.d);
    }
    bool operator==(const Fraction &f, float d)
    {
        Fraction t(d);
        return f == t;
    }
    bool operator==(float d, const Fraction &f)
    {
        Fraction t(d);
        return f == t;
    }
    bool operator>(const Fraction &f1, const Fraction &f2)
    {
        int n_a = f1.n * f2.d;
        int n_b = f2.n * f1.d;

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
        int n_a = f1.n * f2.d;
        int n_b = f2.n * f1.d;

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
        int n_a = f1.n * f2.d;
        int n_b = f2.n * f1.d;

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
        int n_a = f1.n * f2.d;
        int n_b = f2.n * f1.d;

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
    Fraction &Fraction::operator++()
    {
        this->n = this->n + this->d;
        this->reduce();

        return *this;
    }
    Fraction &Fraction::operator--()
    {
        this->n = this->n - this->d;
        this->reduce();
        return *this;
    }
    Fraction Fraction::operator++(int)
    {
        Fraction old_fraction = *this;
        ++(*this);
        return old_fraction;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction old_fraction = *this;
        --(*this);
        return old_fraction;
    }

    // std::ostream &operator<<(std::ostream &stream, const Fraction &f)
    // {

    //     stream << f.toString();
    //     return stream;
    // }

    std::ostream& operator<<(std::ostream& os, const Fraction& f) 
    {
    Fraction t = f;
    os << t.getNumerator() << "/" << t.getDenominator();
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    std::string input_str;
    std::getline(is, input_str);

    if (input_str.length() <= 1) {
        throw std::runtime_error("Invalid stream");
    }

    char delimiter = ' ';
    size_t pos = input_str.find(delimiter);

    if (pos == std::string::npos) {
        delimiter = ',';
        pos = input_str.find(delimiter);
    }

    if (pos == std::string::npos) {
        delimiter = '/';
        pos = input_str.find(delimiter);
    }

    if (pos == std::string::npos) {
        throw std::runtime_error("Invalid stream");
    }

    std::string num_str = input_str.substr(0, pos);
    std::string denom_str = input_str.substr(pos+1);

    int n = std::stoi(num_str);
    int d = std::stoi(denom_str);

    f.set_n(n);
    f.set_d(d);

    return is;
}



    // std::istream &operator>>(std::istream &stream, Fraction &f)
    // {
    //     char s;
    //     stream >> f.n >> s >> f.d;
    //     f.reduce();
    //     return stream;
    // }
    void Fraction::reduce()
    {
        // Find the greatest common divisor of the numerator and denominator
        int gcd = this->gcd(this->n, this->d);

        // Divide the numerator and denominator by the gcd to reduce the fraction
        this->n = this->n / gcd;
        this->d = this->d / gcd;
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
        return std::to_string(this->n) + '/' + std::to_string(this->d);
    }

}