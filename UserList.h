#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include "User.h"


using namespace std;

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount=0;

public:
    static bool idexsist;   //check if id already exist
    static int users_counter; //dynamic array of type User, it includes all the users.
    UserList();   //default constructor
    UserList(int capacity); //constructor
    UserList(const UserList& obj);//copy constructor
    void addUser(User user);    // at the end of the array.
    User& searchUser(string name);
    User& searchUser(int id);
    void deleteUser(int id);
    int getUsersCount();//accessor added
    friend ostream &operator<<( ostream &output, UserList &userList );   //to display all books
    ~UserList();
    };

#endif // USERLIST_H_INCLUDED
