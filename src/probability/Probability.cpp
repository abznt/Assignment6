#include "Probability.h"
#include <stdexcept>

Probability::Probability(const double p) : _probability{validateInput(p)} {}

Probability::operator double() const {
    return _probability;
}

Probability& Probability::operator=(const double p) {
    _probability = validateInput(p);
    return *this;
}

bool operator==(const Probability &p1, const Probability &p2) {
    return p1._probability == p2._probability;
}

Probability Probability::operator~() const {
    return Probability(1 - _probability);
}

Probability operator&(const Probability &p1, const Probability &p2) {
    return Probability(p1._probability * p2._probability);
}

Probability operator|(const Probability &p1, const Probability &p2) {
    return Probability(p1._probability + p2._probability - (double)(p1 & p2));
}

Probability operator^(const Probability &p1, const Probability &p2) {
    return Probability(p1._probability + p2._probability - 2*(double)(p1 & p2));
}

Probability operator-(const Probability &p1, const Probability &p2) {
    return Probability(p1._probability - (double)(p1 & p2));
}

double Probability::validateInput(double p) {
    if (p >= 0.0 && p <= 1.0) {
        return p;
    }
    else {
        throw std::invalid_argument("assigned probability not in range 0 <= p <= 1");
    }
}




