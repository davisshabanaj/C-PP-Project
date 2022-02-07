#ifndef EVENT_H
#define EVENT_H

#include "Database.h"
#include "Presenter.h"
#include "Admin.h"
#include "Judge.h"
#include "Session.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Event{
    public:
        Event();
        
        void SetDatabase( Database * d );

        int MainMenu();
        void Login();
        void Register();

        void RegisterPresenter();
        void RegisterJudge();

    private:
        Database * data;
        string name;
        Admin administrator;
};

Event::Event(){
    for( int i = 0; i < 10; i++ ){
        cout << endl;
    }

    cout << "****** New Event ******" << endl;
    cout << "Enter in the credentials for the Event administrator." << endl;
    this->administrator.NewAccount();

    cout << "Name of event: ";
    cin.ignore(256,'\n');
    getline( cin, this->name );

    return;
}

void Event::SetDatabase( Database * d ){
    this->data = d;
    if( this->administrator.GetUsername() != "None" ){
        this->data->AddPerson( &(this->administrator) );
    }
    this->administrator.SetDatabase( d );
    return;
}

int Event::MainMenu(){
    for( int i = 0; i < 10; i++ ){
        cout << endl;
    }
    
    cout << "*****************************" << endl;
    cout << "Welcome to " << this->name << endl;
    int option;
    cout << " 1. Login\n 2. Register\n 0. Exit\n\nDesired option: ";
    cin >> option;

    if( option == 1 ){
        this->Login();
    }
    else if( option == 2 ){
        this->Register();
    }
    return option;
}

void Event::Login(){

    cout << "Logging in: " << endl;

    string un, pw;
    cout << "Username: ";
    cin >> un;
    cout << "Password: ";
    cin >> pw;

    Person * p = this->data->FindUser( un, pw );

    if( p == NULL ){
        cout << endl << "User not found." << endl;
        return;
    }
    else{
        while( p->Menu() > 0 ){}
    }

    return;
}

void Event::Register(){
    int type;
    cout << "   1. Presenter\n   2. Judge\n\nDesired option: ";
    cin >> type;

    if( type == 1 ){
        this->RegisterPresenter();
    }
    else if( type == 2 ){
        this->RegisterJudge();
    }
    return;
}

void Event::RegisterPresenter(){
    Presenter * presenter = new Presenter;
    presenter->NewAccount();

    if( this->data->UserExists( presenter->GetUsername() ) ){
        cout << "Username invalid" << endl;
        delete presenter;
        return;
    }
    
    Session * session = new Session;
    session->InputInformation();

    presenter->SetSession( session );

    this->data->AddPerson( presenter );
    this->data->AddSession( session );
    return;
}

void Event::RegisterJudge(){
    Judge * judge = new Judge;
    judge->NewAccount();

    if( this->data->UserExists( judge->GetUsername() ) ){
        cout << "Username invalid" << endl;
        delete judge;
        return;
    }

    judge->SetDatabase( this->data );

    this->data->AddPerson( judge );
    return;
}

#endif