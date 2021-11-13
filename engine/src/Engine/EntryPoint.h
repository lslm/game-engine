#pragma once

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
    printf("Starting engine");
    
    auto application = Engine::CreateApplication();
    application->Run();
    delete application;
    
    return 0;
}
