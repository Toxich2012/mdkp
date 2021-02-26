#ifndef POLYNOM_H
#define POLYNOM_H

#include <sstream>
#include <map>
#include <cmath>

/**
 * @brief Класс полинома
 */
class Polynom
{
public:
    /**
     * @brief Конструктор класса
     */
    Polynom();

    /**
     * @brief Функция добавления члена полинома
     * @param mul множитель
     * @param exp степень
     */
    void addTerm(int mul, int exp);
    /**
     * @brief Решение полинома
     * @param x
     * @return значение полинома
     */
    double eval(double x);
    /**
     * @brief Функция представления полинома в виде строки
     * @return полином в виде строки
     */
    std::string to_string();

    /**
     * @brief Функця нахождения производной полинома
     * @return производная полинома
     */
    Polynom derive() const;
    /**
     * @brief Перегрузка оператора сложения, для сложения полиномов
     * @param right правый операнд сложения
     * @return результат сложения
     */
    Polynom operator+(const Polynom &right) const;
    /**
     * @brief Перегрузка оператора вычитания, для вычитания полиномов
     * @param right правый операнд вычитания
     * @return результат вычитания
     */
    Polynom operator-(const Polynom &right) const;
    /**
     * @brief Перегрузка оператора умножения, для умножения полиномов
     * @param right правый операнд умножения
     * @return результат умножения
     */
    Polynom operator*(const Polynom &right) const;

private:
    //! Члены полинома
    std::map<int, int> terms;
};

#endif // POLYNOM_H
