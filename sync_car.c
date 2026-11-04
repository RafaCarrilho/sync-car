#include "sync_car.h"

void station_init(struct station *station) {
    station->embarcando = 0;
    station->esperando = 0;
    station->vagas = 0;
    station->carro_presente =0;

    pthread_mutex_init(&station->mutex, NULL);

    pthread_cond_init(&station->cond_passageiros, NULL);
    pthread_cond_init(&station->cond_carro, NULL);
}


void station_wait_for_car (struct station *station){
    
    pthread_mutex_lock(&station->mutex);
    station->esperando ++;


    while (station->carro_presente == 0 || station->vagas ==0){

        pthread_cond_wait(&station->cond_passageiros, &station->mutex);
    }

    station->esperando --;
    station->vagas --;
    station->embarcando ++;
    pthread_mutex_unlock(&station->mutex);

}