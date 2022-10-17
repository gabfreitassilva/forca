#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
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

std::string Game::random_word(void) {
	std::ifstream read;
	read.open("palavras.txt");
	if (read.is_open()) {
		while (std::getline(read, word))
			dictionary.push_back(word); // armazenar cada linha do arquivo "palavras.txt" no vector dictionary
		srand(time(0));
		random_line = rand()%dictionary.size();
		word = dictionary.at(random_line); // escolhe uma palavra aleatória dentro do vector dicitonary
		read.close();
	}
	return word;
}

void Game::wrong_answers(void) {
	std::cout << "Palavras erradas:\n";
	if (user_word != word)
		wrong_words.push_back(user_word);
	for (int i = 0; i < wrong_words.size(); i++)
		std::cout << wrong_words[i] << '\n';
}

void Game::display_game(void) {
	secret_word = random_word();
	word_size = secret_word.size();
	for (int i = 0; i < word_size; i++)
		secret_word[i] = '-'; // escondendo a palavra da vez com caractere especial '-'
	do {
		system("clear"); // limpar terminal (mudar de acordo com o sistem operacional)
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "Acerte a palavra: " << secret_word << '\n';
		wrong_answers();
		std::cout << "\nSeu palpite: ";
		std::cin >> user_word;
		for (int j = 0; j < word_size; j++) {
			for (int k = 0; k < word_size; k++) {
				if (user_word[j] == word[k])
					secret_word[k] = user_word[j]; // testar letra por letra da palavra digtada entre a palavra do jogo
			}
		}
		if (secret_word != word)
			chance--;
		else
			win = true;
	} while (chance > 0 && win != true);
}

void Game::end_game(void) {
	system("clear"); // limpar terminal (mudar de acordo com o sistem operacional)
	if (chance == 0) {
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "A palavra era: " << word << '\n';
		wrong_answers();
		std::cout << "\nMais sorte na proxima vez...\n";
	}
	if (win == true) {
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "Acerte a palavra: " << secret_word << '\n';
		wrong_answers();
		std::cout << "\nParabens, voce venceu o jogo!!!\n";
	}
}

int main() {
	Game game;
	game.display_game();
	game.end_game();
	return 0;
}