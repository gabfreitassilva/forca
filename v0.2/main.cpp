/*
    BETA PODRE
*/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::string;

class Game {
    public:
        int tamanho_palavra, random_number, chance, palavra_concluida {0};
        string dicionario[10] {"uva", "apple", "cavalo", "abacaxi", "cinco", "positivo", "aula", "visual", "quadrado", "palavra"};
        string palavra, forca;
        char letra;
        bool acerto {false};
        
        void displayGame();
        void palavraForca();

};

void Game::palavraForca() {
    srand(time(0));
    random_number = rand()%10;

    palavra = dicionario[random_number];
    forca = palavra;
    tamanho_palavra = palavra.length();
}

void Game::displayGame() {
    for (int i = 0; i < 50; i++) {
        cout << "Bem-vindo ao jogo da forca\n";

        cout << "A palavra e escolhida automaticamente pelo computador.\n";
        cout << "A palavra da vez tem " << tamanho_palavra << " letras\n";
        for (int j = 0; j < tamanho_palavra; j++) {
            if (i == 0) {
                forca[j] = '_';
            } else {
                if (palavra[j] == letra) {
                    forca[j] = letra;
                    acerto = true;
                    palavra_concluida++;
                    i--;
                }
            }
        }
        cout << forca << '\n';
        if (i == 0) {
            chance = tamanho_palavra;
        } else {
            if (acerto == false) {
                chance--;
            }
        }
        cout << "Voce tem " << chance << " chances para certar a palavra.\n";
        cout << "Digite uma letra: ";
        cin >> letra;
        acerto = false;
        system("cls");
    }
}

int main() {
    Game game;

    game.palavraForca();
    game.displayGame();

    return 0;
}