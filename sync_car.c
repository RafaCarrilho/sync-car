// SPDX-License-Identifier: GPL-3.0
#include "sync_car.h"

void station_init(struct station *station) {
    station->embarcando = 0;
    station->esperando = 0;
    station->vagas = 0;

    pthread_mutex_init(&station->mutex, NULL);

    pthread_cond_init(&station->cond_passageiros, NULL);
    pthread_cond_init(&station->cond_carro, NULL);
}
