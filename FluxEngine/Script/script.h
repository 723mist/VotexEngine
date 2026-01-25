#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

class Object;

class Script {
public:
    virtual ~Script() = default;

    virtual void OnStart();
    virtual void OnUpdate(float deltaTime);
    virtual void OnDestroy();

    std::string name;
    bool isEnabled = true;

    Object* attachedObject = nullptr;

    void SetObject(Object* obj) { attachedObject = obj; }
};

#endif