#ifndef POLYNOM_H
#define POLYNOM_H

#include <QString>
#include <map>



class Polynom
{
public:
    Polynom();

    void addTerm(int mul, int exp);
    double eval(int x);
    std::string to_string();

private:
    std::map<int, int> terms;
};

#endif // POLYNOM_H
