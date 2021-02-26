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
