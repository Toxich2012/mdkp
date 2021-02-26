#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->polySum, &QPushButton::clicked, this, &MainWindow::sumPolynoms);
    connect(ui->polySub, &QPushButton::clicked, this, &MainWindow::subPolynoms);
    connect(ui->polyMult, &QPushButton::clicked, this, &MainWindow::mulPolynoms);
    connect(ui->derivativeSolve, &QPushButton::clicked, this, &MainWindow::derivePolynom);
    connect(ui->xSolve, &QPushButton::clicked, this, &MainWindow::solvePolynomForX);
    connect(ui->copyResult, &QPushButton::clicked, this, &MainWindow::copyResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sumPolynoms()
{
    QString fPolyS = ui->polyInput->text().trimmed();
    QString sPolyS = ui->secondPoly->text().trimmed();
    if (fPolyS.isEmpty() || sPolyS.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все данные введены");
        return;
    }

    Polynom fPoly;
    Polynom sPoly;
    try {
        fPoly = PolynomParser(fPolyS.toStdString()).parse();
        sPoly = PolynomParser(sPolyS.toStdString()).parse();
    } catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат данных");
        return;
    }

    Polynom sumPoly = fPoly + sPoly;
    ui->result->setText(QString::fromStdString(sumPoly.to_string()));
}

void MainWindow::subPolynoms()
{
    QString fPolyS = ui->polyInput->text().trimmed();
    QString sPolyS = ui->secondPoly->text().trimmed();
    if (fPolyS.isEmpty() || sPolyS.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все данные введены");
        return;
    }

    Polynom fPoly;
    Polynom sPoly;
    try {
        fPoly = PolynomParser(fPolyS.toStdString()).parse();
        sPoly = PolynomParser(sPolyS.toStdString()).parse();
    } catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат данных");
        return;
    }

    Polynom sumPoly = fPoly - sPoly;
    ui->result->setText(QString::fromStdString(sumPoly.to_string()));
}

void MainWindow::mulPolynoms()
{
    QString fPolyS = ui->polyInput->text().trimmed();
    QString sPolyS = ui->secondPoly->text().trimmed();
    if (fPolyS.isEmpty() || sPolyS.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все данные введены");
        return;
    }

    Polynom fPoly;
    Polynom sPoly;
    try {
        fPoly = PolynomParser(fPolyS.toStdString()).parse();
        sPoly = PolynomParser(sPolyS.toStdString()).parse();
    } catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат данных");
        return;
    }

    Polynom sumPoly = fPoly * sPoly;
    ui->result->setText(QString::fromStdString(sumPoly.to_string()));
}

void MainWindow::derivePolynom()
{
    QString fPolyS = ui->polyInput->text().trimmed();
    if (fPolyS.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все данные введены");
        return;
    }

    Polynom fPoly;
    try {
        fPoly = PolynomParser(fPolyS.toStdString()).parse();
    } catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат данных");
        return;
    }

    ui->result->setText(QString::fromStdString(fPoly.derive().to_string()));
}

void MainWindow::solvePolynomForX()
{
    QString fPolyS = ui->polyInput->text().trimmed();
    QString xInputS = ui->xInput->text().trimmed();
    if (fPolyS.isEmpty() || xInputS.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все данные введены");
        return;
    }

    bool flag;
    double xInput = xInputS.toDouble(&flag);
    if (!flag) {
        QMessageBox::critical(this, "Error", tr("'%1' не является числом!").arg(xInputS));
        return;
    }

    Polynom fPoly;
    try {
        fPoly = PolynomParser(fPolyS.toStdString()).parse();
    } catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", "Неправильный формат данных");
        return;
    }

    ui->result->setText(QString::number(fPoly.eval(xInput)));
}

void MainWindow::copyResult()
{
    QApplication::clipboard()->setText(ui->result->text().trimmed());
}

