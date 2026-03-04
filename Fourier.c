#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <math.h>

#define NUM_ITERATIONS 100
#define NUM_TERMS 16

#define SHARED_MEMORY_KEY 12345
#define SEMAPHORE_KEY 54321
#define M_PI 3.14159265358979323846
#define A0 (2 * pow(M_PI, 2.0) / 3) + 10

double* shared_memory;
sem_t* semaphore;

void calculateFourierTerms(int start, int end) {
    double AnCosnx = 0.00;
    double BnSennx = 0.00;
    double An = 0.00;
    double Bn = 0.00;
    double term = 0.00;
    for (int x = start; x < end; x++) {
        AnCosnx = 0.00;
        BnSennx = 0.00;
        An = 0.00;
        Bn = 0.00;
        for (int n = 1; n <= NUM_ITERATIONS; n++) {
            An = (4 / pow(n, 2.0)) * pow(-1.0, n); 
            Bn = (4 / n) * pow(-1.0, n);
            AnCosnx = AnCosnx + (An * cos(x * n));
            BnSennx = BnSennx + (Bn * sin(x * n));
        }
        term = (A0/2) + AnCosnx + BnSennx;
        shared_memory[x] = term;
    }
}

int main() {
    // Creación de memoria compartida
    int shmid = shmget(SHARED_MEMORY_KEY, NUM_TERMS * sizeof(double), IPC_CREAT | 0666);
    shared_memory = (double*)shmat(shmid, NULL, 0);

    // Creación del semáforo
    semaphore = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0666, 1);

    // División del trabajo entre procesos hijos
    int num_processes = 4; // Número de procesos hijos
    int terms_per_process = NUM_TERMS / num_processes;

    for (int i = 0; i < num_processes; i++) {
        int start = i * terms_per_process;
        int end = (i + 1) * terms_per_process;

        if (fork() == 0) { // Proceso hijo
            calculateFourierTerms(start, end);
            sem_wait(semaphore); // Espera para acceder a la memoria compartida
            // Realiza la copia de los resultados calculados a la memoria compartida
            /*
            for (int j = start; j < end; j++) {
                shared_memory[j] = Copia el resultado desde el proceso hijo ;
            }
            */
            sem_post(semaphore); // Libera el acceso a la memoria compartida
            exit(0);
        }
    }

    // Espera a que todos los procesos hijos terminen
    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    // Realiza cualquier operación adicional con los resultados en shared_memory

    // Liberación de recursos
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    sem_unlink("/my_semaphore");

    return 0;
}