/*
    Autor: Gabriel de Souza Dourado
    Repositório: Automata Theory
    Prática: DFA com função de transição total
    
    Instruções:
    
    1. Digitar o número de estados |Q| e o número de símbolos |Σ|
    
    2. Digitar os estados de Q, separados por espaço (e.g.: 1 2 3)
    
    3. Digitar os símbolos de Σ, separados por espaço (e.g.: a b)
    
    4. Digitar as |Q|×|Σ| transições, uma por linha (e.g.: 1 a 2) representando δ(1, a) = 2
    
    5. Digitar o estado inicial q0 (e.g.: 1)
    
    6. Digitar o número de estados de aceitação e depois os estados (e.g.: 2 1 3)
    
    7. Digitar o número de testes 
    
    8. Digitar as palavras a serem processadas uma por linha (e.g.: aba)
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

struct DFA {
    std::set<int>                       states;
    std::set<char>                      alphabet;
    std::map<std::pair<int,char>, int>  delta;
    int                                 initial;
    std::set<int>                       accepting;
};

bool simulate(const DFA& dfa, const std::string w) {
    int current = dfa.initial;
    for (char c : w)
        current = dfa.delta.at({current, c});
    return dfa.accepting.count(current) > 0;
}

int main() {
    DFA dfa;
    int n_states, n_symbols;

    std::cin >> n_states >> n_symbols;

    for (int i = 0; i < n_states; i++) {
        int s; std::cin >> s;
        dfa.states.insert(s);
    }

    for (int i = 0; i < n_symbols; i++) {
        char c; std::cin >> c;
        dfa.alphabet.insert(c);
    }

    for (int i = 0; i < n_states * n_symbols; i++) {
        int p, q; char sym;
        std::cin >> p >> sym >> q;
        dfa.delta[{p, sym}] = q;
    }

    std::cin >> dfa.initial;

    int f; std::cin >> f;
    for (int i = 0; i < f; i++) {
        int s; std::cin >> s;
        dfa.accepting.insert(s);
    }

    int num_tests;

    std::cin >> num_tests; 

    for (int i = 0; i < num_tests; i++) {
        std::string w;
        std::cin >> w;
        std::cout << (simulate(dfa, w) ? "aceita:" : "rejeita:");
        std::cout << " " << w << "\n";
    }

    return 0;
}