#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include<cstring>
#include <string>
#include<iostream>

using namespace std;

class User
{
    private: //Attributes
        string name;
        int age;
        int id;
        string password;
        string email;
    public:
        static int count; //Static counter
        User(); //Default Constructor
        User(string name, int age, string email, string password); //Parametrized Constructor
        User(const User&user); //Copy Constructor
        bool operator==(const User& user); //Overloading operator ==
        void setName(string name);
        string getName() const;
        void setPassword(string password);
        string getPassword();
        void setEmail(string email);
        string getEmail();
        void setAge(int age);
        int getAge();
        void setId(int id);
        int getId();
        friend ostream &operator<<(ostream &output, const User &user ); //Overloading Operator <<
        friend istream &operator>>( istream &input, User &user ); //Overloading Operator >>
        int getUserCount() const; // Accessor function to count Users (added new member function)
};

#endif // USER_H
