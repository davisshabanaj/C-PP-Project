#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"
#include <vector>
#include "Session.h"
#include <fstream>
#include <string>

using namespace std;

class Database{
    public:
        ~Database();

        void AddPerson( Person * p );
        void AddSession( Session * s );

        Person * FindUser( string un, string pw );
        bool UserExists( string un );

        void PrintRegistrations();
        void PrintSessions();
        void PrintScores();
		void PrintScores( string jn );

        Session * GetSession();

        void ToFile( string filename );

    private:
        vector<Person *> people;
        vector<Session *> sessions;
};

Database::~Database(){
    for( int i = 1; i < this->people.size(); i++ ){
		delete this->people.at(i);
    }
    for( int i = 0; i < this->sessions.size(); i++ ){
        delete this->sessions.at(i);
    }
    return;
}

void Database::AddPerson( Person * p ){
    this->people.push_back( p );
    return;
}

void Database::AddSession( Session * s ){
    this->sessions.push_back( s );
    return;
}

Person * Database::FindUser( string un, string pw ){
    Person * p = NULL;
    for( int i = 0; i < this->people.size(); i++ ){
        if( this->people.at(i)->ConfirmUsername( un ) ){
            if( this->people.at(i)->ConfirmPassword( pw ) ){
                p = this->people.at(i);
                break;
            }
        }
    }
    return p;
}

bool Database::UserExists( string un ){
    Person * p = NULL;
    for( int i = 0; i < this->people.size(); i++ ){
        if( this->people.at(i)->ConfirmUsername( un ) ){
            return true;
        }
    }
    return false;
}

void Database::PrintRegistrations(){
    cout << endl << endl << "****** Registrations ******" << endl;
    for( int i = 0; i < this->people.size(); i++ ){
        cout << *(this->people.at(i)) << endl;
    }
    cout << endl;
    return;
}

void Database::PrintSessions(){
    cout << endl << endl << "****** Sessions ******" << endl << endl;
    for( int i = 0; i < this->sessions.size(); i++ ){
        cout << *(this->sessions.at(i)) << endl << endl;
    }
    cout << endl;
    return;
}

void Database::PrintScores(){
    cout << endl << endl << "****** Scores ******" << endl << endl;
    for( int i = 0; i < this->sessions.size(); i++ ){
        this->sessions.at(i)->PrintResults();
        cout << endl;
    }
    return;
}

Session * Database::GetSession(){
    int min = 1000000;
    for( int i = 0; i < this->sessions.size(); i++ ){
        if( this->sessions.at(i)->GetNumberOfScores() < min ){
            min = this->sessions.at(i)->GetNumberOfScores();
        }
    }

    for( int i = 0; i < this->sessions.size(); i++ ){
        if( this->sessions.at(i)->GetNumberOfScores() == min ){
            return this->sessions.at(i);
        }
    }
    return NULL;
}

void Database::PrintScores( string jn ){
	for( int i = 0; i < this->sessions.size(); i++ ){
		this->sessions.at(i)->PrintResults( jn );
        cout << endl;
    }
    return;
}

void Database::ToFile( string filename ){
    fstream fid;
    fid.open( filename, ios::out );

    fid << "REGISTRATIONS: " << endl;
    for( int i = 0; i < this->people.size(); i++ ){
        fid << *this->people.at(i) << endl;
    }
    fid << endl << endl;

    fid << "SESSIONS: " << endl;
    for( int i = 0; i < this->sessions.size(); i++ ){
        fid << *this->sessions.at(i) << endl;
        this->sessions.at(i)->PrintResults( fid );
        fid << endl;
    }
    fid << endl;

    fid.close();

    return;
}

#endif