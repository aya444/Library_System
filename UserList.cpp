#include<iostream>
#include "User.h"
#include "User.cpp"
#include "UserList.h"


using namespace std;

bool UserList::idexsist=0;
int UserList::users_counter=0;

//Constructors===============================================
UserList::UserList()
{
    capacity=0;
    usersCount=0;
}

UserList::UserList(int capacity)
{
    this->capacity=capacity;
    users=new User[capacity];
}

UserList::UserList(const UserList& obj)
{
    capacity=obj.capacity;
    for(int i=0;i<obj.usersCount;i++)
    {
        users[i]=obj.users[i];
    }
    users_counter=obj.users_counter;

}

//Methods===============================================
void UserList::addUser(User user)//add user
{
     users[usersCount]=user;
     usersCount++;
     User::count++;
     users_counter++;
}

User& UserList::searchUser(string name)//search user by name
{
    idexsist=0;
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getName()==name)
        {
          idexsist=1;
          return users[i];
        }
    }
    cout<<"No user with name "<<name<<endl;
    return users[0];
}

User& UserList::searchUser(int id)//search user by id
{
    idexsist=0;
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId()==id)
        {
            idexsist=1;
            return users[i];
        }
    }
    cout<<"No user with ID: "<<id<<endl;
    return users[0];
}

void UserList :: deleteUser(int id)//delete user
{
    for(int i=0; i<usersCount; i++)
    {
      if(users[i].getId()==id)
        {
            users_counter--;
          for(int j=i; j<users_counter;j++)
          {
              delete(users+j);
              users[j]= users[j+1];
          }

        }
    }
}

int UserList::getUsersCount()//acessor
{
    return usersCount;
}

ostream& operator<<( ostream &output, UserList &userList )//a friend function of the UseList class, it print all users.
{
    for (int i=0; i<userList.users_counter;i++)
    {
        output<<userList.users[i]<<endl;
    }
    return output;
}

UserList::~UserList()//destructor
{
    delete[]users;
}
