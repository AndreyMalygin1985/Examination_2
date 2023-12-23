#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Menu.h"
#include "Game.h"

// Создайте консольную версию игры «Виселица».
// Важно:
//	■	Слово выбирается компьютером из списка слов.
//	■	Список слов находится в файле в зашифрованном виде.
//	■	По завершении игры на экран выводится статистика игры :
//		•	количество времени;
//		•	количество попыток;
//		•	искомое слово;
//		•	буквы игрока.

int main()
{
	SetConsoleOutputCP(1251);

	Menu menu;
	menu.start();

	return 0;
}