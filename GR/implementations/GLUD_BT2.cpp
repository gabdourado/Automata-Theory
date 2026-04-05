/*
    Autor: Gabriel de Souza Dourado
    Repositório: Automata Theory
    Prática: Conversão de GRUD para AFND e simulação com backtracking (usando o algoritmo 2)
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

struct GLUD {
    std::set<char>                                 nonTerminals;
    std::set<char>                                 terminals;
    std::map<char, std::set<std::pair<char,char>>> productions;
    char                                           startSymbol;
};

struct AFND {
    std::set<int>                                 states;
    std::set<char>                                alphabet;
    std::map<std::pair<int,char>, std::set<int>>  delta;
    int                                           initial;
    std::set<int>                                 accepting;
};

AFND GLUD_to_AFND(const GLUD& glud) {
    AFND afnd;

    afnd.alphabet = glud.terminals;

    std::map<char, int> stateId;
    int id = 0;
    for (const auto& non_terminal : glud.nonTerminals)
        stateId[non_terminal] = id++;

    int finalState = id++;
    afnd.states = {};
    for (const auto& [nt, sid] : stateId)
        afnd.states.insert(sid);
    
    afnd.states.insert(finalState);
    afnd.accepting.insert(finalState);

    afnd.initial = stateId.at(glud.startSymbol);

    for (const auto& [left_prod, prods] : glud.productions) {
        for(const auto& [terminal, non_terminal]: prods) {
            if(non_terminal != '&') 
                afnd.delta[{stateId[left_prod], terminal}].insert(stateId[non_terminal]);
            else {
                if(terminal == '&')
                    afnd.accepting.insert(stateId[left_prod]);
                else
                    afnd.delta[{stateId[left_prod], terminal}].insert(finalState); 
            }       
        }
    }
    return afnd;
}

bool search(const AFND& afnd, const std::string& w, int q, int i, std::set<int> V) {
    if (i == (int)w.length()) 
        return afnd.accepting.count(q) > 0;

    if (afnd.delta.count({q, w[i]}) > 0)
        for (int next : afnd.delta.at({q, w[i]}))
            if (search(afnd, w, next, i + 1, {}))
                return true;

    if (afnd.delta.count({q, '&'}) > 0)
        for (int next : afnd.delta.at({q, '&'}))
            if (V.count(next) == 0) {
                std::set<int> u = V;
                u.insert(next);
                if (search(afnd, w, next, i, u))
                    return true;
            }

    return false;
}

bool simulate(const AFND& afnd, const std::string& w) {

    std::string word = (w == "&") ? "" : w;
    if (search(afnd, word, afnd.initial, 0, {})) 
        return 1;
    else
        return 0;
}

int main() {
    GLUD glud;

    int n_nt, n_t; std::cin >> n_nt >> n_t;
    for (int i = 0; i < n_nt; i++) {
        char nt; std::cin >> nt;
        glud.nonTerminals.insert(nt);
    }

    for (int i = 0; i < n_t; i++) {
        char t; std::cin >> t;
        glud.terminals.insert(t);
    }

    int n_p; std::cin >> n_p;
    for(int i = 0; i < n_p; i++) {
        char lp; std::string arrow, rp;
        std::cin >> lp >> arrow >> rp;
        
        if(rp == "&")
            glud.productions[lp].insert({'&', '&'});
        else if (rp.size() == 1) {
           if (isupper(rp[0]))
                glud.productions[lp].insert({'&', rp[0]});
            else 
                glud.productions[lp].insert({rp[0], '&'});
        } else
            glud.productions[lp].insert({rp[0], rp[1]});
    }

    std::cin >> glud.startSymbol;

    AFND afnd_equival = GLUD_to_AFND(glud);
    
    std::string w;
    while (std::cin >> w && w != "fim") {
        std::cout << (simulate(afnd_equival, w) ? "aceita:" : "rejeita:");
        std::cout << " " << w << "\n";
    }

    return 0;
}