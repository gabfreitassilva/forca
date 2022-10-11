#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using std::ifstream;
using std::getline;
using std::string;
using std::vector;
using std::cout;
using std::cin;

int main() {
    vector<string> dicionario;
    string palavra;

    ifstream leitura;

    leitura.open("palavras.txt");
    if(leitura.is_open()) {
        while (getline(leitura, palavra)) {
            dicionario.push_back(palavra);
        }
        srand(time(0));
        int random_line = rand()%dicionario.size();
        palavra = dicionario.at(random_line);
        leitura.close();
    }

    string forca = palavra;
    int tamanho_palavra = palavra.length();

    for (int i = 0; i < tamanho_palavra; i++) {
        forca[i] = '-';
    }

    int chance = 6;
    bool vitoria = false;

    do {
        cout << "acerte a palavra: " << forca << '\n';

        cout << "Digite uma palavra: ";
        string palavra_usuario;
        cin >> palavra_usuario;

        for (int i = 0; i < tamanho_palavra; i++) {
            for (int j = 0; j < tamanho_palavra; j++) {
                if (palavra_usuario[i] == palavra[j]) {
                    forca[j] = palavra_usuario[i];
                }
            }
        } 
        
        if (forca != palavra) {
            chance--;
        }

        if (forca == palavra) {
            vitoria = true;
        }

    } while (vitoria == false && chance > 0);

    return 0;
}