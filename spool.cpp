#include <iostream>
#include "spool.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>


void Spool::print(std::string_view arquivo, int num_pags, int prioridade, int pid) {
    std::cout << "Spool recebendo do processo " << pid
              << " o arquivo " << arquivo
              << " de " << num_pags << " paginas, prioridade " << prioridade << "\n";
}

