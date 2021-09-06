#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Book.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBookButton_clicked();

    void on_sortBooksButton_clicked();

    void shelfDisplay();

    void bookDisplay(int index, Book someBook);

    void on_changeStockStatusButton_clicked();

    void on_eraseBooksButton_clicked();

    void clearEdits();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
