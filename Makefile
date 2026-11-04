.PHONY: clean
sync_car: sync_car.c sync_car-runner.c sync_car.h
	gcc -pthread -Wall -Wextra sync_car.c sync_car-runner.c -o sync_car

clean:
	rm -f sync_car