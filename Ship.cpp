#include <iostream>

#include "ShipWarClasses.hpp"

using namespace std;

Ship::Ship(int x, int y, int n, int dir){
    Deck nextDeck;
    deckCount = n;
    decks.push_back(new Deck(x, y));
    for (int i = 0; i < deckCount; i++){
        if (dir == RIGHT) nextDeck = new Deck(x + 1, y);
          else 
            if (dir == BOTTOM) nextDeck = new Deck(x, y + 1);
        decks.push_back(nextDeck);
    }
}

bool Ship::isHit(int x, int y){
    int check = checkSpace(x,y);
    if (check){
        decks.erase(decks.begin() + (check - 1));
        deckCount -= 1;
        return true;
    }

    return false;
}        
    
int Ship::checkSpace(int x, int y){
    int space = 0;
    for(int i = 0; i < decks.size() && !space; i++){
        if(x == decks.at(i).x && decks.at(i).y == y)
            space = i;
    }

    return space;
}

