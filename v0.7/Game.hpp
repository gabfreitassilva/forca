#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

class Game {
	private:
		std::vector<std::string> dictionary;
		std::vector<std::string> wrong_words;
		std::string word, secret_word, user_word;
		int random_line, chance = 6, word_size;
		bool win = false, letter_exist = false;

	public:
		std::string random_word (void);
		void display_game(void);
		void end_game(void);
		void wrong_answers(void);
};