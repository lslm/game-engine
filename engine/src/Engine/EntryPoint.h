#pragma once

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
    Engine::Log::Init();
    ENGINE_CORE_WARN("Initializing engine");
    
    auto application = Engine::CreateApplication();
    INFO_LOG("Engine initialized");
    application->Run();
    delete application;
    
    return 0;
}
