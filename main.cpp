#include <iostream>
#include "library.h"
using namespace std;

int main(){
    //library object that holds all of the games
    Library lib;
    int choice = 0;
    //keep showing the menu until user chooses 8. same as linked-list individual assignment.
    while(choice != 8){
        cout << "Welcome to the Game Library. Please select one of these options: " << endl
             << "1. Insert a game into the library" << endl
             << "2. Find a genre in library" << endl
             << "3. Find a game in library" << endl
             << "4. Delete a game from library " << endl
             << "5. Print the current library " << endl
             << "6. Load a file to the game library" << endl
             << "7. Save a file" << endl
             << "8. Exit the program" << endl;
        cin >> choice;
        
        //collect all 6 fields from the user and insert the game in sorted order
        if (choice == 1){
            Game temp;

            cout << "Enter the title (use underscores for spaces): ";
            cin >> temp.title;
            cout << endl;

            cout << "Enter the publisher (use underscores for spaces): ";
            cin >> temp.publisher;
            cout << endl;

            cout << "Enter the genre (use underscores for spaces): ";
            cin >> temp.genre;
            cout << endl;

            cout << "How many hours played: ";
            cin >> temp.hours_played;
            cout << endl;

            cout << "What is the price: ";
            cin >> temp.price;
            cout << endl;

            cout << "What year was it released: ";
            cin >> temp.year_released;
            lib.insert_sorted(temp);

        }
        //search for all games that match the given genre
        else if (choice == 2){
            string genre;
            cout << "Enter a genre to search for: ";
            cin >> genre;
            lib.find_genre(genre);
        }
        //search for any game whose title contains the given string
        else if (choice == 3){
            string game;

            cout << "Enter a game you want to search for: ";
            cin >> game;
            lib.find_game(game);
        }
        //get the title and year in order to delete the game and to make sure we delete the right game
        else if (choice == 4){
            string title_game;
            short year;
            cout << "Enter the title of the game:";
            cin >> title_game;
            cout << "Enter the year it was released: ";
            cin >> year;
            lib.delete_game(title_game, year);
        }
        //print everything in the current library
        else if(choice == 5){
            lib.print();
        }
        //load a saved library file into the program
        else if(choice == 6){
            string file;
            cout << "Enter the name of the file: ";
            cin >> file;
            lib.load(file);
        }
        //save the library into a file
        else if(choice == 7){
            string file;
            cout << "Enter the name of the file: ";
            cin >> file;
            lib.save(file);
        }
        //exit the program
        else if(choice == 8){
            cout << "See ya later" << endl;
            break;
        }
        //if no number matches any field then show it is invalid input
        else{
            cout << "Invalid input" << endl;
        }

    }
}