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

Bottle operator""_bottle(const char* str, size_t size) {
    int idx = -1;
    for (int i = 0; i < size; ++i) {
        if (str[i] == ',') {
            idx = i;
        }
    }
    if (idx == -1 || idx == size - 1 || idx == 0) {

    }
    char* first_part = new char[idx];
    char* second_part = new char [size - idx - 1];
    std::copy(str, str + idx, first_part);
    std::copy(str + idx + 1, str + size, second_part);
    return Bottle(std::stod(first_part), std::stod(second_part));
}

std::istream& operator >> (std::istream& is, Bottle& b) {
    double volume, percent;
    is >> volume >> percent;
    b = Bottle(volume, percent);
    return is;
}

std::ostream& operator << (std::ostream& os, const Bottle& b) {
    os << "Volume:" <<b.GetVolume() << ", Fill percent:" << b.GetFillPercent() << ", Filled volume:" << b.GetFilledVolume();
}