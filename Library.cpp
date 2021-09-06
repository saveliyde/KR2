#include "Library.h"
#include "QMessageBox"

void Library::addBook(Book tmp){
    QMessageBox msgBox;
    Bookshelf->push_back(tmp);
}

int Library::getRecordsCount(){
    return Bookshelf->size();
}

Book Library::getBookByIndex(int index){
    return Bookshelf->at(index);
}

void Library::ChangeStockStatus(int index){
    Bookshelf->at(index).changeBookStockStatus();
}

void Library::sort() {
	string tmp = "";
	int r = 0;
    for (int i = 0; i < Bookshelf->size(); i++){
        for (int j = Bookshelf->size() - 1; j > r; j--){
            if (Bookshelf->at(j).getAuthor() < Bookshelf->at(j - 1).getAuthor()){
                swap(Bookshelf->at(j-1), Bookshelf->at(j));
			}
		}
		r++;
	}
}

void Library::BooksDeleting(int Year) {
    for (int i = Bookshelf->size() - 1; i >= 0 ; i--)
        if (Bookshelf->at(i).getYear() == Year)
            Bookshelf->erase(Bookshelf->begin()+i);
}

