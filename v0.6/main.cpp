#include <iostream>
#include <string>
#include <cmath>

using std::getline;
using std::string;
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
    string palavra_usuario;
    bool vitoria {false};
    for(int i = 0; i < tamanho_palavra; i++) { forca[i] = '_'; }
   
    do {
        system("cls");
        cout << "Acerte a palavra: " << forca << '\n';
   
        cout << "Digite uma palavra: ";
        getline(cin >> ws, palavra_usuario);
    
        for(int i = 0; i < tamanho_palavra; i++) {
            for(int j = 0; j < tamanho_palavra; j++) {
                if(palavra_usuario[i] == palavra_random[j]) {
                    forca[j] = palavra_usuario[i];
                }
            }
        }

        if(forca != palavra_random) { chance--; }
        if(forca == palavra_random) { vitoria = true; }
    } while(chance > 0 && vitoria != true);

    system("cls");
    if(vitoria == true) {
        cout << "Voce acertou a palavra! Parabens!\n";
        cout << "Acerte a palavra: " << forca << '\n';
    }

    if(chance == 0) {
        cout << "Infelizmente voce perdeu.. Mais sorte na proxima vez!\n";
        cout << "Acerte a palavra: " << forca << '\n';
    }
    return 0;
}