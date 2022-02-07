#ifndef PRESENTER_H
#define PRESENTER_H

#include "Person.h"
#include "Session.h"
#include <vector> 

using namespace std;

class Presenter: public Person{
    public:
        Presenter();
        void SetSession( Session * s );
        int Menu() override;
        
    private:
        Session * session;
};

Presenter::Presenter(){
    this->type = "presenter";
    return;
}

void Presenter::SetSession( Session * s ){
    this->session = s;
}

int Presenter::Menu(){
    for( int i = 0; i < 10; i++ ){
        cout << endl;
    }

    int option;
    cout << endl << endl << "Menu:\n   1. View session information\n   2. Change password\n   0. Exit\n\nDesired option: ";
    cin >> option;

    if( option == 1 ){
        cout << "****** Session information ******" << endl;
        cout << *(this->session) << endl << endl;
    }
    else if( option == 2 ){
        this->ChangePassword();
    }
    return option;
}

#endif