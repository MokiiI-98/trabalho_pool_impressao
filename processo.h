#pragma once

#include <csignal>
#include <sys/types.h>
#include "spool.h"

class Processo {
private:
    pid_t pid{}; // Identificador do processo

public:
    explicit Processo(pid_t pid); // Construtor único

    void start(Spool &spool); // Método que inicia o processo, usa Spool
};
