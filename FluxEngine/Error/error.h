#ifndef ERROR_H
#define ERROR_H

#include <iostream>

class Error {
private:
    const char* engineINFO;
    const char* engineWARNING;
    const char* engineERROR;
    const char* engineCriticalERROR;

public:
    void addToInfoList(const char* receivedEngineINFO) { engineINFO = receivedEngineINFO; }
    void addToWarningList(const char* receivedEngineWARNING) { engineWARNING = receivedEngineWARNING; } 
    void addToErrorList(const char* receivedEngineERROR) { engineERROR = receivedEngineERROR; }
    void addToCriticalErrorList(const char* receivedEngineERROR) { engineERROR = receivedEngineERROR; }

    const char* getInfo();
    const char* getWarning();
    const char* getErrors();
    const char* getCriticalERROR();

    void printEngineInfo() {
        std::cout << engineINFO << std::endl;
    }

    void printEngineWarning() {
        std::cout << engineWARNING << std::endl;
    }

    void printEngineERROR() {
        std::cerr << engineERROR << std::endl;
    }

    void printCriticalEngineERROR() {
        std::cerr << engineERROR << std::endl;
        //Дописать КРИТИЧЕСКОЕ остановление движка(закрытие) 22.01.26 по МСК
    }
};

#endif