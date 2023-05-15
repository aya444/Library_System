#include<iostream>
#include "User.h"
#include "Book.h"

using namespace std;

int Book::count=1;
int countrate = 0;
double accRate=0.0;

//constructors---------------------------------------------------------------------

/*
    Default Constructor used to initialize its the private attributes
    Initialize the strings with empty strings
*/
Book::Book()
{
    title="";
    isbn="";
    category="";
    averageRating=0;
    id=count;
}

/*
    Parameterized (title, isbn, category) Constructor
    (this) is a keyword that refers to the current instance of the class.
    (this) keyword was used because the name of the parameters is the same as the attributes
*/
Book::Book(string title, string isbn, string category)
{
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    this->averageRating=0;
    count++;
}

Book::Book(const Book&book)//Copy Constructor
{
    title=book.title;
    isbn=book.isbn;
    id=book.id;
    category= book.category;
    averageRating=book.averageRating;
    //count++;
    id=count;
}
//----------------------------------------------------------------------------------
//Getters---------------------------------------------------------------------------
string Book::getTitle()
{
    return title;
}
string Book::getISBN()
{
    return isbn;
}
int Book::getId()
{
    return id;
}
string Book::getCategory()
{
    return category;
}
User Book::getAuthor()
{
    return author;
}
int Book::getBookCount() const // Accessor function to count Books (added new member function)
{
    return count;
}
int Book::getRate()
{
    return averageRating;
}
//----------------------------------------------------------------------------------
//Setters---------------------------------------------------------------------------
void Book::setTitle(string title)
{
    this->title=title;
}
void Book::setISBN(string isbn)
{
    this->isbn=isbn;
}
void Book::setId(int id)
{
    this->id=id;
}
void Book::setCategory(string category)
{
    this->category=category;
}
void Book::setAuthor(User user)
{
    this->author=user;
}
void Book::rateBook(int rating)//Needed to take the ratings of the books properly and calculate it's average
{
    countrate++;
    accRate += rating;
    averageRating =accRate/countrate;
}

//---------------------------------------------------------------------------------
//Operator Overloading-------------------------------------------------------------

/*
    Bool To compare users
    The function returns whether the users are equal or not
*/
bool Book::operator==(const Book& book)
{
    return (title == book.title && isbn == book.isbn && id == book.id && category == book.category);
}
ostream& operator<<(ostream& output, const Book& book) //Function that returns the output Book's info.
{
    output<<"========Book "<<book.id<<" info ========"<<endl<<"Title: "<<book.title<<" | ISBN: "<<book.isbn<<" | ID: "<<book.id<<" | Category: "<<book.category<<" | Avg Rating: "<<book.averageRating<<endl;
    return output;
}
istream& operator>>(istream& input, Book& book) //Function that returns the input Book's info.
{
    input >> book.title >> book.isbn >> book.category;
    return input;
}
void Book::print( Book& book) //Function to print Book info. with its Authors info.
{
        cout<<book<<endl;
        cout<<book.getAuthor();
}

