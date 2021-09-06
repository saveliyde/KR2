#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book {
    private:
        string Author;
        string Name;
        int Year;
        int InvNumber;
        int Pages;
        int Price;
        int InStock;
    public: 
        Book(string someAuthor = "", string someName = "", int someInvNumber = 0, int someYear = 0,
             int somePages = 0, int somePrice = 0, bool stockInfo = false):Author(someAuthor), Name(someName), Year(someYear),
            InvNumber(someInvNumber), Pages(somePages), Price(somePrice), InStock(stockInfo)
        {}
        string getAuthor();
        string getName();
        int getYear();
        int getInvNumber();
        int getPrice();
        int getPages();
        int getInStock();
        void changeBookStockStatus();
};

#endif
