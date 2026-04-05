# AFND — Teoria, Implementações e Testes

## Teoria

Em [`notes/`](notes/) estão as anotações sobre Autômatos Finitos Não Determinísticos, cobrindo:

- AFND tradicionais
- AFND com transições vazias

Incluindo definições formais e pseudocódigos.

## Implementações

Os programas em [`implementations/`](implementations/) aceitam um AFND descrito em arquivo de texto e simulam sua execução.

Os arquivos de entrada devem seguir exatamente a ordem apresentada, uma informação por linha:

### Formato de entrada
```
<|Q|> <|Σ|>          número de estados e símbolos             e.g.: 3 2
<Q>                  estados separados por espaço             e.g.: 0 1 2
<Σ>                  símbolos separados por espaço            e.g.: a b
<|δ|>                número de transições                     e.g.: 5
<transições>         uma por linha, no formato q a p          e.g.: 0 a 1
...
<q0>                 estado inicial                           e.g.: 0
<|F|> <F>            número de estados finais e os estados    e.g.: 1 2
<palavras>           uma por linha                            e.g.: aa
...
<fim>                string que indica o fim dos testes
```

### Descrição dos Arquivos

| Arquivo | Descrição |
|---|---|
| `AFND_BT.cpp` | Simula AFND usando Backtraking |
| `AFNDE_BT.cpp` | Simula AFND com transições vazias usando Backtracking |

## Testes

Os arquivos em [`implementations/inputs/`](implementations/inputs/) são entradas de teste, nomeadas conforme a linguagem reconhecida:

| Arquivo | Linguagem | Tipo | Programa |
|---|---|---|---|
| `IN1_AFND_BT.txt` | Palavras sobre {a,b} onde o penúltimo símbolo é "a" | Backtracking | `AFND_BT.cpp` |
| `IN1_AFNDE_BT.txt` | Palavras formadas só por a's ou só por b's (incluindo vazia) | Backtracking + ε | `AFNDE_BT.cpp` |
| `IN2_AFNDE_BT.txt` | Palavras sobre {a,b} com quantidade par de a's | Backtracking + ε | `AFNDE_BT.cpp` |