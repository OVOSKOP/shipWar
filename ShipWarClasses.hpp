#ifndef SHIPWARCLASSES_HPP
#define SHIRWARCLASSES_HPP

#include <vector>
#include <pair>

class Player {
	Field f; // поле игрока с его кораблями
	// игрок ставит корабль в клетку, программа вызывает метод addShip, передает в нее количество палуб
	// координату начальной клетки и направление, метод вызывает конструктор Ship и добавляет новый корабль в массив
	// кораблей поля игрока.
	bool addShip(int n, int x, int y, int dir);
	bool isALive(); // проверяет количество оставшихся кораблей. Если кораблей > 0, то результат true
}

class Field{
	// Игрок вводит 2 координаты в диапазоне [a-k], [1-10], программа вызывает isUsed, которая
	// проверяет нахождение клетки в массиве usedDeck, если клетки нет в массиве, программа вызывает метод
	// hit, которая засчитывает клетку в массив и если игрок попал, то засчитывает урон кораблю.
	public:
		Ships s[10];
		vector < pair <Deck, int> > usedDeck; //  {((1,1), 1), {{(1,2),2}}
		bool hit(int x, int y);
		bool isUsed(int x, int y);
		bool isFree(int x, int y);
};
class Deck{
	// палуба корабля
	public:
		Deck(int x, int y); 
		int x;
		int y;
};

class Ship{
	public:
		// конструктор получает количество палуб, координату начальной клетки, и направление,
		// вызывает метод isFree, который проверяет свободность клетки, и если координата свободна
		// то в зависимости от направления прибавляет к x или y единицу и проверяет свободность новой координаты, по количеству палуб 
		Ships(int n, int x, int y, int dir);
		int countDeck;
		Deck d[n];
		isHit();
};
#endif //SHIPWARCLASSES_HPP
