#include <iostream>
#include <fstream>
#include <iomanip>
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
    list<Game>::iterator it;

    for(it = games.begin(); it != games.end();it++){
        if(it->genre == genre){
            cout << "Here are the game(s): " << endl
            << "Publisher: " << it->publisher << endl 
            << "-Title: " << it->title << endl 
            << "-Genre: " << it->genre << endl 
            <<"-Hours Played: " << it->hours_played << endl
            << "-Price: " << it->price << endl
            << "-Year released: " << it->year_released << endl;
        }
    }
}
void Library::find_game(std::string title){
    list<Game>::iterator it;
    for (it = games.begin(); it != games.end(); it++){
        //searches for the title and if it cannot find the title then it has no position
        //here is the source for the npos: https://en.cppreference.com/w/cpp/string/basic_string/find
        if(it->title.find(title) != std::string::npos){
            cout << "Here are the game(s): " << endl
            << "Publisher: " << it->publisher << endl 
            << "-Title: " << it->title << endl 
            << "-Genre: " << it->genre << endl 
            <<"-Hours Played: " << it->hours_played << endl
            << "-Price: " << it->price << endl
            << "-Year released: " << it->year_released << endl;
        }
    }
}
void Library::delete_game(std::string title, short year_released){
    list<Game>::iterator it;
    for (it = games.begin(); it != games.end(); it++){
        if(it->title == title && it->year_released == year_released){
            games.erase(it);
            break;
        }   
    }
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
//this is to read a file and fill up the games list
void Library::load(std::string fileName){
    Game temp;
    fstream inFile;
    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "File does not exist." << endl;
        return;
    }
    inFile >> temp.title;
    //sentinel loop help from dr.ericson
    while(inFile){
        inFile >> temp.publisher;
        inFile >> temp.genre;
        inFile >> temp.hours_played;
        inFile >> temp.price;
        inFile >> temp.year_released;
        insert_sorted(temp);
        inFile >> temp.title;
    }
    inFile.close();
}
void Library::save(std::string fileName){
    list<Game>::iterator it;
    //we want to write to a file so i need to use ofstream
    ofstream inFile;

    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "File does not exist." << endl;
        return;
    }

    for (it = games.begin(); it != games.end(); it++){
        inFile << it->title << endl 
               << it->publisher << endl 
               << it->genre << endl 
               << it->hours_played << endl
               << it->price << endl
               << it->year_released << endl;
    }
    
    inFile.close();
}