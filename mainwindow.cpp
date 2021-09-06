#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Book.h"
#include "Library.h"
#include "QMessageBox"
#include "QString"
#include "QLineEdit"
#include "string"

Library Shelf;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Автор"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Инвентарный номер"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Год издания"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Количество страниц"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Цена"));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Наличие"));
    ui->tableWidget->resizeColumnsToContents();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_addBookButton_clicked(){
    Book tmp(ui->AuthorEdit->text().toStdString(), ui->NameEdit->text().toStdString(), ui->InvNumEdit->text().toInt(), ui->YearEdit->text().toInt(),
                                                     ui->PagesEdit->text().toInt(), ui->PriceEdit->text().toInt(), ui->InStockEdit->text().toInt());
    Shelf.addBook(tmp);
    int r = Shelf.getRecordsCount();
    bookDisplay(r-1, tmp);
    clearEdits();

}

void MainWindow::on_changeStockStatusButton_clicked(){
    QTableWidgetItem *tmp = ui->tableWidget->currentItem();
    int CurrentRowIndex = tmp->row();
    Shelf.ChangeStockStatus(CurrentRowIndex);
    shelfDisplay();
}

void MainWindow::on_sortBooksButton_clicked(){
    Shelf.sort();
    shelfDisplay();
}

void MainWindow::on_eraseBooksButton_clicked()
{
    Shelf.BooksDeleting(ui->YearEdit->text().toInt());
    shelfDisplay();
    clearEdits();
}

void MainWindow::shelfDisplay(){
    ui->tableWidget->setRowCount(0);
    Book tmp;
    for(int i = 0; i < Shelf.getRecordsCount(); i++){
        tmp = Shelf.getBookByIndex(i);
        bookDisplay(i, tmp);
    }
}

void MainWindow::bookDisplay(int index, Book someBook){
    ui->tableWidget->setRowCount(index + 1);
    ui->tableWidget->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(someBook.getAuthor())));
    ui->tableWidget->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(someBook.getName())));
    ui->tableWidget->setItem(index, 2, new QTableWidgetItem(QString::number(someBook.getInvNumber())));
    ui->tableWidget->setItem(index, 3, new QTableWidgetItem(QString::number(someBook.getYear())));
    ui->tableWidget->setItem(index, 4, new QTableWidgetItem(QString::number(someBook.getPages())));
    ui->tableWidget->setItem(index, 5, new QTableWidgetItem(QString::number(someBook.getPrice())));
    ui->tableWidget->setItem(index, 6, new QTableWidgetItem(QString::number(someBook.getInStock())));
}

void MainWindow::clearEdits(){
    ui->NameEdit->clear();
    ui->AuthorEdit->clear();
    ui->InvNumEdit->clear();
    ui->YearEdit->clear();
    ui->PagesEdit->clear();
    ui->PriceEdit->clear();
    ui->InStockEdit->clear();
}
