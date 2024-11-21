#include "processo.h"
#include "impressora.h"
#include "spool.h"
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>

int main() {
    Spool spool;

    int qtdProcessos, qtdImpressoras;

    std::cout << "Digite a quantidade de processos: ";
    std::cin >> qtdProcessos;

    std::cout << "Digite a quantidade de impressoras: ";
    std::cin >> qtdImpressoras;

    // Criação de processos
    std::vector<Processo> processos;
    for (int i = 1; i <= qtdProcessos; ++i) {
        processos.emplace_back(i); //
    }

    for (int i = 1; i <= qtdProcessos; ++i) {
        processos.emplace_back(i); // Atribuindo IDs únicos sequencialmente
    }

    for (auto &processo : processos) {
        processo.start(spool); // Inicia os processos
    }

    //////////////////////
    // // Criação de impressouras
    // std::vector<Impressora> impressora;
    // for (int i = 1; i <= qtdImpressoras; ++i) {
    //     impressora.emplace_back(i); //
    // }
    //
    // for (int i = 1; i <= qtdImpressoras; ++i) {
    //     impressora.emplace_back(i); // Atribuindo IDs únicos sequencialmente
    // }
    //
    // for (auto &impressora : impressora) {
    //     impressora.start(spool); // Inicia os processos
    // }


    // Mantém o programa rodando para que as threads terminem
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}






// #include "processo.h"
// #include "impressora.h"
// #include "spool.h"
// #include <thread>
// #include <chrono>
//
// int main() {
//
//     Spool spool;
//
//     Processo p1(1);
//     Processo p2(2);
//     Processo p3(3);
//     Processo p4(4);
//
//     Impressora hp1(1);
//     Impressora hp2(2);
//
//     p1.start(spool);
//     p2.start(spool);
//     p3.start(spool);
//     p4.start(spool);
//
//     // substitua por um timeout
//     std::this_thread::sleep_for(std::chrono::seconds(10));
//
//     return 0;
// }
