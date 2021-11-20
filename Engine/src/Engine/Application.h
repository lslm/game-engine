#pragma once

#include "epch.h"

#include "Engine/DarwinWindow.h"

namespace Engine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void EngineVersion();
        
    private:
        std::unique_ptr<DarwinWindow> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}
