#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QClipboard>

#include "polynom.h"
#include "polynomparser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Класс главного окна
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса главного окна
     * @param parent родитель окна
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~MainWindow();

private:
    //! Указатель на объект интерфейса окна
    Ui::MainWindow *ui;

private slots:
    /**
     * @brief Слот суммирования полиномов
     */
    void sumPolynoms();
    /**
     * @brief Слот вычитания полиномов
     */
    void subPolynoms();
    /**
     * @brief Слот умножения полиномов
     */
    void mulPolynoms();
    /**
     * @brief Слот нахождения производной полинома
     */
    void derivePolynom();
    /**
     * @brief Слот решения полинома от X
     */
    void solvePolynomForX();
    /**
     * @brief Слот копирования результатов
     */
    void copyResult();
};
#endif // MAINWINDOW_H
