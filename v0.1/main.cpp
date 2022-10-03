#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;

int main() {
    int numero_escolhido, tamanho_palavra, palavra_concluida {0};
    string dicionario[4] {"pera", "uva", "letra", "cavalo"};
    string palavra;
    char forca[tamanho_palavra], letra;

    cout << "Escolha um numero de 1 a 4: ";
    cin >> numero_escolhido;

    palavra = dicionario[numero_escolhido-1];
    tamanho_palavra = palavra.length();

    for (int i = 0; i < tamanho_palavra; i++) {
        forca[i] = '_';
    }

    cout << "A palavra escolhida tem " << tamanho_palavra << " letras.\n";
    cout << forca << '\n';

    loop:
        cout << "Digite uma letra: ";
        cin >> letra;
    
    system("cls");
    for (int i = 0; i < tamanho_palavra; i++) {
        if (palavra[i] == letra) {
            forca[i] = letra;
            palavra_concluida++;
        }
    }

    cout << "A palavra escolhida tem " << tamanho_palavra << " letras.\n";
    cout << forca << '\n';
    if (palavra_concluida == tamanho_palavra) {
        cout << "Palavra conluida!\n";
        return 0;
    }
    goto loop;

    return 0;
}