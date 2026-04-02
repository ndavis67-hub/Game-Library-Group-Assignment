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
             << "5. Print the game library" << endl
             << "6. Load a file" << endl
             << "7. Save a file" << endl
             << "8. Exit the program";
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
    }
}