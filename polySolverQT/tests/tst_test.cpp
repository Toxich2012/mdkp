#include <QtTest>

#include "../polySolver/polynom.h"
#include "../polySolver/polynomparser.h"

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void polynom_parse();
    void polynom_parse_error();
    void polynom_addition();
    void polynom_subtraction();
    void polynom_multiplication();
    void polynom_derrivation();
    void polynom_solve();

};

test::test()
{

}

test::~test()
{

}

void test::polynom_parse()
{
    Polynom p1;
    p1.addTerm(2, 5);

    Polynom p2 = PolynomParser("2x^5").parse();
    QCOMPARE((p1 - p2).to_string(), "0");
}

void test::polynom_parse_error()
{
    QVERIFY_EXCEPTION_THROWN(PolynomParser("x^").parse(), std::invalid_argument);
}

void test::polynom_addition()
{
    Polynom p1;
    p1.addTerm(2, 0);

    Polynom p2 = PolynomParser("2").parse();

    QCOMPARE((p1 + p2).to_string(), "+4");
}

void test::polynom_subtraction()
{
    Polynom p1;
    p1.addTerm(2, 0);

    Polynom p2 = PolynomParser("2").parse();

    QCOMPARE((p1 - p2).to_string(), "0");
}

void test::polynom_multiplication()
{
    Polynom p1;
    p1.addTerm(2, 0);

    Polynom p2 = PolynomParser("2").parse();

    QCOMPARE((p1 * p2).to_string(), "+4");
}

void test::polynom_derrivation()
{
    Polynom p1;
    p1.addTerm(2, 0);

    Polynom p2 = PolynomParser("2x^8").parse();

    QCOMPARE(p1.derive().to_string(), "0");
    QCOMPARE(p2.derive().to_string(), "+16x^7");
}

void test::polynom_solve()
{
    Polynom p1 = PolynomParser("5x^2-8x+13-5x^-2").parse();

    QCOMPARE(p1.eval(3), 33.444444444444444444444);
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
