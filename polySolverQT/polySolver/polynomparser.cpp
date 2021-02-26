#include "polynomparser.h"

PolynomParser::PolynomParser(const std::string &polynomStr) : polynomStr(polynomStr)
{
    ENOS = polynomStr.length();
}

Polynom PolynomParser::parse()
{
    Polynom p;

    bool hasNum = false;
    int latNum = 0;
    while (pos != ENOS) {
        char c = peek();
        if (c == 'x') {
            char ac = peek(1);
            get();
            if (ac == '^') {
                get();
                int mult = 1;
                char possibleSign = peek();
                if (possibleSign == '-' || possibleSign == '+') {
                    get();
                    mult = possibleSign == '-'? -1 : 1;
                }
                int exp = this->parseNum();
                p.addTerm(hasNum? latNum : 1, exp * mult);
            }
            else {
                p.addTerm(hasNum? latNum : 1, 1);
            }
            latNum = 0;
            hasNum = false;
        }
        else if (c == '+' || c == '-') {
            char sign = get();
            int num = this->parseNum();
            num *= sign == '+'? 1 : -1;
            latNum = num;
            hasNum = true;
        }
        else {
            int num = this->parseNum();
            latNum = num;
            hasNum = true;
        }

        if (hasNum && peek() != 'x') {
            p.addTerm(latNum, 0);
            latNum = 0;
            hasNum = false;
        }
    }

    return p;
}

char PolynomParser::peek(int rel_pos)
{
    return polynomStr[pos+rel_pos];
}

char PolynomParser::get()
{
    return polynomStr[pos++];
}

int PolynomParser::parseNum()
{
    std::string numAccum;
    while (pos != ENOS && NUMS.find(peek()) != std::string::npos) {
        numAccum += get();
    }

    if (numAccum.empty()) {
        throw std::invalid_argument("invalid polynom");
    }

    return stoi(numAccum);
}
