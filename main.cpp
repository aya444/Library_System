/*This is an online library program that includes the following classes:
-User   -Book  -UserList  -BookList
The program first shows a main menu from which the user chooses to go to Books menu or Users menu or exit.
------------------------------------------------------------------------------------------------------*/
#include<cstring>
#include<iostream>
#include <string>
#include "UserList.h"
#include "UserList.cpp"
#include "BookList.h"
#include "BookList.cpp"

using namespace std;

int main()
{
    BookList b;
    UserList u;
    bool idexsist=0;
    int Num,cap;
    int Choice, choice1B,choice2B,choice3B,choice4B,choice5B;
    int choice1U;

    do//loop printing out this main menu till the user chooses to exit
    {
        cout<<"Select one of the following choices:"<<endl;
        cout<<"1- Books Menu"<<endl;
        cout<<"2- Users Menu"<<endl;
        cout<<"3- Exit"<<endl;
        cin>>Choice;

        switch(Choice)
        {
        case 1:
            {
                cout<<"How many books will be added"<<endl;
                cin>>Num;
                BookList bookM(Num);
                b=bookM;

                do//loop printing out this book menu till the user chooses to exit back to main menu
                {
                    cout<<"Book List Menu"<<endl;
                    cout<<"1- Create a book & add it to the list"<<endl<<"2- Search for a book"<<endl;
                    cout<<"3- Display all books (with book rating)"<<endl<<"4- Get the highest rating book"<<endl;
                    cout<<"5- Get all books of a user"<<endl<<"6- copy the current Book List to a new book list & switch to it"<<endl;
                    cout<<"7-Back to the main menu"<<endl;
                    cin>>choice1B;
                    int index;

                    switch(choice1B)
                    {
                    case 1:
                        {
                            int C;
                            Book b1;
                            cout<<"Enter the book information in this order"<<endl;
                            cout<<"Title   ISBN   Category(Space separated)"<<endl;
                            cin>>b1;
                            cout<<"1- Assign author"<<endl<<"2- continue"<<endl;
                            cin>>C;
                            switch(C)
                            {
                            case 1:
                                {
                                    cout<<"Enter Author (user) id"<<endl;
                                    int AuthorID ;
                                    cin>>AuthorID;
                                    User author = u.searchUser(AuthorID);
                                    b1.setAuthor(author);
                                    if(u.idexsist == 1)
                                    {
                                        b1.setAuthor(author);
                                    }
                                    break;
                                }
                            case 2:
                                {
                                    continue;
                                }
                            }
                            bookM.addBook(b1);
                            break;
                        }
                    case 2:
                        {
                            int S,K;
                            do//loop printing out this book menu till the user chooses to exit back to book menu
                            {
                                cout<<"1-search by name"<<endl<<"2-search by id"<<endl;
                                cout<<"3-Return to Books menu"<<endl;
                                cin>>S;

                                switch (S)
                                {
                                case 1:
                                    {
                                        cout<<"Enter name:"<<endl;
                                        string title;
                                        cin>>title;
                                        Book want;
                                        want= bookM.searchBook(title);
                                        index = bookM.searchBook(title).getId();
                                        if(bookM.idexsist == 1)
                                        {
                                             cout<<want;
                                             cout<<"1- Update Author"<<endl<<"2- Update name"<<endl;
                                             cout<<"3- Update Category"<<endl<<"4- Delete book"<<endl;
                                             cout<<"5-Rate book"<<endl<<"6-Get back to books menu"<<endl;
                                             cin>>K;

                                             switch(K)
                                             {
                                             case 1:
                                                 {
                                                    int IDauthor;
                                                    cout<<"Enter Author (user) id"<<endl;
                                                    cin>>IDauthor;
                                                    User author = u.searchUser(IDauthor);
                                                    if(u.idexsist==1)
                                                    {
                                                        bookM.setBookAuthor(author, index);
                                                    }
                                                     break;
                                                 }
                                             case 2:
                                                 {
                                                     string name;
                                                     cout<<"Enter the new name"<<endl;
                                                     cin>>name;
                                                     bookM.setBookName(name,index);
                                                     break;
                                                 }
                                             case 3:
                                                 {
                                                    string catg;
                                                    cout<<"Enter the new category "<<endl;
                                                    cin>>catg;
                                                    bookM.setBookName(catg, index);
                                                     break;
                                                 }
                                             case 4:
                                                 {
                                                    int IDbook;
                                                    cout<<"Enter book id "<<endl;
                                                    cin>>IDbook;
                                                    bookM.deleteBook(IDbook);
                                                    break;
                                                 }
                                             case 5:
                                                 {
                                                    int rate;
                                                    cout<<"Enter rate"<<endl;
                                                    cin>>rate;
                                                    bookM.setBookRate(rate, index);
                                                     break;
                                                 }
                                             case 6:
                                                 {
                                                     break;
                                                 }
                                             }

                                        }
                                        break;
                                    }
                                case 2:
                                    {
                                        int id;
                                        cout<<"Enter id" << endl;
                                        cin>>id;
                                        Book want;
                                        want=bookM.searchBook(id);
                                        index=bookM.searchBook(id).getId();
                                        if(bookM.idexsist == 1)
                                        {
                                            cout << want;
                                             cout<<"1- Update Author"<<endl<<"2- Update name"<<endl;
                                             cout<<"3- Update Category"<<endl<<"4- Delete book"<<endl;
                                             cout<<"5-Rate book"<<endl<<"6-Get back to books menu"<<endl;
                                             cin>>K;

                                             switch(K)
                                             {
                                             case 1:
                                                 {
                                                    int IDauthor;
                                                    cout<<"Enter Author (user) id"<<endl;
                                                    cin>>IDauthor;
                                                    User author = u.searchUser(IDauthor);
                                                    if(u.idexsist==1)
                                                    {
                                                        bookM.setBookAuthor(author, index);
                                                    }
                                                     break;
                                                 }
                                             case 2:
                                                 {
                                                     string name;
                                                     cout<<"Enter the new name"<<endl;
                                                     cin>>name;
                                                     bookM.setBookName(name,index);
                                                     break;
                                                 }
                                             case 3:
                                                 {
                                                    string catg;
                                                    cout<<"Enter the new category "<<endl;
                                                    cin>>catg;
                                                    bookM.setBookName(catg, index);
                                                     break;
                                                 }
                                             case 4:
                                                 {
                                                    int IDbook;
                                                    cout<<"Enter book id "<<endl;
                                                    cin>>IDbook;
                                                    bookM.deleteBook(IDbook);
                                                    break;
                                                 }
                                             case 5:
                                                 {
                                                    int rate;
                                                    cout<<"Enter rate"<<endl;
                                                    cin>>rate;
                                                    bookM.setBookRate(rate, index);
                                                     break;
                                                 }
                                             case 6:
                                                 {
                                                     break;
                                                 }
                                             }

                                        }

                                        break;
                                    }
                                case 3:
                                    {
                                        break;
                                    }
                               }
                             }
                              while(S!=3);
                              break;
                        }
                    case 3:
                        {
                            cout<<bookM;
                            break;
                        }
                    case 4:
                        {
                            bookM.getTheHighestRatedBook();
                            break;
                        }
                    case 5:
                        {
                            int id;
                            cout<<"Enter ID"<<endl;
                            cin>>id;
                            bookM.getBooksForUser(u.searchUser(id));
                            break;
                        }
                    case 6:
                        {
                            b=bookM;
                            break;
                        }
                    case 7:
                        {
                            break;
                        }
                    }

                }while(choice1B!=7);
                break;
            }

        case 2:
            {
                cout<<"How many users will be added"<<endl;
                cin>>cap;
                UserList userM(cap);
                u=userM;
               do//loop printing out this user menu till the user chooses to exit back to main menu
                {
                   cout<<"USERS MENU"<<endl;
                   cout<<"1- Create a user and add it to the list"<<endl;
                   cout<<"2- Search for a user"<<endl;
                   cout<<"3- Display all users"<<endl;
                   cout<<"4- Back to the main menu"<<endl;
                   cin>>choice1U;

                    switch(choice1U)
                    {
                    case 1:
                        {
                          User u1;
                            cout<<"Enter the user information in this order"<<endl;
                            cout<<"Name age Email Password (Space separated)"<<endl;
                            cin>>u1;
                            userM.addUser(u1);
                            break;
                        }
                    case 2:
                        {
                            int D,E;
                            do//loop printing out this  menu till the user chooses to exit back to users menu
                            {
                                User Find;
                                cout<<"Search for a user"<<endl<<"1- Search by name"<<endl;
                                cout<<"2- Search by ID"<<endl<<"3- Return to Users Menu"<<endl;
                                cin>>D;
                                switch(D)
                                {
                                case 1:
                                    {
                                        string name;
                                        cout<<"Enter Name"<<endl;
                                        cin>>name;
                                        Find=userM.searchUser(name);
                                        if(userM.idexsist==1)
                                        {
                                           cout<<Find;
                                           cout<<"1- Delete user"<<endl<<"2- Return to the Users Menu"<<endl;
                                           cin>>E;
                                           switch(E)
                                            {
                                            case 1:
                                                {
                                                    userM.deleteUser(Find.getId());
                                                    break;
                                                }
                                            case 2:
                                                {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                case 2:
                                    {
                                        int id,H;
                                        cout<<"Enter ID"<<endl;
                                        cin>>id;
                                        Find=userM.searchUser(id);
                                        if(userM.idexsist==1)
                                        {
                                            cout<<Find;
                                            cout<<"1- Delete user"<<endl<<"2- Return to the Users Menu"<<endl;
                                            cin>>H;
                                            switch(H)
                                            {
                                            case 1:
                                                {
                                                    userM.deleteUser(Find.getId());
                                                    break;
                                                }
                                            case 2:
                                                {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                }
                            }while(D!=3);
                            break;
                        }
                    case 3:
                        {
                            cout<<userM<<endl;
                            break;
                        }
                    case 4:
                        {
                            break;
                        }

                    }

                }while(choice1U!=4);
                u=userM;
                break;
            }

        }
    }while (Choice !=3);

    return 0;

}



