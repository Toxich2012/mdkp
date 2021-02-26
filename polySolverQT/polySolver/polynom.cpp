#include "polynom.h"

Polynom::Polynom()
{

}

void Polynom::addTerm(int mul, int exp)
{
    terms[exp] += mul;
}

double Polynom::eval(int x)
{
    double out = 0;
    for (auto k : terms) {
        int exp = k.first;
        int mult = k.second;

        out += mult * std::pow(x, exp);
    }
    return out;
}

std::string Polynom::to_string()
{
    std::stringstream ss;
    for (auto k : terms) {
        int exp = k.first;
        int mult = k.second;

        ss << (mult >= 0? "+" : "") << mult;
        if (exp == 1) {
            ss << "x";
        }
        else if (exp != 0) {
            ss << "x^" << exp << "";
        }
    }
    return ss.str();
}

Polynom Polynom::derive() const
{
    Polynom p;
    for (auto k : terms) {
        int exp = k.first;
        int mult = k.second;
        if (exp == 0) {
            continue;
        }
        p.addTerm(mult*exp, exp-1);
    }
    return p;
}

Polynom Polynom::operator+(const Polynom &right) const
{
    Polynom p(*this);
    for (auto k : right.terms) {
        int exp = k.first;
        int mult = k.second;
        p.addTerm(mult, exp);
    }
    return p;
}

Polynom Polynom::operator-(const Polynom &right) const
{
    Polynom p(*this);
    for (auto k : right.terms) {
        int exp = k.first;
        int mult = k.second;
        p.addTerm(-mult, exp);
    }
    return p;
}
