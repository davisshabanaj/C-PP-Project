#ifndef JUDGE_H
#define JUDGE_H

#include "Person.h"
#include "Database.h"
#include "Session.h"

using namespace std;

class Judge: public Person{
    public:
        Judge();
        int Menu() override;
        void SetDatabase( Database * d );

        void GetSession();
        void JudgeSession();
        
    private:
        Database * data;
        Session * session;
};

Judge::Judge(){
    type = "judge";
    return;
}

int Judge::Menu(){
    for( int i = 0; i < 10; i++ ){
        cout << endl;
    }

    int option;
    cout << endl << endl << "Menu:\n   1. Judge session\n   2. Print scores\n   3. Change password\n   0. Exit\n\nDesired option: ";
    cin >> option;

    if( option == 1 ){
        this->GetSession();
		if( this->session != NULL ){
            cout << "****** Session ******" << endl;
            cout << *this->session << endl << endl;
			this->JudgeSession();
		}
        else{
            cout << "No sessions to assign" << endl;
        }
    }
    else if( option == 2 ){
        this->data->PrintScores( this->username );
    }
    else if( option == 3 ){
        this->ChangePassword();
    }

    return option;
}

void Judge::SetDatabase( Database * d ){
    this->data = d;
    return;
}

void Judge::GetSession(){
    this->session = this->data->GetSession();
    return;
}

void Judge::JudgeSession(){
    this->session->AddRubricScores( this->username );
    return;
}

#endif