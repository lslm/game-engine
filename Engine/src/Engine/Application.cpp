#include "Application.h"

#include "Log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
    Application::Application()
    {
        WindowProps windowsProps = WindowProps("Game engine", 1280, 720);
        m_Window = std::unique_ptr<Window>(Window::Create(windowsProps));
    }
    
    Application::~Application() {}

    void Application::Run() {
        ENGINE_CORE_INFO("GLFW initialized");
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    void Application::EngineVersion() {
        printf("0.0.1");
    }
}
