#include <iostream>
#include "User.h"

using namespace std;

int User::count=1;

//CONSTRUCTORS---------------------------------------------------------------------

/*
    Default Constructor used to initialize its the private attributes
    Initialize the strings with empty strings
*/
User::User()
{
    //name="";
    //age=0;
    //email="";
    //password="";
    id = count;
    //count++;
}

/*
    Parameterized (name, age, email,password) Constructor
    (this) is a keyword that refers to the current instance of the class.
    (this) keyword was used because the name of the parameters is the same as the attributes
*/
User::User(string name, int age, string email, string password)
{
    this->name=name;
    this->age=age;
    this->email=email;
    this->password=password;
    count++;
}

User::User(const User&user) //Copy Constructor
{
    name=user.name;
    age=user.age;
    id=user.id;
    email=user.email;
    password= user.password;
    //count++;
}
//----------------------------------------------------------------------------------
//Getters---------------------------------------------------------------------------
string User::getName() const
{
    return name;
}
int User::getAge()
{
    return age;
}
int User::getId()
{
    return id;
}
string User::getPassword()
{
    return password;
}
string User::getEmail()
{
    return email;
}
int User::getUserCount() const // Accessor function to count Users (added new member function)
{
    return count;
}
//----------------------------------------------------------------------------------
//Setters---------------------------------------------------------------------------
void User::setName(string name)
{
    this->name=name;
}
void User::setAge(int age)
{
    this->age=age;
}
void User::setId(int id)
{
    this->id=id;
}
void User::setEmail(string email)
{
    this->email=email;
}
void User::setPassword(string password)
{
    this->password=password;
}
//---------------------------------------------------------------------------------
//Operator Overloading-------------------------------------------------------------

/*
    Bool To compare users
    The function returns whether the users are equal or not
*/
bool User::operator==(const User& user)
{
    return (name == user.name && age == user.age && id == user.id && email == user.email);
}

ostream& operator<<(ostream& output, const User& user) //Function that returns the output user's info.
{
    output<<"========User "<<user.id<<" info ========"<<endl<<"Name: "<<user.name<<endl<<"Age: "<<user.age<<endl<<"Id: "<<user.id<<endl<<"Email: "<<user.email<<endl<<"==============================="<<endl;
    return output;
}
istream& operator>>(istream& input, User& user)//Function that returns the input user's info.
{
    user.id = user.count;
    input >> user.name >> user.age >> user.email >> user.password;
    return input;
}

