#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
    Game(const std::vector<std::string>& names);
    
    ~Game();
    
    //plays the game of blackjack    
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;  
};

#endif