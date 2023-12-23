#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Game.h"

void Game::loadWordsFromFile(const string& filename) {
	ifstream file(filename);
	string word;

	while (file >> word) {
		words.push_back(word);
	}

	file.close();
}

string Game::selectRandomWord() {
	if (words.empty()) {
		cerr << "Ошибка: список слов пуст." << endl;
		exit(1);
	}

	srand(time(nullptr));
	int index = rand() % words.size();

	return words[index];
}

bool Game::isWordGuessed(const string& secretWord, const vector<char>& guessedLetters) {
	for (char letter : secretWord) {
		if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
			return false;
		}
	}
	return true;
}

void Game::printHangman(int numAttempts)
{
	if (numAttempts == 0) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|       / \\" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 1) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|       /" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 2) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 3) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|       /|\\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 4) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|       /|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 5) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 6) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        !" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 7) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
	else if (numAttempts == 8) {
		cout << " --------" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|___" << endl;
	}
}

void Game::showWord(const string& secretWord, const vector<char>& guessedLetters) {
	cout << "Слово: ";
	for (char letter : secretWord) {
		if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
			cout << letter << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}

Game::Game() {
	string wordsFile = "words.txt";
	loadWordsFromFile(wordsFile);

	hiddenWord = selectRandomWord();
	guessedLetters.clear();
	numAttempts = 0;
}

void Game::play() {
	cout << "Добро пожаловать в игру 'Виселица'!" << endl;
	startTime = chrono::steady_clock::now();

	while (!isWordGuessed(hiddenWord, guessedLetters) && numAttempts < 8) {
		printHangman(numAttempts);
		showWord(hiddenWord, guessedLetters);

		cout << "Угадайте букву: ";
		char guess;
		cin >> guess;

		guessedLetters.push_back(guess);

		if (hiddenWord.find(guess) == string::npos) {
			numAttempts++;
			cout << "Неправильная буква!" << endl;
		}
	}

	endTime = chrono::steady_clock::now();
	printHangman(numAttempts);
	showWord(hiddenWord, guessedLetters);

	if (isWordGuessed(hiddenWord, guessedLetters)) {
		cout << "Поздравляю, вы угадали слово!" << endl;
	}
	else {
		cout << "К сожалению, вы проиграли." << endl;
	}

	cout << endl << "Статистика игры:" << endl;
	cout << "Потраченое время: " << getTimeDuration() << " секунд" << endl;
	cout << "Количество неправильных букв: " << numAttempts << endl;
	cout << "Загаданное слово: " << hiddenWord << endl;
	cout << "Все введённые буквы : ";
	for (char letter : guessedLetters) {
		cout << letter << " ";
	}
	cout << endl;
}

int Game::getTimeDuration() const
{
	chrono::steady_clock::duration duration = endTime - startTime;
	return chrono::duration_cast<chrono::seconds>(duration).count();
}
