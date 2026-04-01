#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
#include <concepts>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational {
private:
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) return; 
        if (num_ == 0) { den_ = 1; return; }
        I common = std::gcd(num_, den_);
        num_ /= common; den_ /= common;
        if (den_ < 0) { num_ = -num_; den_ = -den_; }
    }

public:
    rational() : num_(0), den_(1) {} 
    rational(I n, I d) : num_(n), den_(d) { simplify(); } 

    I num() const { return num_; } 
    I den() const { return den_; } 

    bool is_nan() const { return num_ == 0 && den_ == 0; }
    bool is_inf() const { return num_ != 0 && den_ == 0; } 

    rational& operator+=(const rational& other) {
        if (is_nan() || other.is_nan()) { num_ = 0; den_ = 0; }
        else if (is_inf() || other.is_inf()) { num_ = 1; den_ = 0; }
        else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ *= other.den_;
            simplify();
        }
        return *this;
    }

    rational& operator*=(const rational& other) {
        if (is_nan() || other.is_nan()) { num_ = 0; den_ = 0; }
        else { num_ *= other.num_; den_ *= other.den_; simplify(); }
        return *this;
    }

    rational& operator-=(const rational& other) { return *this += rational(-other.num(), other.den()); }
    rational& operator/=(const rational& other) { return *this *= rational(other.den(), other.num()); }

    
    rational operator+(const rational& other) const { rational r = *this; r += other; return r; }
    rational operator-(const rational& other) const { rational r = *this; r -= other; return r; }
    rational operator*(const rational& other) const { rational r = *this; r *= other; return r; }
    rational operator/(const rational& other) const { rational r = *this; r /= other; return r; }
};

// Overload 
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.is_nan()) os << "NaN";
    else if (r.is_inf()) os << "Inf";
    else os << r.num() << "/" << r.den();
    return os;
}
#endif
