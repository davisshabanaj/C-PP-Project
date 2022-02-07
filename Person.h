#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Person{
    public:
        Person();
        void NewAccount();

        void ChangePassword();
        string GetUsername();
		string GetType();

        bool ConfirmUsername( string un );
        bool ConfirmPassword( string pw );

        virtual int Menu() = 0;

        friend ostream & operator<<( ostream & out, const Person & p );

    protected:
        string username;
        string password;
        string type;
};

Person::Person(){
    this->username = "NONE";
    this->password = "NONE";
    return;
}

void Person::NewAccount(){
    cout << "Username: ";
    cin >> this->username;
    cout << "Password: ";
    cin >> this->password;
    return;
}

bool Person::ConfirmUsername( string un ){
    if( un == this->username ){
        return true;
    }
    return false;
}

bool Person::ConfirmPassword( string pw ){
    if( pw == this->password ){
        return true;
    }
    return false;
}

void Person::ChangePassword(){
    string tmp;
    cout << "Old password: ";
    cin >> tmp;

    if( this->ConfirmPassword( tmp ) ){
        cout << "New password: ";
        cin >> this->password;
    }
    else{
        cout << "Invalid password." << endl;
    }

    return;
}

string Person::GetUsername(){
    return this->username;
}

string Person::GetType(){
    return this->type;
}

ostream & operator<<( ostream & out, const Person & p ){
    out << setw(10) << p.type << " " << p.username;
    return out;
}

#endif