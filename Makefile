## This file is subject to the terms and conditions defined in
# file 'LICENSE', which is part of Atom repository.
# 
# This work has been funded by:
# 
# University of Granada under grant number PPJIA-2023-25.\n
# Spanish 'Ministerio de Ciencia, Innovación y Universidades' under grants number PID2022-137461NB-C32 and PID2020-119478GB-I00.\n
# Spanish 'Ministerio de Universidades' as part of the program of mobility stays for professors and researchers in foreign higher education and research centers under grant number CAS22/00332.\n
# European Regional Development Fund (ERDF).
#
# @file Makefile
# @author Juan José Escobar Pérez and Jesús López Rodríguez
# @date 02/02/2024
# @brief File with the necessary rules to compile the project
# @copyright Atom (c) 2024 University of Granada

SRC = src
INC = include

NFEATURES = -D N_FEATURES=$(N_FEATURES)

all: build_mpi

build_mpi:
	mpic++ -O2 -o pso -Iinclude $(NFEATURES) $(SRC)/main.cpp $(SRC)/lector.cpp $(SRC)/pso.cpp $(SRC)/particula.cpp $(SRC)/parametro.cpp $(SRC)/paramlist.cpp $(SRC)/tinyxml2.cpp -fopenmp

clean:
	@\rm -rf pso
