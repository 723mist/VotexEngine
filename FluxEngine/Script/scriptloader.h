#ifndef SCRIPT_LOADER_H
#define SCRIPT_LOADER_H

#include <functional>
#include <memory>
#include <unordered_map>
#include <string>
#include "script.h"

class ScriptLoader {
private:
    std::unordered_map<std::string, std::function<std::shared_ptr<Script>()>> scriptRegistry;
public:
    template<typename T>
    void RegisterScript(const std::string& scriptName) {
        scriptRegistry[scriptName] = []() {
            return std::make_shared<T>();
        };
    }

    std::shared_ptr<Script> LoadScript(const std::string& scriptName) {
        auto it = scriptRegistry.find(scriptName);
        if (it != scriptRegistry.end()) {
            return it->second();
        }

        return nullptr;
    }

    static ScriptLoader& GetInstance() {
        static ScriptLoader instance;
        return instance;
    }
};

#endif