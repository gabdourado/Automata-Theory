# AFD — Teoria, Implementações e Testes

## Teoria

Em [`notes/`](notes/) estão as anotações sobre Autômatos Finitos Determinísticos, cobrindo:

- AFD com função de transição **total**
- AFD com função de transição **parcial**

Incluindo definições formais e pseudocódigos.

## Implementações

Os programas em [`implementations/`](implementations/) aceitam um AFD descrito em arquivo de texto e simulam sua execução. Os arquivos de entrada devem seguir exatamente a ordem apresentada, uma informação por linha:

### Formato de entrada para `AFD_Total.cpp`
```
<|Q|> <|Σ|>             número de estados e símbolos             e.g.: 3 2
<Q>                     estados separados por espaço             e.g.: 0 1 2
<Σ>                     símbolos separados por espaço            e.g.: a b
<|Q| x |Σ| transições>  uma por linha, no formato q a p          e.g.: 0 a 1
...
<q0>                    estado inicial                           e.g.: 0
<|F|> <F>               número de estados finais e os estados    e.g.: 1 2
<palavras>              uma por linha                            e.g.: aa
...
<fim>                   string que indica o fim dos testes
```

### Formato de entrada para `AFD_Partial.cpp`

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