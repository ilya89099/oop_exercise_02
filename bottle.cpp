#include "bottle.h"
#include <exception>
#include <stdexcept>

Bottle::Bottle(double volume, double fill_percent)
: volume_(volume), fill_percent_(fill_percent) {
    if (volume < 0 || fill_percent < 0 || fill_percent > 1) {
        throw std::logic_error("Unacceptable parameters for constructor");
    }
}

double Bottle::GetVolume() const {
    return volume_;
}

double Bottle::GetFillPercent() const {
    return fill_percent_;
}

Bottle& Bottle::SetPercent(double percent) {
    if (percent < 0 || percent > 1) {
        throw std::logic_error("Unacceptable percent value");
    }
    fill_percent_ = percent;
    return *this;
}

double Bottle::GetFilledVolume() const {
    return volume_ * fill_percent_;
}

double operator + (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() + rhs.GetFilledVolume();
}

double operator - (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() - rhs.GetFilledVolume();
}

bool operator == (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() == rhs.GetFilledVolume();
}

bool operator > (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() > rhs.GetFilledVolume();
}

bool operator < (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() < rhs.GetFilledVolume();
}

Bottle operator""_bottle(long double size) {
    return Bottle(size);
}