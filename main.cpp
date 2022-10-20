#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

class Game {
	private:
		std::vector<std::string> dicionario;
		std::vector<std::string> palavras_erradas;
		std::string palavra, palavra_secreta, palavra_usuario;
		int linha_aleatoria, chance = 6, tamanho_palavra;
		bool vitoria = false, letra_existe = false;

	public:
		std::string random_word ();
		void display_game();
		void end_game();
		void wrong_answers();
};

std::string Game::random_word() {
	std::ifstream read;
	read.open("palavras.txt");
	if (read.is_open()) {
		while (std::getline(read, palavra))
			dicionario.push_back(palavra); // armazenar cada linha do arquivo "palavras.txt" no vector dictionary
		std::random_device rd;
    	std::mt19937 mt(rd());
    	std::uniform_int_distribution<int> dist(0,79);
    	linha_aleatoria = dist(mt);
		palavra = dicionario[linha_aleatoria];
		palavra.resize(5);
		read.close();
	}
	return palavra;
}

void Game::wrong_answers() {
	std::cout << "Palavras erradas:\n";
	if (palavra_usuario != palavra)
		palavras_erradas.push_back(palavra_usuario);
	for (int i = 0; i < palavras_erradas.size(); i++)
		std::cout << palavras_erradas[i] << '\n';
}

void Game::display_game() {
	palavra_secreta = random_word();
	tamanho_palavra = palavra_secreta.length();
	for (int i = 0; i < tamanho_palavra; i++)
		palavra_secreta[i] = '-'; // escondendo a palavra da vez com caractere especial '-'
	do {
		system("clear"); // limpar terminal (mudar de acordo com o sistem operacional)
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "Acerte a palavra: " << palavra_secreta << '\n';
		wrong_answers();
		std::cout << "\nSeu palpite: ";
		std::cin >> palavra_usuario;
		for (int j = 0; j < tamanho_palavra; j++) {
			for (int k = 0; k < tamanho_palavra; k++) {
				if (palavra_usuario[j] == palavra[k])
					palavra_secreta[k] = palavra_usuario[j]; // testar letra por letra da palavra digtada entre a palavra do jogo
			}
		}
		if (palavra_secreta != palavra)
			chance--;
		else
			vitoria = true;
	} while (chance > 0 && vitoria != true);
}

void Game::end_game() {
	system("clear"); // limpar terminal (mudar de acordo com o sistem operacional)
	if (chance == 0) {
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "A palavra era: " << palavra << '\n';
		wrong_answers();
		std::cout << "\nMais sorte na proxima vez...\n";
	}
	if (vitoria == true) {
		std::cout << "Voce tem " << chance << " chances\n";
		std::cout << "Acerte a palavra: " << palavra_secreta << '\n';
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