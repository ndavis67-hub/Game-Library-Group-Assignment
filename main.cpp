#include <iostream>
#include "library.h"
using namespace std;

int main(){
    Library lib;
    int choice = 0;

    while(choice != 8){
        cout << "Welcome to the Game Library. Please select one of these options: " << endl
             << "1. Insert a name into the library (sorted)" << endl
             << "2. Find genre in library" << endl
             << "3. Find game in library" << endl
             << "4. Delete game from library " << endl
             << "5. Print a game " << endl
             << "6. Load a file to the game library" << endl
             << "7. Save a file" << endl
             << "8. Exit the program" << endl;
        cin >> choice;

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

        else if (choice == 2){
            string genre;
            cout << "Enter a genre to search for: ";
            cin >> genre;
            lib.find_genre(genre);
        }

        else if (choice == 3){
            string game;

            cout << "Enter a game you want to search for: ";
            cin >> game;
            lib.find_game(game);
        }

        else if (choice == 4){
            string title_game;
            short year;
            cout << "Enter the title of the game:";
            cin >> title_game;
            cout << "Enter the year it was released: ";
            cin >> year;
            lib.delete_game(title_game, year);
        }

        else if(choice == 5){
            lib.print();
        }

        else if(choice == 6){
            string file;
            cout << "Enter the name of the file: ";
            cin >> file;
            lib.load(file);
        }

        else if(choice == 7){
            string file;
            cout << "Enter the name of the file: ";
            cin >> file;
            lib.save(file);
        }

        else if(choice == 8){
            cout << "See ya later" << endl;
            break;
        }

        else{
            cout << "Invalid input" << endl;
        }

    }
}