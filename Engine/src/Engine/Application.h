#pragma once

#include "epch.h"
#include "Window.h"
#include "LayerStack.h"
#include "Engine/Events/ApplicationEvent.h"

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
        
        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        static Application* s_Instance;
    
        bool onWindowClose(WindowCloseEvent& windowCloseEvent);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication();
}
