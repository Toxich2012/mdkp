#ifndef POLYNOMPARSER_H
#define POLYNOMPARSER_H

#include "polynom.h"
#include <string>

class PolynomParser
{
public:
    explicit PolynomParser(const std::string &polynomStr);
    char peek(int rel_pos=0);
    char get();
    int parseNum();
    Polynom parse();

private:
    const std::string NUMS = "0123456789";
    std::string polynomStr;
    int pos = 0;
    int ENOS;
};


#endif // POLYNOMPARSER_H
