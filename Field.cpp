#include <iostream>

#include "ShipWarClasses.hpp"

using namespace std;

bool Field::addShip(int x, int y, int n, int dir)
{
    bool allFree = true;
    bool nextCellFree;

    if(isFree(x,y)){
        for(int i = 0; i < n && allFree; i++){
            if (dir == RIGHT) nextCellFree = !isFree(x + i, y);
              else 
                if (dir == BOTTOM) nextCellFree = !isFree(x, y + i);
            if (!nextCellFree)
                allFree = false;
        }
    }

    if(allFree){
        ships.push_back(new Ship(x, y, n, dir));
    }
    return allFree;
}

bool Field::hit(int x, int y)
{
    bool h = false;
	for (int i = 0; i < ships.size(); i++) {
		if (ships.at(i).isHit(x, y))
            h = true;
	}

    return h;
}

bool Field::isUsed(int x, int y)
{
    bool used = false;

	for (int i = 0; i < usedDeck.size() && !used; i++) {
		if (x == usedDeck.at(i).first.x && usedDeck.at(i).first.y == y){
            used = true;
        }
	}

    if (used) 
        return true;
      else
        return false;
}

bool Field::isFree(int x, int y)
{
    bool taken = false;

	for (int i = 0; i < SHIPS_COUNT && !taken; i++) {
		if(ships[i].checkSpace(x, y) && isInBounds(x,y))
            taken = true;
	}

    if (!taken) 
        return true;
      else
        return false;
}

bool Field::isInBounds(int x, int y){
    return (x >= 1 && x <= FIELDSIZE &&  y >= 1 && y <= FIELDSIZE);
}
