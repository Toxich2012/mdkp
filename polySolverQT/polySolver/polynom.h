#ifndef POLYNOM_H
#define POLYNOM_H

#include <QString>



class Polynom
{
public:
    Polynom();

    Polynom* parse(QString polyStr);

    double solve(double value);
    Polynom add(Polynom *other);
    Polynom sub(Polynom *other);

private:
    QString polyStr;
    QMap<int, int> terms();
};

#endif // POLYNOM_H
