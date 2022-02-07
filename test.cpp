#include "Event.h"
#include "Session.h"
#include "Presenter.h"
#include "Database.h"
#include "Admin.h"
#include "Judge.h"
#include <iostream>

using namespace std;

int main( void ){
	//Presenter * p = new Presenter;
	//p->NewAccount();
	//Session * s = new Session;
	//s->InputInformation();
//	s->PrintResults();

	Judge * j = new Judge;
	j->NewAccount();
//	j->Menu();

	/*Rubric *r = new Rubric;
	r->EnterScores();
	cout<<*r;*/

	Event * e = new Event;

	e->MainMenu();


	Database * d = new Database;

/*	d->AddPerson( p );
	d->AddSession( s );
	d->AddPerson( j );



	//d->ToFile(name);*/
	
	delete d;
	
	return 0;
}