#ifndef GAME_H
#define GAME_H
#include <string>
/**
 * @brief Game struct to hold the game library
 * 
 */
struct Game{
  /**
   * @brief the game needs to have a title 
   * @param std::string title
   */
  std::string title;
  
  std::string publisher;
  std::string genre;
  float hours_played;
  float price;
  short year_released;

};

#endif
