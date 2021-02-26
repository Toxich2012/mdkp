#include "polynomparser.h"

PolynomParser::PolynomParser(const std::string &polynomStr) : polynomStr(polynomStr)
{
    ENOS = polynomStr.length();
}
