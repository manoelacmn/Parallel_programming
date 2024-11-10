
# Sincronização e Coordenação em Programação Paralela

Este projeto contém exemplos práticos em C para ilustrar conceitos de sincronização e coordenação em programação paralela e distribuída. Utilizando a biblioteca `pthread`, os exemplos abordam os conceitos de Leitores e Escritores, Barreiras, Sinais e Deadlocks.

## Estrutura do Projeto

- `readers.c`: Implementa o problema de Leitores e Escritores, gerenciando o acesso concorrente a um recurso compartilhado.
- `barriers.c`: Exemplo de barreira onde múltiplas threads precisam esperar umas pelas outras antes de prosseguir.
- `signals.c`: Utiliza sinais para comunicação entre threads.
- `deadlock.c`: Demonstra um cenário de deadlock intencional entre duas threads.

## Pré-requisitos

- **Compilador GCC**: Instale o GCC se ainda não tiver (comando `sudo apt install gcc` no Ubuntu).
- **Pthreads**: Certifique-se de que seu compilador está configurado para usar `pthread`, que geralmente está disponível por padrão no GCC.

## Como Compilar e Executar os Exemplos

Cada arquivo pode ser compilado e executado individualmente. Siga as instruções abaixo para cada exemplo.

### 1. Leitores e Escritores (`readers.c`)

O exemplo implementa controle de acesso para leitores e escritores usando semáforos.

```bash
gcc readers.c -o readers -lpthread
./readers
```

### 2. Barreiras (`barriers.c`)

Este exemplo demonstra a utilização de barreiras para sincronizar threads.

```bash
gcc barriers.c -o barriers -lpthread
./barriers
```

### 3. Sinais (`signals.c`)

O exemplo configura um manipulador de sinal para comunicação assíncrona entre threads.

```bash
gcc signals.c -o signals -lpthread
./signals
```

### 4. Deadlock (`deadlock.c`)

Demonstra uma situação de deadlock intencional. Ao executar, observe como as threads bloqueiam umas às outras.

```bash
gcc deadlock.c -o deadlock -lpthread
./deadlock
```

## Explicação dos Exemplos

### Leitores e Escritores
- **Descrição**: Múltiplos leitores acessam o recurso simultaneamente, mas apenas um escritor possui acesso exclusivo.
- **Objetivo**: Gerenciar acesso seguro a um recurso compartilhado, evitando condições de corrida.

### Barreiras
- **Descrição**: Barreiras sincronizam threads em pontos específicos, garantindo que todas avancem juntas.
- **Objetivo**: Demonstrar como sincronizar threads para completar etapas do processamento.

### Sinais
- **Descrição**: Utiliza sinais para permitir comunicação assíncrona entre threads.
- **Objetivo**: Mostrar como threads podem se comunicar e reagir a eventos.

### Deadlock
- **Descrição**: Um deadlock intencional onde duas threads esperam por recursos em ordens opostas, bloqueando-se mutuamente.
- **Objetivo**: Ilustrar o problema do deadlock e a importância da ordem de aquisição de recursos.

## Observações

Estes exemplos têm como objetivo ilustrar conceitos básicos de sincronização e coordenação. Em projetos maiores, recomenda-se utilizar técnicas avançadas de prevenção e detecção de deadlocks, bem como ferramentas de depuração para análise de condições de corrida e segurança de threads.



