#include "processo.h"
#include "logger.h"
#include <iostream>
#include <random>
#include <thread>

// Logger global
Logger logger;

Processo::Processo(pid_t pid) : pid(pid) {}

// Função para gerar um número aleatório
int numero_aleatorio(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// Função para gerar um nome de arquivo aleatório
std::string gerar_nome_arquivo() {
    const std::string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const std::vector<std::string> extensoes = {".txt", ".cpp", ".jpg", ".png", ".pdf", ".docx"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> charDistrib(0, caracteres.size() - 1);
    std::uniform_int_distribution<> extDistrib(0, extensoes.size() - 1);

    std::string nome;
    for (int i = 0; i < 8; i++) {
        nome += caracteres[charDistrib(gen)];
    }
    nome += extensoes[extDistrib(gen)];
    return nome;
}

// Método start
void Processo::start(Spool &spool) {
    // Captura as variáveis por valor ou referência quando necessário
    std::thread t([this, &spool]() {
        // Usando logger para imprimir a mensagem inicial
        logger.log("Processo " + std::to_string(pid) + " iniciou.");

        for (int i = 0; i < numero_aleatorio(5, 10); i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(numero_aleatorio(0, 5000)));

            std::string nome_arquivo = gerar_nome_arquivo();
            // Usando logger para registrar envio de arquivos com separador
            logger.log_with_separator("Processo " + std::to_string(pid) + " enviando arquivo " + nome_arquivo + " ao spool.");

            spool.print(nome_arquivo, numero_aleatorio(1, 50), numero_aleatorio(1, 5), pid);
        }

        // Usando logger para imprimir a mensagem final
        logger.log("Processo " + std::to_string(pid) + " terminou.");
    });

    // Decisão de usar detach ou não: depende do comportamento esperado.
    t.detach(); // Permite que a thread rode independentemente
}
