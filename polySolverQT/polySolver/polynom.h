#ifndef POLYNOM_H
#define POLYNOM_H

#include <sstream>
#include <map>
#include <cmath>

class Polynom
{
public:
    Polynom();

    void addTerm(int mul, int exp);
    double eval(int x);
    std::string to_string();

    Polynom derive() const;
    Polynom operator+(const Polynom &right) const;
    Polynom operator-(const Polynom &right) const;

private:
    std::map<int, int> terms;
};

#endif // POLYNOM_H
