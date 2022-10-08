#include "Game.hpp"

void Game::display_status(void) {
    forca = palavra_random;
    for(int i = 0; i < tamanho_palavra; i++) { forca[i] = '-'; }
    
    do {
        system("cls");
        cout << "Jogo da Forca" << '\n';
        cout << "Voce tem " << chance << " chances para acertar." << '\n';
        cout << forca << '\n';
        cout << "Letras erradas:\n";
        for(int i = 0; i < letra_errada.size(); i++) { cout << letra_errada[i] << " "; }
        cout << "\n\nDigite uma letra: "; cin >> letra_usuario;
        for(int i = 0; i < tamanho_palavra; i++) {
            if(letra_usuario == palavra_random[i]) {
                forca[i] = letra_usuario;
                acerto = true;
                vitoria++;
            }
        }
        if(acerto == false) {
            letra_errada.push_back(letra_usuario);
            chance--;
        }
        acerto = false;
    } while(chance > 0 && vitoria < tamanho_palavra);
}

void Game::end_game() {
    if(chance == 0) {
        system("cls");
        cout << "Jogo da Fora\n";
        cout << "Voce tem " << chance << " chances para acertar\n";
        cout << forca << '\n';
        cout << "Letras erradas: ";
        for(int i = 0; i < letra_errada.size(); i++) { cout << letra_errada[i] << " "; }
        cout << "\n\nInfelizmente suas chances acabaram... Mais sorte na proxima vez.\n";
    }
    if(vitoria == tamanho_palavra) {
        system("cls");
        cout << "Jogo da Forca\n";
        cout << "Voce tem " << chance << " chances para acertar.\n";
        cout << forca << '\n';
        cout << "Letras erradas:\n";
        for(int i = 0; i < letra_errada.size(); i++) { cout << letra_errada[i] << " "; }
        cout << "\n\nParabens!! Voce acertou a palavra...\n";
    }
}