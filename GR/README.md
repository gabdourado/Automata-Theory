# AFND — Teoria, Implementações e Testes

## Teoria

Em [`notes/`](notes/) estão as anotações sobre Gramáticas Regulares, cobrindo:

- Definição de GR
- Conversão de GLUD para AFND-$\varepsilon$

## Implementações

O programa em [`implementations/`](implementations/) aceita uma GLUD descrito em arquivo de texto e simulam sua execução. 

### Formato de entrada

O arquivo de entrada deve seguir exatamente a ordem abaixo, uma informação por linha:

```
<|V|> <|T|>          número de não-terminais e terminais       e.g.: 2 2
<V>                  não-terminais separados por espaço        e.g.: S A
<T>                  terminais separados por espaço            e.g.: a b
<|P|>                número de produções                       e.g.: 4
<produções>          uma por linha, no formato A -> aB         e.g.: S -> aA
...                                                            e.g.: S -> b
<S>                  símbolo inicial                           e.g.: S
<palavras>           uma por linha                             e.g.: ab
...                                                            e.g.: ba
<fim>                string que indica o fim dos testes
```

### Convenções

Para funcionamento do programa, algumas convenções devem ser adotadas — idiota, eu sei. Veja abaixo:

1. Use letras maiúsculas para produções (e.g.: `A, B, C`)
2. Se o alfabeto for composto por letras, use minúsculas (e.g.: `a, b, c`)
3. Por ser uma GLUD, sempre escreva no formato padrão (e.g.: `A → aB`)
4. Use o símbolo `-` no caso de uma produção vazia (e.g.: `A → -`)


### Descrição dos Arquivos
| Arquivo | Descrição |
|---|---|
| `GLUD_BT.cpp` | Simula GLUD convertendo para um AFND-$\varepsilon$ e usando Backtracking |

## Testes

Os arquivos em [`implementations/inputs/`](implementations/inputs/) são entradas de teste, nomeadas conforme a linguagem reconhecida:

| Arquivo | Linguagem  | Programa |
|---|---|---|
| `IN1_GLUD_BT.txt` | Palavras sobre {a,b} terminadas em "b" | `GLUD_BT.cpp` |
| `IN2_GLUD_BT.txt` | Palavras sobre {a,b} com quantidade par de a's | `GLUD_BT.cpp` |
| `IN3_GLUD_BT.txt` | Palavras sobre {0,1} que começam e terminam com mesmo símbolo | `GLUD_BT.cpp` |
| `IN4_GLUD_BT.txt` | Palavras sobre {a,b} que contém "ab" como substring | `GLUD_BT.cpp` |