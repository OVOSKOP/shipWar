#ifndef SHIPWARCLASSES_HPP
#define SHIRWARCLASSES_HPP

#include <vector>
#include <utility> //pair, make_pair

class Menu{
public: 
    void run(); //функция запуска меню, вызывается при запуске программы и при выходе в меню
private:
    const int variantCount = 2; //количество вариантов выбора в меню
    void printVariants();  //функция вывода вариантов выбора
    int getInput(); // функция получающая выбор пользователя
}

class Game {
	public:
	    void run();// метод, который запускает игру
	private:
	    Player p1; //Игрок №1
	    Player p2; //Игрок №2

	    const int FIELDSIZE = 10; // number of cells = FIELDSIZE * FIELDSIZE
	    const int SHIPS_COUNT = 10;
	    const int RIGHT = 1;
	    const int BOTTOM = 0;
};

class Player {
	public:
	    Player(); // конструктор игрока, который инициализирует доступные корабли
	    void rankingShip(); // расстановка кораблей игроками
	    bool isALive(); // проверяет количество оставшихся кораблей. Если кораблей > 0, то результат true
	private:
	    Field f; // поле игрока с его кораблями
	    // игрок ставит корабль в клетку, программа вызывает метод addShip, передает в нее количество палуб
	    // координату начальной клетки и направление, метод вызывает конструктор Ship и добавляет новый корабль в массив
	    // кораблей поля игрока.
	    vector < Ship > avalaibleShips; // инвентарь игрока с десятью кораблями
};

class Field{
	// Игрок вводит 2 координаты в диапазоне [a-k], [1-10], программа вызывает isUsed, которая
	// проверяет нахождение клетки в массиве usedDeck, если клетки нет в массиве, программа вызывает метод
	// hit, которая засчитывает клетку в массив и если игрок попал, то засчитывает урон кораблю.
	public:
	    // addShip вызывает метод isFree, который проверяет свободность клетки, и если координата свободна
		// то в зависимости от направления прибавляет к x или y единицу и проверяет свободность 
	    // новой координаты, по количеству палуб 
	    bool addShip(int x, int y, int n, int dir);
		bool hit(int x, int y);
		bool isUsed(int x, int y);
		bool isFree(int x, int y);
	    bool isInBounds(int x, int y);
	private:
		vector < Ship > ships;
		vector < pair <Deck, int> > usedDeck; 
};

class Deck{
	// палуба корабля
	public:
		Deck(int x, int y); 
	private:
		int x;
		int y;
};

class Ship{
	public:
		// конструктор получает количество палуб координату начальной клетки, и направление, 
	    // и создаёт корабль с этими координатами
		Ship(int n);
		bool set(int x, int y, int dir);
		bool isHit(int x, int y);
	    int checkSpace(int x, int y); //returns 0 if (x,y) is not in this ship
	private:
		int deckCount;
		vector < Deck > decks;
};

#endif //SHIPWARCLASSES_HPP
