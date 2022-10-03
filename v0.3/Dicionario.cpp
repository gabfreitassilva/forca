#include "Dicionario.hpp"

string dicionario() {
    string dicionario[30] {"apple", "rice", "dollar", "three", "planet", "space", "mars", "earth", "five", "month",
                           "visual", "bread", "kiss", "moon", "hospital", "restaurant", "interessting", "money",
                           "guide", "course", "automation", "windows", "hacker", "cracker", "python", "programming",
                           "linux", "fork", "outline", "spotify"};

    srand(time(0));
    int numero_palavra = rand()%30;
    string palavra = dicionario[numero_palavra];
    return palavra;
}