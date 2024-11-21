#include "logger.h"

// Implementação do método para registrar mensagens simples
void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << message << std::endl;
}

// Implementação do método para registrar mensagens com separador
void Logger::log_with_separator(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "--------------" << std::endl;
    std::cout << message << std::endl;
}
