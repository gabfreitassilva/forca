#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::cin;

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
    int tamanho_palavra, vida = 15, vitoria = 0;
    char letra_usuario;
    vector<char> letra_incorreta;
    string forca, palavra_random;
    bool acerto;

    palavra_random = dicionario();
    tamanho_palavra = palavra_random.length();
    forca = palavra_random;

    for(int i = 0; i < tamanho_palavra; i++) { // me retorna uma string do tamanha da palavra escolhida aleatoriamente, mas com - no lugar das letras
        forca[i] = '-';
    }

    do {
        system("cls");
        cout << "============Jogo da forca com C++============\n";
        cout << "A palavra da vez tem " << tamanho_palavra << " letras.\n";
        cout << "Voce tem " << vida << " chances para acertar a palavra.\n\n";
        cout << forca << '\n';

        cout << "Letras erradas: \n";
        for(int i = 0; i < letra_incorreta.size(); i++) { // vai sempre retornar as letras erradas, cada repetição do programa
            cout << letra_incorreta[i] << " ";
        }

        cout << "\nDigite uma letra: ";
        cin >> letra_usuario;

        for(int i = 0; i < tamanho_palavra; i++) {
            if(letra_usuario == palavra_random[i]) { // verificação da letra digitada, caso exista na palavra escolhida pelo computador
                forca[i] = letra_usuario; // se a letra exisitir, o programa atribui a letra na posição dentro da string que contem os -
                vitoria++;
                acerto = true;
            }
        }

        if(acerto == false) {
            vida--;
            letra_incorreta.push_back(letra_usuario); // coloca a letra errada no vetor
        }

        acerto = false; // retorna o valor para false todo final do loop
    } while(vida > 0 && vitoria < tamanho_palavra);
   
    if(vitoria == tamanho_palavra) { // cada letra acertada acrescente +1 a variavel vitoria, logo quando vitoria for igual o tamanho da palavra, o usuario vence
        system("cls");
        cout << "Voce venceu!\n";
        cout << "A palavra era " << palavra_random << '\n';
    }

    if(vida == 0) { // sempre que o usuario errar, uma vida é perdida, logo quando a quantidade de vidas zerar, o jogo termina
        system("cls");
        cout << "Voce perdeu!\n";
        cout << "A palavra era " << palavra_random << "\nMais sorte na proxima!";
    }

    return 0;
}