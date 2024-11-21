#pragma once
#include <queue> //
#include <mutex>  //semáforo
#include <condition_variable>
#include <string_view>
#include <string>

class Spool {
public:
    void print(std::string_view arquivo, int num_pags, int prioridade, int pid);
};

