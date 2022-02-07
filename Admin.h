#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Database.h"
#include <string> 
#include <vector> 

using namespace std;

class Admin: public Person{
    public:
        Admin();
        int Menu() override;
        void SetDatabase( Database * d );
        
    private:
        Database * data;
};

Admin::Admin(){
    type = "admin";
    return;
}

void Admin::SetDatabase( Database * d ){
    this->data = d;
    return;
}

int Admin::Menu(){
    for( int i = 0; i < 10; i++ ){
        cout << endl;
    }

    int option;
    cout << endl << endl << "Menu:\n   1. View registrants\n   2. View presentations\n   3. View results\n   4. Print database\n   5. Change password\n   0. Exit\n\nDesired option: ";
    cin >> option;

    if( option == 1 ){
        this->data->PrintRegistrations();
    }
    else if( option == 2 ){
        this->data->PrintSessions();
    }
    else if( option == 3 ){
        this->data->PrintScores();
    }
    else if( option == 4 ){
        string filename;
        cout << "Enter in the filename: ";
        cin >> filename;

        this->data->ToFile( filename );
    }
    else if( option == 5 ){
        this->ChangePassword();
    }

    return option;
}

#endif