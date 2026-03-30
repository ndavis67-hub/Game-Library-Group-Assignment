#include <iostream>
#include "library.h"
using namespace std;

void Library::insert_sorted(Game g){
    list<Game>::iterator it;
    bool inserted_game = false;
    for (it = games.begin(); it != games.end(); it++){
        
        if (g.title < it->title){
            games.insert(it, g);
            inserted_game = true;
            break;
        }
    }
    if (inserted_game == false){
            games.push_back(g);
        }
}
void Library::find_genre(std::string genre){

}
void Library::find_game(std::string title){

}
void Library::delete_game(std::string title, short year_released){

}
void Library::print(){
    list<Game>::iterator it;
    for (it = games.begin(); it != games.end(); it++){
        cout << "Publisher: " << it->publisher << endl 
        << "-Title: " << it->title << endl 
        << "-Genre: " << it->genre << endl 
        <<"-Hours Played: " << it->hours_played << endl
        << "-Price: " << it->price << endl
        << "-Year released: " << it->year_released << endl;
    }
}
void Library::load(std::string fileName){

}
void Library::save(std::string fileName){

}