#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::getline;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ws;

string dicionario() {
    string dicionario[50] {"sagaz", "negro", "mexer", "nobre", "afeto", "plena", "sutil", "fazer", "vigor", "poder", "moral",
                            "muito", "justo", "honra", "sobre", "ideia", "assim", "sonho", "expor", "tempo", "dengo", "causa",
                            "dizer", "digno", "comum", "culto", "ainda", "censo", "valha", "forte", "pudor", "regra", "jeito",
                            "ordem", "pedir", "feliz", "prosa", "ontem", "forma", "vendo", "visar", "acaso", "certo", "afins",
                            "cisma", "obter", "todos", "matiz", "havia", "falso"};
    srand(time(0));
    int numero_palavra = rand()%50;
    string palavra = dicionario[numero_palavra];
    return palavra;
}

int main() {

    int chance {6};
    string palavra_random = dicionario();
    string forca = palavra_random;
    int tamanho_palavra = forca.length();
    vector<char> letra_inexistente;
    string palavra_usuario;
    bool vitoria {false}, letra_existe {false};

    for(int i = 0; i < tamanho_palavra; i++) {
        forca[i] = '_';
    }
   
    do {
        system("cls");
        cout << "Voce tem " << chance << " chances\n";
        cout << "Acerte a palavra: " << forca << '\n';
   
        cout << "\nLetras erradas:\n";
        for (int i = 0; i < letra_inexistente.size(); i++) {
            cout << letra_inexistente[i] << " ";
        }

        cout << "\nDigite uma palavra: ";
        getline(cin >> ws, palavra_usuario);
    
        for (int i = 0; i < tamanho_palavra; i++) {
            for (int j = 0; j < tamanho_palavra; j++) {
                if (palavra_usuario[i] == palavra_random[j]) {
                    forca[j] = palavra_usuario[i];
                    letra_existe = true;
                }
            }

            if (letra_existe == false) {
                letra_inexistente.push_back(palavra_usuario[i]);
            }

            letra_existe = false;
        }

        if (forca != palavra_random) {
            chance--;
        }

        if (forca == palavra_random) {
            vitoria = true;
        }

    } while (chance > 0 && vitoria != true);

    system("cls");
    if (vitoria == true) {
        cout << "Voce tem " << chance << " chances\n";
        cout << "Acerte a palavra: " << forca << '\n';
   
        cout << "\nLetras erradas:\n";
        for (int i = 0; i < letra_inexistente.size(); i++) {
            cout << letra_inexistente[i] << " ";
        }

        cout << "\nParabens, voce acertou a palavra!!!!!\n";
    }

    if (chance == 0) {
        cout << "Voce tem " << chance << " chances\n";
        cout << "Acerte a palavra: " << forca << '\n';
   
        cout << "\nLetras erradas:\n";
        for (int i = 0; i < letra_inexistente.size(); i++) {
            cout << letra_inexistente[i] << " ";
        }

        cout << "\nMais sorte na proxima vez... suas chances acabaram.\n";
    }

    return 0;
}