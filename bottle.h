#pragma once

#include <iostream>

class Bottle {
public:
    Bottle() = default;
    Bottle(double volume, double fill_percent = 0);

    double GetVolume() const;
    double GetFillPercent() const;

    double GetFilledVolume() const;

    friend double operator + (const Bottle& lhs, const Bottle& rhs);
    friend double operator - (const Bottle& lhs, const Bottle& rhs);

    friend bool operator == (const Bottle& lhs, const Bottle& rhs);
    friend bool operator > (const Bottle& lhs, const Bottle& rhs);
    friend bool operator < (const Bottle& lhs, const Bottle& rhs);

    friend std::istream& operator >> (std::istream& is, Bottle& b);
    friend std::ostream& operator << (std::ostream& os, const Bottle& b);

private:
    double volume_ = 0;
    double fill_percent_ = 0;
};

Bottle operator""_bottle(const char* str, size_t size);