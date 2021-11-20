#pragma once

#include "epch.h"
#include "Window.h"
#include "Engine/ApplicationEvent.h"
#include "LayerStack.h"

namespace Engine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void EngineVersion();
        void OnEvent(Event& event);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        
    private:
        bool onWindowClose(WindowCloseEvent& windowCloseEvent);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication();
}
