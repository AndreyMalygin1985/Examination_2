#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::start() {
    char choice;

    do {
        cout << "Меню:" << endl;
        cout << "1. Начать игру" << endl;
        cout << "2. Выйти" << endl;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case '1':
            game.play();
            break;
        case '2':
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

        cout << endl;
    } while (choice != '2');
}
