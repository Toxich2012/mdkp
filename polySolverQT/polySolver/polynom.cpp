#include "polynom.h"

Polynom::Polynom()
{

}

Polynom *Polynom::parse(QString polyStr)
{
    auto polynom = new Polynom();
    polynom->polyStr = polyStr;

    return polynom;
}

double Polynom::solve(double value)
{

}

Polynom Polynom::add(Polynom *other)
{

}

Polynom Polynom::sub(Polynom *other)
{

}
