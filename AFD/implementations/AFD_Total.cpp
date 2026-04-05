/*
    Autor: Gabriel de Souza Dourado
    Repositório: Automata Theory
    Prática: Simulando AFD com função de transição total
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

struct AFD {
    std::set<int>                       states;
    std::set<char>                      alphabet;
    std::map<std::pair<int,char>, int>  delta;
    int                                 initial;
    std::set<int>                       accepting;
};

bool simulate(const AFD& afd, const std::string w) {
    int current = afd.initial;
    std::string word = (w == "&") ? "" : w;
    for (char c : word)
        current = afd.delta.at({current, c});
    return afd.accepting.count(current) > 0;
}

int main() {
    AFD afd;
    int n_st, n_sy;

    std::cin >> n_st >> n_sy;

    for (int i = 0; i < n_st; i++) {
        int s; std::cin >> s;
        afd.states.insert(s);
    }

    for (int i = 0; i < n_sy; i++) {
        char c; std::cin >> c;
        afd.alphabet.insert(c);
    }

    for (int i = 0; i < n_st * n_sy; i++) {
        int p, q; char sym;
        std::cin >> p >> sym >> q;
        afd.delta[{p, sym}] = q;
    }

    std::cin >> afd.initial;

    int f; std::cin >> f;
    for (int i = 0; i < f; i++) {
        int s; std::cin >> s;
        afd.accepting.insert(s);
    }

    std::string w;
    while (std::cin >> w && w != "fim") {
        std::cout << (simulate(afd, w) ? "aceita:" : "rejeita:");
        std::cout << " " << w << "\n";
    }

    return 0;
}