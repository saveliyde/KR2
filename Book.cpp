#include "Book.h"

string Book::getAuthor(){
    return Author;
}

string Book::getName(){
    return Name;
}

int Book::getYear(){
    return Year;
}

int Book::getInvNumber(){
    return InvNumber;
}

int Book::getPages(){
    return Pages;
}

int Book::getPrice(){
    return Price;
}

int Book::getInStock(){
    return InStock;
}

void Book::changeBookStockStatus(){
    if (InStock == 1)
        InStock = 0;
}
