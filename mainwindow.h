#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include "include.h"
#include <QMessageBox>


namespace Ui {
    class MainWindow;
}
//наследуем от QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT //обязательный макрос для реализации слотов и сигналов

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//слоты - ждут своего сигнала - выполняют, что умеют
private slots:

    void on_pb00_01_clicked(); //клик "-" передаёт 99 в void click__on_pb(int num)
    void on_pb00_0_clicked(); //клик "0" передаёт 0 в void click__on_pb(int num)
    void on_pb00_1_clicked(); //клик "1" передаёт 1 в void click__on_pb(int num)
    void on_pb00_2_clicked(); //клик "2" передаёт 2 в void click__on_pb(int num)
    void on_pb00_3_clicked(); //клик "3" передаёт 3 в void click__on_pb(int num)
    void on_pb00_4_clicked(); //клик "4" передаёт 4 в void click__on_pb(int num)
    void on_pb00_5_clicked(); //клик "5" передаёт 5 в void click__on_pb(int num)
    void on_pb00_6_clicked(); //клик "6" передаёт 6 в void click__on_pb(int num)
    void on_pb00_7_clicked(); //клик "7" передаёт 7 в void click__on_pb(int num)
    void on_pb00_8_clicked(); //клик "8" передаёт 8 в void click__on_pb(int num)
    void on_pb00_9_clicked(); //клик "9" передаёт 9 в void click__on_pb(int num)

    //действие при клике на ячейку таблицы (запоминает строку + столбец, ещё выводит их в label)
    void on_table_cellClicked(int row, int column);
    //действие при клике кнопки решения (обнуление матрицы + её решение, вывод решения)
    void on_solve_clicked();
    //действие при нажатии на "Новая игра", сброс, генерация, вывод
    void on_actionNew_game_triggered();
    //действие при нажатии "Выход", закрытие приложения
    void on_actionExitQ_triggered();
    //действие при нажатии "Очистить всё", чистит поле, выводит начальное условие ("константы")
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //инты со значением актуальных столбца и строки
    int Column, Row;
    //клики на кнопки "0-9" + "-", запись их в матрицу
    void click__on_pb(int num);
};

#endif // MAINWINDOW_H

