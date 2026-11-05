# sync_car — Implementação Sync (Infraestrutura de Software)

Implementação das funções de sincronização para embarque de passageiros no METROREC, usando apenas `pthread_mutex` e `pthread_cond` (sem semáforos), com um único lock por `struct station` e sem busy-wait.

## Build

```
make
```

Gera o executável `sync_car`.

Para limpar:

```
make clean
```

## Executar

```
./sync_car
```

Roda o harness oficial de teste (`sync_car-runner.c`, não editável), que cria múltiplas threads de passageiros e de carros concorrentemente. Saída esperada termina em `Looks good!` se a sincronização estiver correta.

## Funções implementadas (`sync_car.c` / `sync_car.h`)

- `station_init(struct station *station)` — inicializa contadores, mutex e condition variables.
- `station_wait_for_car(struct station *station)` — chamada pelo passageiro: bloqueia até haver carro presente com vaga, reserva o assento.
- `station_on_board(struct station *station)` — chamada pelo passageiro após embarcar, sinaliza o carro quando todos os embarques em andamento terminaram.
- `station_load_car(struct station *station, int count)` — chamada pelo carro ao chegar com `count` vagas; libera os passageiros esperando e aguarda a condição de partida antes de retornar.

## Arquivos

| Arquivo | Descrição |
|---|---|
| `sync_car.h` | `struct station` e protótipos das 4 funções |
| `sync_car.c` | Implementação das 4 funções |
| `sync_car-runner.c` | Harness oficial de teste (fornecido pelo professor, não editado) |
| `Makefile` | Build (`make` / `make clean`) |
| `evidencias.log` | Log de terminal da execução dos testes |

## Ambiente

Desenvolvido e testado em WSL (Ubuntu). Compila com:

```
gcc -pthread -Wall -Wextra sync_car.c sync_car-runner.c -o sync_car
```

## Autor

Rafael Carrilho (rac4), CESAR School.
