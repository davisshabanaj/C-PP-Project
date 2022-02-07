#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Rubric.h"

using namespace std;

class Session{
    public:
        Session();
        ~Session();

        void InputInformation();

        void AddRubricScores( string jn );
        int GetNumberOfScores();

        void PrintResults();
        void PrintResults( string jn );
        void PrintResults( ostream & out );

        friend ostream & operator<<( ostream & out, const Session & s );
        
    protected:
        string title;
        string type;
        vector< string > authors;
        vector<Rubric *> rubric_scores;
};

Session::Session(){
    this->type = "None";
    this->title = "None";
    return;
}

Session::~Session(){
    for( int i = 0; i < this->rubric_scores.size(); i++ ){
        delete this->rubric_scores.at(i);
    }
    return;
}

void Session::InputInformation(){
    int option;
    cout << endl << "Enter in session information: " << endl;
    cout << "   1. Poster\n   2. Presentation\n\nType: ";
    cin >> option;

    if( option == 1 ){
        this->type = "Poster";
    }
    else if( option == 2 ){
        this->type = "Presentation";
    }

    cout << endl << "Title: ";
    cin.ignore(256,'\n');
    getline( cin, this->title );

    int num_authors;
    cout << "Number of authors: ";
    cin >> num_authors;
    this->authors.resize( num_authors );

    cin.ignore(256,'\n');
    for( int i = 0; i < this->authors.size(); i++ ){
        cout << "Author " << i+1 << ": ";
        getline( cin, this->authors.at(i) );
    }

    return;
}

void Session::AddRubricScores( string jn ){

    Rubric * r = new Rubric;
    r->SetFile( "Rubric.txt" );
    r->SetJudgeName( jn );
    r->EnterScores();

    this->rubric_scores.push_back( r );
    return;
}

int Session::GetNumberOfScores(){
    return this->rubric_scores.size();
}

void Session::PrintResults(){
    cout << "****** RESULTS ******" << endl;
    cout << endl << *this << endl;
    for( int i = 0; i < this->rubric_scores.size(); i++ ){
        this->rubric_scores.at(i)->PrintScores();
        cout << endl << endl;
    }
    return;
}

void Session::PrintResults( string jn ){
    cout << "****** RESULTS  for " << jn << " ******" << endl;
    for( int i = 0; i < this->rubric_scores.size(); i++ ){
        if( this->rubric_scores.at(i)->GetJudgeName() == jn ){
            cout << endl << *this << endl << endl;
            this->rubric_scores.at(i)->PrintScores();
        }
    }
    return;
}

void Session::PrintResults( ostream & out ){
    for( int i = 0; i < this->rubric_scores.size(); i++ ){
        this->rubric_scores.at(i)->PrintScores( out );
        out << endl << endl;
    }
}

ostream & operator<<( ostream & out, const Session & s ){
    out << endl;
    out << s.type << endl;
    out << "      Title: " << s.title << endl;
    out << "    Authors: ";
    for( int i = 0; i < s.authors.size()-1; i++ ){
        out << s.authors.at(i) << ", ";
    }
    out << s.authors.at( s.authors.size()-1 ) << endl;
    return out;
}


#endif