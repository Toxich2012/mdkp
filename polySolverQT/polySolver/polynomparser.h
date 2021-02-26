#ifndef POLYNOMPARSER_H
#define POLYNOMPARSER_H

#include "polynom.h"
#include <string>

/**
 * @brief Класс парсера строкового представления полиномов
 */
class PolynomParser
{
public:
    /**
     * @brief Конструктор парсера полинома
     * @param polynomStr полином в строковом представлении
     */
    explicit PolynomParser(const std::string &polynomStr);
    /**
     * @brief Функция парсинга полинома
     * @return полином
     */
    Polynom parse();

private:
    //! Все числа
    const std::string NUMS = "0123456789";
    //! Строковое представление полинома
    std::string polynomStr;
    //! Текущия позиция парсера
    int pos = 0;
    //! Длина строки
    int ENOS;

    /**
     * @brief Функция получения символа, относительно текущего
     * @param rel_pos относительная позиция
     * @return символ
     */
    char peek(int rel_pos=0);
    /**
     * @brief Функция получения текущего символа
     * @return текущий символ
     */
    char get();
    /**
     * @brief Функция парсинга числа
     * @return число
     */
    int parseNum();
};


#endif // POLYNOMPARSER_H
