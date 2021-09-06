#include "Book.h"
#include <vector>

using namespace std;

class Library {
    private:
        vector<Book> Bookshelf[1];
    public:
        Library():Bookshelf{}
        {}
        void sort();
        void ChangeStockStatus(int index);
        void BooksDeleting(int Year);
        void addBook(Book tmp);
        Book getBookByIndex(int index);
        int getRecordsCount();
};
