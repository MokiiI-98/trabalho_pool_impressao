#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
    // Método para registrar mensagens simples
    void log(const std::string& message);

    // Método para registrar mensagens com separador
    void log_with_separator(const std::string& message);

private:
    std::mutex log_mutex; // Mutex para sincronizar o acesso ao log
};

#endif // LOGGER_H
