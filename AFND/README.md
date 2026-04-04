# AFND — Teoria, Implementações e Testes

## Teoria

Em [`notes/`](notes/) estão as anotações sobre Autômatos Finitos Não Determinísticos, cobrindo:

- AFND tradicionais
- AFDND com transições vazias

Incluindo definições formais e pseudocódigos.

## Implementações

Os programas em [`implementations/`](implementations/) aceitam um AFND descrito em arquivo de texto e simulam sua execução:

| Arquivo | Descrição |
|---|---|
| `AFND_BT.cpp` | Simula AFND usando Backtraking |
| `AFNDE_BT.cpp` | Simula AFND com transições vazias usando Backtracking |

## Testes

Os arquivos em [`implementations/inputs/`](implementations/inputs/) são entradas de teste, nomeadas conforme a linguagem reconhecida:

| Arquivo | Linguagem | Tipo | Programa |
|---|---|---|---|
| `IN1_AFND_BT.txt` | $L = \{w \in \{a,b\}^* \mid \text{ o penúltimo símbolo de } w \text{ é } a\}$ | Total | `AFND_BT.cpp` |
| `IN1_AFNDE_BT.txt` | $L = \{a^{n} \mid n \geq 0\} \cup \{b^{n} \mid n \geq 0\}$ | Parcial | `AFNDE_BT.cpp` |