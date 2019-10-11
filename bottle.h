#pragma once

#include <iostream>

class Bottle {
public:

    Bottle(double volume, double fill_percent = 0);

    double GetVolume() const;
    double GetFillPercent() const;

    double GetFilledVolume() const;

    friend double operator + (const Bottle& lhs, const Bottle& rhs);
    friend double operator - (const Bottle& lhs, const Bottle& rhs);

    friend bool operator == (const Bottle& lhs, const Bottle& rhs);
    friend bool operator > (const Bottle& lhs, const Bottle& rhs);
    friend bool operator < (const Bottle& lhs, const Bottle& rhs);

private:
    double volume_;
    double fill_percent_;
};

Bottle operator""_bottle(const char* str, size_t size);