FROM ubuntu:24.04

LABEL license="This file is subject to the terms and conditions defined in file 'LICENSE', which is part of Atom repository."

LABEL funding="This work has been funded by: \
               University of Granada under grant number PPJIA-2023-25. \
               Spanish 'Ministerio de Ciencia, Innovación y Universidades' under grants number PID2022-137461NB-C32 and PID2020-119478GB-I00. \
               Spanish 'Ministerio de Universidades' as part of the program of mobility stays for professors and researchers in foreign higher education and research centers under grant number CAS22/00332. \
               European Regional Development Fund (ERDF)."

LABEL file="Dockerfile"
LABEL author="Juan José Escobar Pérez and Jesús López Rodríguez"
LABEL date="19/07/2024"
LABEL brief="Dockerfile that build a multi-arch image of Atom"
LABEL copyright="Atom (c) 2024 University of Granada"

ENV TZ=Europe/Madrid
ENV DEBIAN_FRONTEND noninteractive

COPY Atom /root/Atom
WORKDIR /root/Atom

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone \
    && apt-get -y update \
    && apt-get -y upgrade \
    && apt-get -y dist-upgrade \
    && apt-get -y autoremove \
    && apt-get -y install g++ make libopenmpi-dev \
    && rm -rf /var/lib/apt/lists/* \
    && make -j N_FEATURES=3600

CMD mpirun --bind-to none --allow-run-as-root --map-by node --host localhost ./pso
