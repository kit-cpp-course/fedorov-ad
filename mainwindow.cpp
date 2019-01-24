#include "mainwindow.h"
#include "ui_mainwindow.h"



sudoku::matrix matx;


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    matx.new_puzzle();

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);

            QString str = "";
            str += '0' + matx.read(i, j);
            if (str=='0')
            {
                str = '-';
            }
            const QString cstr = str;

            Cell->setText(cstr);

            if (matx.read(i, j))
            {
                QColor c(220,220,220);
                Cell->setBackgroundColor(c);
            }
        }
    }
    ui->label->setText("SudokuTry v.1.2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//действие при клике на ячейку таблицы
void MainWindow::on_table_cellClicked(int row, int column)
{
    Row = row;

    Column = column;

    QString str = "";
    str += '1' + row;
    str += ',';
    str += '1' + column;

    const QString cstr = str;
    ui->label->setText(cstr);
}

//клики на кнопки с цифрами от 0 до 9 и "-"
void MainWindow::click__on_pb(int num)
{
    QTableWidgetItem* Cell = ui->table->item(Row, Column);

    matx.write(Row, Column, num);

    QString str = "";
    str += '0' + matx.read(Row, Column);
    if(num == 99)
    {
        str = '-';
    }
    const QString cstr = str;
    Cell->setText(cstr);

    //сражу же проверим на выигрышность и выведем соответствующие сообщения
    if (matx.you_win())
    {
        ui->label->setText("Победа!");
        QMessageBox msgBox;
        msgBox.setText("Congratulations! You won!");
        msgBox.setInformativeText("Нажмите OK, чтобы начать новую игру");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int res = msgBox.exec();
        if (res == QMessageBox::Ok) //нажата кнопка Ok
               MainWindow::on_actionNew_game_triggered();
    }
}

//клик на кнопку "-"
void MainWindow::on_pb00_01_clicked()
{
   click__on_pb(99);
}
//клик на кнопку "0"
void MainWindow::on_pb00_0_clicked()
{
   click__on_pb(0);
}
//клик на кнопку "1"
void MainWindow::on_pb00_1_clicked()
{
   click__on_pb(1);
}
//клик на кнопку "2"
void MainWindow::on_pb00_2_clicked()
{
    click__on_pb(2);
}
//клик на кнопку "3"
void MainWindow::on_pb00_3_clicked()
{
    click__on_pb(3);
}
//клик на кнопку "4"
void MainWindow::on_pb00_4_clicked()
{
    click__on_pb(4);
}
//клик на кнопку "5"
void MainWindow::on_pb00_5_clicked()
{
    click__on_pb(5);
}
//клик на кнопку "6"
void MainWindow::on_pb00_6_clicked()
{
    click__on_pb(6);
}
//клик на кнопку "7"
void MainWindow::on_pb00_7_clicked()
{
    click__on_pb(7);
}
//клик на кнопку "8"
void MainWindow::on_pb00_8_clicked()
{
    click__on_pb(8);
}
//клик на кнопку "9"
void MainWindow::on_pb00_9_clicked()
{
    click__on_pb(9);
}

//клик на кнопку "Solve It!"
void MainWindow::on_solve_clicked()

{
    matx.reset();

    matx.solve();

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";

            str += '0' + matx.read(i,j);

            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}


//триггер на выход
void MainWindow::on_actionExitQ_triggered()
{
    QApplication::quit();
}
//триггер на новую игру
void MainWindow::on_actionNew_game_triggered()

{
    matx.new_puzzle();

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";

            str += '0' + matx.read(i, j);
            if (str=='0')
            {
                str = '-';
            }

            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(220,220,220);
                Cell->setBackgroundColor(c);
            }

            else
            {
                QColor c(255,255,255);
                Cell->setBackgroundColor(c);
            }
        }
    }
}

//клик на кнопку "Очистить всё"
void MainWindow::on_pushButton_clicked()
{
    matx.reset();

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            if (str=='0')
            {
                str = '-';
            }
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}
