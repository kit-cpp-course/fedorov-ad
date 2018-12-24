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

void MainWindow::on_table_cellClicked(int row, int column)
{
    Row = row;

    Column = column;

    QString str = "";
    str += '0' + row;
    str += ',';
    str += '0' + column;

    const QString cstr = str;
    ui->label->setText(cstr);
}

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

void MainWindow::on_pb00_01_clicked()
{
   click__on_pb(99);
}

void MainWindow::on_pb00_0_clicked()
{
   click__on_pb(0);
}

void MainWindow::on_pb00_1_clicked()
{
   click__on_pb(1);
}

void MainWindow::on_pb00_2_clicked()
{
    click__on_pb(2);
}

void MainWindow::on_pb00_3_clicked()
{
    click__on_pb(3);
}

void MainWindow::on_pb00_4_clicked()
{
    click__on_pb(4);
}

void MainWindow::on_pb00_5_clicked()
{
    click__on_pb(5);
}

void MainWindow::on_pb00_6_clicked()
{
    click__on_pb(6);
}

void MainWindow::on_pb00_7_clicked()
{
    click__on_pb(7);
}

void MainWindow::on_pb00_8_clicked()
{
    click__on_pb(8);
}

void MainWindow::on_pb00_9_clicked()
{
    click__on_pb(9);
}

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



void MainWindow::on_actionExitQ_triggered()
{
    QApplication::quit();
}

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
