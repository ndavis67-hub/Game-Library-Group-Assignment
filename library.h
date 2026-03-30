#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <list>
#include "game.h"

class Library{

private:
    std::list<Game> games;

public:
    void insert_sorted(Game g);
    void find_genre(std::string genre);
    void find_game(std::string title);
    void delete_game(std::string title, short year_released);
    void print();
    void load(std::string fileName);
    void save(std::string fileName);

};
#endif