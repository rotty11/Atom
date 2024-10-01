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
 * @file knn.h
 * @author Juan José Escobar Pérez and Jesús López Rodríguez
 * @date 02/02/2024
 * @brief Function declarations of the KNN algorithm
 * @copyright Atom (c) 2024 University of Granada
 */

#ifndef KNN_H
#define KNN_H

#include <vector>
#include "lector.h"
using namespace std;


class KNN {
public:
    KNN(int k);
    void ejecutar();
    void mostrarResultados();

private:
    Lector * lector;
    vector<vector<double>> data_test;
    vector<vector<double>> data_training;
    vector<int> labels_test;
    vector<int> labels_training;
    double valor;
    int k_valor;

};


#endif
