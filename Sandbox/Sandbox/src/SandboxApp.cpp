#include "Engine.h"

class Sandbox : public Engine::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

Engine::Application* Engine::CreateApplication()
{
    INFO_LOG("Starting Sandbox");
    return new Sandbox();
    INFO_LOG("Sandbox finished");
}
