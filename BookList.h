#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include "User.h"
#include "Book.h"
#include "UserList.h"

class BookList
{
    private:
        Book* books;
        int capacity;
        int booksCount;
    public:
        static int counter;
        static bool idexsist;
        BookList();//default constructor
        BookList(int capacity);//constructor
        BookList(const BookList& obj);//copy constructor
        void addBook(Book books);
        Book& searchBook(string name);
        Book& searchBook(int id);
        void setBookAuthor(User user, int index);
        void setBookName(string name, int index);
        void setBookCategory(string category, int index);
        void setBookRate(int rate, int index);
        void deleteBook(int id);//delete book
        Book getTheHighestRatedBook();
        Book* getBooksForUser(User user);
        Book & operator [ ] (int position);
        int get_booksCount();
        friend ostream &operator<<( ostream &output, BookList &booklist );
        ~BookList();//destructor
};

#endif // BOOKLIST_H_INCLUDED
