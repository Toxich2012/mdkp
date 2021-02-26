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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void sumPolynoms();
    void subPolynoms();
    void mulPolynoms();
    void derivePolynom();
    void solvePolynomForX();
    void copyResult();
};
#endif // MAINWINDOW_H
