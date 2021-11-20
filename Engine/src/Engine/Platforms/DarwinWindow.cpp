#include "DarwinWindow.h"

namespace Engine
{
    static bool s_GLFWInitialized = false;
    
    Window* Window::Create(const WindowProps& props)
    {
        return new DarwinWindow(props);
    }
    
    DarwinWindow::DarwinWindow(const WindowProps& props)
    {
        Init(props);
    }
    
    DarwinWindow::~DarwinWindow()
    {
    }
    
    void DarwinWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        
        if (!s_GLFWInitialized)
        {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            
            // Defines the OpenGL profile functions to be used:
            // - Core (modern functions)
            // - Compatibility (includes both modern and deprecated functions)
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            s_GLFWInitialized = true;
        }
        
        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        
        if (m_Window == nullptr)
            ENGINE_CORE_CRITICAL("Failed to initialize GLFW");
        
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }
    
    void DarwinWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
    
    void DarwinWindow::OnUpdate()
    {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
    
    void DarwinWindow::SetVSync(bool enabled)
    {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        m_Data.VSync = enabled;
    }
    
    bool DarwinWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}
