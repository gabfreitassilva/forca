#include "dicionario.hpp"
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