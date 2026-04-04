/*
    Autor: Gabriel de Souza Dourado
    Repositório: Automata Theory
    Prática: FNA com transições vazias com backtracking
    
    Instruções:
    
    1. Digitar o número de estados |Q| e o número de símbolos |Σ|
    
    2. Digitar os estados de Q, separados por espaço (e.g.: 1 2 3)
    
    3. Digitar os símbolos de Σ, separados por espaço (e.g.: a b)
    
    4. Digitar o número de transições δ (e.g.: 4)
    
    5. Digitar as transições uma por linha (e.g.: 1 a 2) representando δ(1, a) = 2 e 
    use um traço (-) para transições vazias (e.g.: 2 - 3) representando δ(2, ε) = 3
    
    5. Digitar o estado inicial q0 (e.g.: 1)
    
    6. Digitar o número de estados de aceitação e depois os estados (e.g.: 2 1 3)
    
    7. Digitar o número de testes 
    
    8. Digitar as palavras a serem processadas uma por linha (e.g.: aba)
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

struct NFA {
    std::set<int>                                 states;
    std::set<char>                                alphabet;
    std::map<std::pair<int,char>, std::set<int>>  delta;
    int                                           initial;
    std::set<int>                                 accepting;
};

bool search(const NFA& nfa, const std::string& w, int q, int i, std::set<int> V) {
    if (i == (int)w.length())
        return nfa.accepting.count(q) > 0;

    if (nfa.delta.count({q, w[i]}) > 0)
        for (int next : nfa.delta.at({q, w[i]}))
            if (search(nfa, w, next, i + 1, {}))
                return true;

    if (nfa.delta.count({q, '-'}) > 0)
        for (int next : nfa.delta.at({q, '-'}))
            if (V.count(next) == 0) {
                std::set<int> u = V;
                u.insert(next);
                if (search(nfa, w, next, i, u))
                    return true;
            }

    return false;
}

bool simulate(const NFA& nfa, const std::string& w) {
    if (search(nfa, w, nfa.initial, 0, {})) 
        return 1;
    else
        return 0;
}

int main() {
    NFA nfa;
    int n_states, n_symbols;

    std::cin >> n_states >> n_symbols;

    for (int i = 0; i < n_states; i++) {
        int s; std::cin >> s;
        nfa.states.insert(s);
    }

    for (int i = 0; i < n_symbols; i++) {
        char c; std::cin >> c;
        nfa.alphabet.insert(c);
    }

    int t; std::cin >> t;
    for (int i = 0; i < t; i++) {
        int p, q; char sym;
        std::cin >> p >> sym >> q;
        nfa.delta[{p, sym}].insert(q);
    }

    std::cin >> nfa.initial;

    int f; std::cin >> f;
    for (int i = 0; i < f; i++) {
        int s; std::cin >> s;
        nfa.accepting.insert(s);
    }

    int num_tests;

    std::cin >> num_tests; 

    for (int i = 0; i < num_tests; i++) {
        std::string w;
        std::cin >> w;
        std::cout << (simulate(nfa, w) ? "aceita:" : "rejeita:");
        std::cout << " " << w << "\n";
    }

    return 0;
}