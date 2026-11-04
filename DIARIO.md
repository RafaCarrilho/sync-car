# Diário de Tentativas — sync_car (Implementação Sync)

Preenchido em ordem cronológica, batendo com `evidencias.log`. Formato do Guia de Relatórios: # | Estratégia | O que tentei | Resultado | Hipótese/Causa (se falhou) | Quando | Evidência.

| # | Estrat. | O que tentei | Resultado | Hipótese/Causa | Quando | Evidência |
|---|---------|--------------|-----------|-----------------|--------|-----------|
| 1 | S1 | Desenhar `struct station` (3 contadores: esperando, vagas, embarcando; 1 mutex; 2 condvars: cond_passageiros, cond_carro) | OK — justificada antes de codar (2 condvars pq signal numa condvar única arriscaria acordar a thread errada) | — | 03/11 21:25 | DIARIO + conversa com Claude |
| 2 | S1 | Primeira versão de `station_init(struct station station)` (parâmetro por valor) + `cond_passageiros` inicializada duas vezes | Erro, não commitado | Confundiu assinatura com `station_init` tomando a struct por cópia; copy-paste sem trocar `cond_passageiros`→`cond_carro` na segunda `pthread_cond_init` | 03/11 21:37 | revisão manual (sem compilar essa versão) |
| 3 | S1 | Corrigido: `station_init(struct station *station)`, `->` em vez de `.`, segundo `cond_init` apontando pra `cond_carro` | OK — compila sem warnings (`gcc -Wall -Wextra -c sync_car.c`) | — | 03/11 21:39 | `evidencias.log` (linhas iniciais) |

## Estratégias

| Estrat. | Nome curto | Contexto | Motivo da troca |
|---------|-----------|----------|------------------|
| S1 | Contadores + 2 condvars | Abordagem principal desde o início: struct com 3 inteiros, 1 mutex, 2 condition variables separadas por "assunto" (passageiro vs. carro) | — (ainda não trocamos de estratégia) |
