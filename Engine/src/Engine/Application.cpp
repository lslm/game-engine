#include "Application.h"

#include "Log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        WindowProps windowsProps = WindowProps("Game engine", 1280, 720);
        m_Window = std::unique_ptr<Window>(Window::Create(windowsProps));
        m_Window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
    }
    
    Application::~Application() {}
    
    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }
    
    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }
    
    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClose));
        
        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(event);
            if (event.IsHandled())
                break;
        }
    }
    
    void Application::Run() {
        ENGINE_CORE_INFO("GLFW initialized");
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            
            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }
    
    bool Application::onWindowClose(WindowCloseEvent& windowCloseEvent)
    {
        m_Running = false;
        return true;
    }

    void Application::EngineVersion() {
        printf("0.0.1");
    }
}
