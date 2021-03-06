#include "Application.h"

#include "Log.h"
#include <GLFW/glfw3.h>

namespace Engine {
#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)
    
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
    }
    
    Application::~Application() {}
    
    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }
    
    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
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
            glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
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
