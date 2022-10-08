#include <iostream>
#include <vector>
#include <string>
#include "dicionario.hpp"
using std::string;
using std::vector;
using std::cout;
using std::cin;

class Game {
    public:
        string palavra_random = dicionario();
        int tamanho_palavra = palavra_random.length(), chance {30}, vitoria {0};
        vector<char> letra_errada;
        string forca;
        char letra_usuario;
        bool acerto;

        void display_status(void);
        void end_game(void);
};