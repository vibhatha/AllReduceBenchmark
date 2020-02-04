#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <string>
#include "Initializer.h"
#include "Util.h"

using namespace std;

void allReduce(int messageSize);

void mpi_hello();

void mpi_init();

void mpi_finalize();

void print(double *message, int size);

double *init_message(int message_size);

int world_size = 0;
int world_rank = 0;
const int repitition = 10;
bool log = false;
string save_file = "";

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Message Size for Allreduce must be specified" << endl;
    } else {
        save_file = argv[2];
        allReduce(stoi(argv[1]));
    }

    return 0;
}

void allReduce(int messageSize) {
    mpi_init();
    if (world_rank == 0) {
        cout << "Allreduce test on Message Size [" << messageSize << "]" << endl;
    }

    double *local_message = init_message(messageSize);
    double *global_message = init_message(messageSize);
    double t1, t2;

    if(world_rank == 0 && log) {
        Util u = Util();
        u.print1DMatrix(local_message, messageSize);
    }

    t1 = MPI_Wtime();
    for (int i = 0; i < repitition; ++i) {
        MPI_Allreduce(local_message, global_message, messageSize, MPI_DOUBLE, MPI_SUM,
                      MPI_COMM_WORLD);
    }
    t2 = MPI_Wtime();

    double elapsed_time = t2 - t1;
    double average_time = elapsed_time / (float) repitition;

    if (world_rank == 0) {
        cout << messageSize << ", " << average_time << ", file: " << save_file << endl;
        Util u = Util();
        u.summary(save_file, world_size, messageSize, average_time);
    }



    mpi_finalize();
}

void mpi_init() {
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
}

void mpi_finalize() {
    MPI_Finalize();
}

double *init_message(int message_size) {
    Initializer initializer;
    double *wglobal = initializer.zeroWeights(message_size);
    return wglobal;
}


void mpi_hello() {
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment. No more MPI calls can be made after this
    MPI_Finalize();
}

void print(double *message, int size) {
    for (int i = 0; i < size; i++) {
        cout << message[i] << " ";
    }
    cout << endl;
}




