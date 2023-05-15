#include <string>
#include<cstring>
#include<iostream>
#include "User.h"
#include "Book.h"
#include "Book.cpp"
#include "BookList.h"

using namespace std;
int BookList::counter=0;
bool BookList::idexsist;
int MaxRate=0;

//Constructors===============================================
BookList::BookList()
{
    capacity=0;
    booksCount=0;
}

BookList::BookList(int capacity)
{
    this->capacity=capacity;
    books=new Book[capacity];

    //counter++;
}

BookList::BookList(const BookList& obj)
{
    capacity=obj.capacity;
    for(int i=0;i<obj.booksCount;i++)
    {
        books[i]=obj.books[i];
    }
    counter=obj.counter;
}

//Setters===============================================
void BookList::setBookAuthor(User user, int index)
{
     for(int i=0; i<idexsist; i++)
    {
        if(books[i].getId() == index)
        {
          books[i].getAuthor() = user;
        }
    }
}
void BookList::setBookName(string name,int index)
{
    for(int i=0;i<idexsist; i++)
    {
        if(books[i].getId() == index)
        {
          books[i].getTitle() = name;
        }
    }
}
void BookList::setBookCategory(string catg, int index)
{
    for(int i=0; i<idexsist; i++)
    {
        if(books[i].getId() == index)
        {
          books[i].getCategory()=catg;
        }
    }
}
void BookList::setBookRate(int rate,int index)
{
     for(int i=0; i<idexsist; i++)
    {
        if(books[i].getId() == index)
        {
          books[i].rateBook(rate);
        }
    }
}

//Methods===============================================
void BookList::addBook(Book book)//add book
{
     books[booksCount]=book;
     booksCount++;
     book.count++;
     counter++;
}

Book& BookList::searchBook(string name)//search book by name
{
    idexsist=0;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getTitle()==name)
        {
          idexsist=1;
          return books[i];
        }
    }
    cout<<"No book with name "<<name<<endl;
    return books[0];
}

Book& BookList::searchBook(int id)//search book by id
{
    idexsist=0;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getId()==id)
        {
          idexsist=1;
          return books[i];
        }
    }
    cout<<"No book with name "<<id<<endl;
    return books[0];
}

void BookList::deleteBook(int id)//delete
{
    for(int i=0; i<booksCount; i++)
    {
      if(books[i].getId()==id)
        {
          counter--;
          for(int j=i; j<booksCount;j++)
          {
              delete(books+j); //test
              books[j]= books[j+1];
          }

        }
    }
}

Book BookList::getTheHighestRatedBook()//get The Highest Rated Book
{
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].getRate() > MaxRate)
            MaxRate = books[i].getRate();
    }
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].getRate() == MaxRate)
            return books[i];
    }
}

Book* BookList::getBooksForUser(User user) // get all books of this author
{
    for(int i=0;i< booksCount; i++)
    {
        if(books[i].getAuthor() == user)
            cout << books[i];

    }
    return books;
}

Book & BookList::operator[ ](int position)
{
    for(int i=0;i< booksCount; i++)
    {
        return books[position];
    }
}

int BookList::get_booksCount()//acessor
{
    return booksCount;
}

 ostream &operator<<( ostream &output, BookList &bookList ) //a friend function of the UseList class, it print all users.
{
    for (int i=0; i<bookList.counter;i++)
    {
        output<<bookList.books[i]<<endl;
    }
    return output;
}

BookList::~BookList()//destructor
{
    delete[]books;
}
