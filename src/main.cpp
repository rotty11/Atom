/**
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of Atom repository.
 *
 * This work has been funded by:
 *
 * University of Granada under grant number PPJIA-2023-25.\n
 * Spanish 'Ministerio de Ciencia, Innovación y Universidades' under grants number PID2022-137461NB-C32 and PID2020-119478GB-I00.\n
 * Spanish 'Ministerio de Universidades' as part of the program of mobility stays for professors and researchers in foreign higher education and research centers under grant number CAS22/00332.\n
 * European Regional Development Fund (ERDF).
 *
 * @file main.cpp
 * @author Juan José Escobar Pérez and Jesús López Rodríguez
 * @date 02/02/2024
 * @brief A parallel and distributed Binary Particle Swarm Optimization (BPSO) algorithm to EEG classification
 * @copyright Atom (c) 2024 University of Granada
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#include "lector.h"
#include "pso.h"
#include "omp.h"
#include "paramlist.h"
#include <mpi.h>

using namespace std;

int main (int argc, char* argv[]){

    int numprocs, rank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);

    //printf("Hybrid: Hello from process %d/%d on %s\n", rank, numprocs, processor_name);

    //MPI::Init_thread(MPI_THREAD_MULTIPLE);

    
    
    Paramlist * lista;
    if (argc==1){
        lista = Paramlist::getInstance();
    }
    else{
        lista = Paramlist::getInstance(argc, argv);
    }

    //cout << "N hebras" << lista->getValor("-nH") << endl;

    srand((uint) time(NULL) + stoi(lista->getValor("MPIrank")));

    PSO mi_pso = PSO();
    double time_inicio;
    double time;
    if(stoi(lista->getValor("MPIrank"))==0){
        //cout << "Master tamanio: " << lista->getValor("MPIsize") << endl << flush;
        mi_pso.crearCumulo();
        time_inicio = omp_get_wtime();
        mi_pso.ejecutar();
        time = omp_get_wtime() - time_inicio;
        cout << "Execution time (s):" << endl << time << endl;
    }
    else {
        //cout << "Worker: " << lista->getValor("MPIrank") << endl << flush;
        mi_pso.valorar();
    }

    
    //mi_pso.mostrarResultados();


    MPI::Finalize();

    return 0;
}
