#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <list>
#include "game.h"

class Library{

private:
    //this uses the game struct and makes it a list
    std::list<Game> games;

public:
    /**
     * @brief this sorts out any game by the title that is added to the game library A-Z
     * 
     * @param g 
     */
    void insert_sorted(Game g);

    /**
     * @brief function to find the genre based on the games in the genre created. if multiple games in genre, then it will find the games.
     * 
     * @param genre 
     */
    void find_genre(std::string genre);

    /**
     * @brief finds the game based on the title ex: Apex_Legends
     * 
     * @param title 
     */
    void find_game(std::string title);

    /**
     * @brief this method will delete a game from the library based on their title and year released
     * 
     * @param title 
     * @param year_released 
     */
    void delete_game(std::string title, short year_released);

    /**
     * @brief This method prints all the games in the current library
     * 
     */
    void print();

    /**
     * @brief this will add a file to the game library. to check to see if it works use print to show the games
     * 
     * @param fileName 
     */
    void load(std::string fileName);

    /**
     * @brief this allows user to save games that they have added to the library to a .txt file
     * 
     * @param fileName 
     */
    void save(std::string fileName);

};
#endif