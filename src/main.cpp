#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <string>

using namespace std;

void allreduce(int messageSize);
void mpi_hello();
void mpi_init();
void mpi_finalize();

int world_size = 0;
int world_rank = 0;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Message Size for Allreduce must be specified" << endl;
    } else {
        allreduce(stoi(argv[1]));
    }
    cout << argc << " " << argv[0] << endl;
    return 0;
}

void allreduce(int messageSize) {
    mpi_init();



    mpi_finalize();
}

void mpi_init() {
    MPI_Init(NULL, NULL);
}

void mpi_finalize() {
    MPI_Finalize();
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


