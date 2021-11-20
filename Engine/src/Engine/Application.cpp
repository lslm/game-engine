#include "Application.h"

#include "Log.h"

namespace Engine {
    Application::Application()
    {
        WindowProps windowsProps = WindowProps("Game engine", 1280, 720);
        m_Window = std::unique_ptr<DarwinWindow>(DarwinWindow::Create(windowsProps));
    }
    
    Application::~Application() {}

    void Application::Run() {
        ENGINE_CORE_INFO("GLFW initialized");
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    void Application::EngineVersion() {
        printf("0.0.1");
    }
}
