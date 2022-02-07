#ifndef RUBRIC_H
#define RUBRIC_H

#include <string> 
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Rubric{
    public:
        void SetFile( string filename );
        void SetJudgeName( string jn );
        string GetJudgeName();

        void EnterScores();
        void PrintScores();
        void PrintScores( ostream & out );

        friend ostream & operator<<( ostream & out, const Rubric & r );
        
    private:
        vector<string> categories;
        vector<int> scores;
        string judge_name;
};

void Rubric::SetFile( string filename ){
    fstream fid;
    fid.open( filename, ios::in );

    string tmp;
    while( !fid.eof() ){
        getline( fid, tmp );
        this->categories.push_back( tmp );
    }

    this->scores.resize( this->categories.size() );

    fid.close();
    return;
}

void Rubric::EnterScores(){

    cout << "****** Rubric information ******" << endl;
    for( int i = 0; i < this->categories.size(); i++ ){
        cout << this->categories.at(i) << endl;
        cout << endl << "   1. Excellent\n   2. Good\n   3. Satisfactory\n   4. Needs Improvement" << endl;
        cout << endl << "Enter in a score: " << endl;
        cin >> scores.at(i);
    }
    return;
}

void Rubric::PrintScores(){
    for( int i = 0; i < this->categories.size(); i++ ){
        cout << setw(20) << this->categories.at(i).substr(0, this->categories.at(i).find(":") );
        cout << ": " << this->scores.at(i) << endl;
    }
    return;
}

void Rubric::PrintScores( ostream & out ){
    for( int i = 0; i < this->categories.size(); i++ ){
        out << setw(20) << this->categories.at(i).substr(0, this->categories.at(i).find(":") );
        out << ": " << this->scores.at(i) << endl;
    }
    return;
}

void Rubric::SetJudgeName( string jn ){
    this->judge_name = jn;
    return;
}

string Rubric::GetJudgeName(){
    return this->judge_name;
}

ostream & operator<<( ostream & out, const Rubric & r ){
    out << "Rubric scores: " << endl;
    for( int i = 0; i < r.categories.size(); i++ ){
        out << r.categories.at(i) << endl;
    }
    return out;
}

#endif