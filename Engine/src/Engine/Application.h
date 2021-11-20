#pragma once

#include "epch.h"
#include "Window.h"
#include "Engine/ApplicationEvent.h"

namespace Engine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void EngineVersion();
        void OnEvent(Event& event);
        
    private:
        bool onWindowClose(WindowCloseEvent& windowCloseEvent);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}
