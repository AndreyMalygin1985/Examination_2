#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <chrono>
using namespace std;

class Game {
protected:
	friend class Menu;

private:
	vector<std::string> words;
	string hiddenWord;
	vector<char> guessedLetters;
	int numAttempts;
	chrono::steady_clock::time_point startTime;
	chrono::steady_clock::time_point endTime;

	void loadWordsFromFile(const string& filename);
	string selectRandomWord();
	bool isWordGuessed(const string& hiddenWord, const vector<char>& guessedLetters);
	void printHangman(int numAttempts);
	void showWord(const string& hiddenWord, const vector<char>& guessedLetters);

public:
	Game();
	void play();
	int getTimeDuration() const;
};
#endif