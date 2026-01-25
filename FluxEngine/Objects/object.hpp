#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <string>
#include <vector>
#include "../Texture/texture.hpp"
#include "../Script/script.h"
#include "Vector/vec.h"
#include "Matrix/matrix.h"
#include "Math/math.h"

class Script;

class Object {
public:
    std::string name;
    vec3 position;
    vec3 rotation;
    vec3 scale;
    std::shared_ptr<Texture> texture;
    std::vector<std::shared_ptr<Script>> scripts;

    Object(const std::string& name = "Object") : name(name), position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {}

    mat4 getModelMatrix() const {
        mat4 model;
        model = fluxmath::translate(model, position);
        model = fluxmath::rotate(model, fluxmath::radians(rotation.x), vec3(1, 0, 0));
        model = fluxmath::rotate(model, fluxmath::radians(rotation.y), vec3(0, 1, 0));
        model = fluxmath::rotate(model, fluxmath::radians(rotation.z), vec3(0, 0, 1));
        model = fluxmath::scale(model, scale);
        return model;
    }

    void setTexture(const std::string& filePath) {
        texture = std::make_shared<Texture>();
        texture->setTexture(filePath);
    }

    void setTextureFrom(std::shared_ptr<Texture> tex) {
        texture = tex;
    }

    void bindTexture(unsigned int textureUnit = 0) {
        if (texture) {
            texture->bindTexture(textureUnit);
        }
    }

    void AddScript(const std::shared_ptr<Script>& script) {
        script->SetObject(this);
        scripts.push_back(script);
    }

    void UpdateScripts(float deltaTime) {
        for (auto& script : scripts) {
            if (script && script->isEnabled) {
                script->OnUpdate(deltaTime);
            }
        }
    }

    void StartScripts() {
        for (auto& script : scripts) {
            if (script && script->isEnabled) {
                script->OnStart();
            }
        }
    }
};
#endif
