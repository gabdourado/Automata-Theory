/*
    Autor: Gabriel de Souza Dourado
    Repositório: Automata Theory
    Prática: Simulando AFND com transições vazias com backtracking    
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

struct AFND {
    std::set<int>                                 states;
    std::set<char>                                alphabet;
    std::map<std::pair<int,char>, std::set<int>>  delta;
    int                                           initial;
    std::set<int>                                 accepting;
};

bool search(const AFND& afnd, const std::string& w, int q, int i, std::set<int> V) {
    if (i == (int)w.length()) {
        if (afnd.accepting.count(q) > 0) return true;

        if (afnd.delta.count({q, '-'}) > 0)
            for (int next : afnd.delta.at({q, '-'}))
                if (V.count(next) == 0) {
                    std::set<int> u = V;
                    u.insert(next);
                    if (search(afnd, w, next, i, u))
                        return true;
                }
        return false;
    }

    if (afnd.delta.count({q, w[i]}) > 0)
        for (int next : afnd.delta.at({q, w[i]}))
            if (search(afnd, w, next, i + 1, {}))
                return true;

    if (afnd.delta.count({q, '-'}) > 0)
        for (int next : afnd.delta.at({q, '-'}))
            if (V.count(next) == 0) {
                std::set<int> u = V;
                u.insert(next);
                if (search(afnd, w, next, i, u))
                    return true;
            }

    return false;
}

bool simulate(const AFND& afnd, const std::string& w) {
    if (search(afnd, w, afnd.initial, 0, {})) 
        return 1;
    else
        return 0;
}

int main() {
    AFND afnd;
    
    int s_st, n_sy; std::cin >> s_st >> n_sy;
    for (int i = 0; i < s_st; i++) {
        int s; std::cin >> s;
        afnd.states.insert(s);
    }

    for (int i = 0; i < n_sy; i++) {
        char c; std::cin >> c;
        afnd.alphabet.insert(c);
    }

    int t; std::cin >> t;
    for (int i = 0; i < t; i++) {
        int p, q; char sym;
        std::cin >> p >> sym >> q;
        afnd.delta[{p, sym}].insert(q);
    }

    std::cin >> afnd.initial;

    int f; std::cin >> f;
    for (int i = 0; i < f; i++) {
        int s; std::cin >> s;
        afnd.accepting.insert(s);
    }

    std::string w;
    while (std::cin >> w && w != "fim") {
        std::cout << (simulate(afnd, w) ? "aceita:" : "rejeita:");
        std::cout << " " << w << "\n";
    }

    return 0;
}