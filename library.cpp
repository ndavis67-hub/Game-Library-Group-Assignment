#include <iostream>
#include <fstream>
#include <iomanip>
#include "library.h"
using namespace std;

//inserts a game into the list and sorts it alphabetically 
void Library::insert_sorted(Game g){
    //iterator to traverse through the list
    list<Game>::iterator it;

    //created to make sure that the inserted game is in alphabetical order correctly
    bool inserted_game = false;

    //walks through list from beginning to end until we find a title that comes after ours
    for (it = games.begin(); it != games.end(); it++){
        //if you found the right name, insert it before the current game and stop looking
        if (g.title < it->title){
            games.insert(it, g);
            inserted_game = true;
            break;
        }
    }
    //if you didn't find the right spot then put the game at the end
    if (inserted_game == false){
            games.push_back(g);
        }
}
//prints all games that match with the given genre
void Library::find_genre(std::string genre){
    list<Game>::iterator it;

    for(it = games.begin(); it != games.end();it++){
        //if the genre of the game you are looking for matches the given genre print the given information
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
//searches for any game whose title matches the given title
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
// Removes a game from the list by matching both title and release year
// We check both fields so we don't accidentally delete the wrong game
void Library::delete_game(std::string title, short year_released){
    list<Game>::iterator it;
    for (it = games.begin(); it != games.end(); it++){
        if(it->title == title && it->year_released == year_released){
            games.erase(it);
            break;
        }   
    }
}
//prints every game currently in the library
void Library::print(){

    list<Game>::iterator it;

    for (it = games.begin(); it != games.end(); it++){
        //this is the structure for how to print the games
        cout << "Publisher: " << it->publisher << endl 
        << "-Title: " << it->title << endl 
        << "-Genre: " << it->genre << endl 
        <<"-Hours Played: " << it->hours_played << endl
        << "-Price: " << it->price << endl
        << "-Year released: " << it->year_released << endl;
    }
}
//Reads a file and loads all the games into the library
void Library::load(std::string fileName){
    //temp holds each game's data as we read it in
    Game temp;
    
    fstream inFile;
    //open the file
    inFile.open(fileName);
    //if we can't open the file, file doesn't exist
    if(!inFile.is_open()){
        cout << "File does not exist." << endl;
        return;
    }
    //read the first title before the loop so the sentinel loop has something to check
    inFile >> temp.title;
    //sentinel loop help from dr.ericson
    while(inFile){
        //this is the structure the file should be in
        inFile >> temp.publisher;
        inFile >> temp.genre;
        inFile >> temp.hours_played;
        inFile >> temp.price;
        inFile >> temp.year_released;
        //used a function we created to sort the games in the file alphabetically
        insert_sorted(temp);
        inFile >> temp.title;
    }
    //dont forget to close the file
    inFile.close();
}
//save the current game library to a file 
void Library::save(std::string fileName){
    list<Game>::iterator it;
    //we want to write to a file so i need to use ofstream
    ofstream inFile;

    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "File does not exist." << endl;
        return;
    }
    //write each game's fields on separate lines to match the load format
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