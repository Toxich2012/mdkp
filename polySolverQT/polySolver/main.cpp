#include "mainwindow.h"

#include <QApplication>

/**
 * @brief Основная точка входа в приложение
 * @param argc кол-во консольных параметров
 * @param argv консольные параметры
 * @return код выхода
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
