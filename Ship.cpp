#include <iostream>

#include "ShipWarClasses.hpp"

using namespace std;

Ship::Ship(int n){
    deckCount = n;

    decks.reserve(n);
}

bool Ship::set(int x, int y, int dir) {
    Deck nextDeck;

    for (int i = 0; i < deckCount; i++) {
        if (dir == RIGHT) nextDeck = new Deck(x + i, y);
          else 
            if (dir == BOTTOM) nextDeck = new Deck(x, y + i);
        decks.at(i) = nextDeck;
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

