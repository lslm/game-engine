#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
    ExampleLayer() : Layer("Example") {}
    
    void OnUpdate() override
    {
        INFO_LOG("ExampleLayer::Update");
    }
    
    void OnEvent(Engine::Event& event) override
    {
        TRACE_LOG("{0}", event);
    }
};

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Engine::ImGuiLayer());
    }
    ~Sandbox() {}
};

Engine::Application* Engine::CreateApplication()
{
    INFO_LOG("Starting Sandbox");
    return new Sandbox();
    INFO_LOG("Sandbox finished");
}
