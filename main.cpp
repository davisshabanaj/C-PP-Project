#include "Event.h"

using namespace std;

int main( void ){

    Event Conference2021;
    Database d;
    Conference2021.SetDatabase( &d );

    while( Conference2021.MainMenu() > 0 ){}

    return 0;
}