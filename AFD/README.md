# AFD — Teoria, Implementações e Testes

## Teoria

Em [`notes/`](notes/) estão as anotações sobre Autômatos Finitos Determinísticos, cobrindo:

- AFD com função de transição **total**
- AFD com função de transição **parcial**

Incluindo definições formais e pseudocódigos.

## Implementações

Os programas em [`implementations/`](implementations/) aceitam um AFD descrito em arquivo de texto e simulam sua execução:

| Arquivo | Descrição |
|---|---|
| `AFD_Partial.cpp` | Simula AFD com função de transição parcial |
| `AFD_Total.cpp` | Simula AFD com função de transição total |

## Testes

Os arquivos em [`implementations/inputs/`](implementations/inputs/) são entradas de teste, nomeadas conforme a linguagem reconhecida:

| Arquivo | Linguagem | Tipo | Programa |
|---|---|---|---|
| `IN1_AFD_Total.txt` | Palavras sobre {a,b} que terminam com "ab" | Total | `AFD_Total.cpp` |
| `IN2_AFD_Total.txt` | Palavras sobre {0,1} com número par de 0's | Total | `AFD_Total.cpp` |
| `IN1_AFD_Parcial.txt` | Palavras sobre {a,b} que começam e terminam com o mesmo símbolo | Parcial | `AFD_Parcial.cpp` |
| `IN2_AFD_Parcial.txt` | Palavras sobre {a,b} que contêm "aa" como substring | Parcial | `AFD_Parcial.cpp` |