#ifndef BOOK_H
#define BOOK_H
#include "User.h"

using namespace std;

class Book
{
    private:
         string title; // Attributes
         string isbn;
         int id;
         string category;
         double averageRating;
         User author; // Aggregation
    public:
         static int count; // Static counter
         Book(); //Default constructor
         Book(string title, string isbn, string category); //Parametrized Constructor
         Book(const Book& book); //Copy Constructor
         void setTitle(string title);
         string getTitle();
         void setISBN(string isbn);
         string getISBN();
         void setId(int id);
         int getId();
         void setCategory(string category);
         string getCategory();
         void setAuthor(User user); //Aggregation
         User getAuthor(); //Aggregation
         int getRate();
         void rateBook(int rating);
         bool operator==(const Book& book); //Overloading Operator ==
         friend ostream &operator<<(ostream &output, const Book &book ); //Overloading Operator <<
         friend istream &operator>>( istream &input, Book &book ); //Overloading Operator >>
         int getBookCount() const; //Accessor function to count Books (added new member function)
         void print( Book& book); //Function to print Book info. with its Authors info.
};

#endif // BOOK_H
