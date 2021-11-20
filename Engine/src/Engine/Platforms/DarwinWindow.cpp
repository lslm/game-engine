#include "DarwinWindow.h"

#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

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
    
    static void GLFWErrorCallback(int error, const char* description)
    {
        ENGINE_CORE_ERROR("GLFW error ({0}): {1}", error, description);
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
            
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
        
        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        
        if (m_Window == nullptr)
            ENGINE_CORE_CRITICAL("Failed to initialize GLFW");
        
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        
        // initializes GLEW
        glewExperimental = GL_TRUE;
        glewInit();
        
        SetVSync(true);
        
        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            windowData.Width = width;
            windowData.Height = height;
            
            WindowResizeEvent windowResizeEvent(width, height);
            windowData.EventCallback(windowResizeEvent);
        });
        
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent windowCloseEvent;
            windowData.EventCallback(windowCloseEvent);
        });
        
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent keyPressedEvent(key, 0);
                    windowData.EventCallback(keyPressedEvent);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent keyReleasedEvent(key);
                    windowData.EventCallback(keyReleasedEvent);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent keyPressedEvent(key, 1);
                    windowData.EventCallback(keyPressedEvent);
                    break;
                }
            }
        });
        
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch(action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent mouseButtonPressedEvent(button);
                    windowData.EventCallback(mouseButtonPressedEvent);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent mouseButtonReleaseEvent(button);
                    windowData.EventCallback(mouseButtonReleaseEvent);
                    break;
                }
            }
        });
        
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset){
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent mouseScrolledEvent((float) xOffset, (float) yOffset);
            windowData.EventCallback(mouseScrolledEvent);
        });
        
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPosition, double yPosition){
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent mouseMovedEvent((float) xPosition, (float) yPosition);
            windowData.EventCallback(mouseMovedEvent);
        });
        
        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode){
            WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent keyTypedEvent(keycode);
            windowData.EventCallback(keyTypedEvent);
        });
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
