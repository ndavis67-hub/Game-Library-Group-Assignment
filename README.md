# Game-Library-Group-Assignment
### Authors: Nasir and Joey

## Description
Here is a linked-list based game library that allows you to store, search, and manage all games that you add to the library. Games are sorted in alphabetical order. For inserting, please use underscores for the spaces in the title, genre, and publisher. That is the format that we put it in so it may not work otherwise. Duplicate games with the same title and year cannot exist.

## Compile
Compile using the (make) command in linux based systems

## How to run
Run the program using the (./gamelib) command in linux based systems

## Menu Options
1. **Insert a game** - Add a new game to the library, it will automatically be placed in alphabetical order
2. **Find by genre** - Search for all games that match a specific genre (ex. RPG, FPS, Simulation)
3. **Find by title** - Search for a game using a partial title match
4. **Delete a game** - Remove a game from the library using its title and release year
5. **Print library** - Print every game currently in the library
6. **Load a file** - Load a previously saved library file
7. **Save to file** - Save the current library to a file
8. **Exit** - Exit the program

## File Format
- title
- publisher
- genre
- hours_played
- price
- year_released

## Files Included
- main.cpp
- library.h
- library.cpp
- game.h
- game.cpp
- make
- example libraries: game_lib.txt new_library.txt
