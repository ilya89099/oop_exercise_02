#pragma once

class Bottle {
public:

    Bottle(double volume, double fill_percent = 0);

    Bottle& SetPercent(double percent);

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

Bottle operator""_bottle(long double size);