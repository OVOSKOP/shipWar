void Menu::run(){

	printVariants();
	int n;
	bool flag = true;

	while(flag)
	{
		n = getInput();
			
		switch(n)
		{
			case 0:
				Game.run();
				break;
			case 1:
				cout << "О программе" << endl;
				cout << "Выполнили студенты Группы П1-17:" << endl;
				cout << "Богомолов Максим" << endl;
				cout << "Пищулин Игорь" << endl;
				cout << "Попкова Алена" << endl;
				cout << "Саполетова Анастасия"<< endl;
				cout << "Морской бой» игра для двух участников, в которой игроки по очереди называют координаты на неизвестной им карте соперника. Если у соперника по этим координатам имеется корабль (координаты заняты), то корабль или его часть «топится», а попавший получает право сделать ещё один ход. Цель игрока первым поразить все корабли противника" << endl;
	
				break;
			default:
			 	flag = false;
				break;
		}	
	}

}

void printVariants()
{
    cout << "0.Запуск игры" << endl;
    cout << "1.О программе" << endl;	
}


int getInput()
{
    int a; 
    cin >> a;
    return a;
}
