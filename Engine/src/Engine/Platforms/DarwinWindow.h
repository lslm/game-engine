#pragma once

#include <iostream>

#include <GLFW/glfw3.h>
#include "Log.h"

namespace Engine
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;
        
        WindowProps(const std::string& title = "Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
                    : Title(title), Width(width), Height(height) {}
                    
    };
    
    class DarwinWindow
    {
    public:
        //using EventCallbackFn = std::function<void(Event&)>;
        DarwinWindow(const WindowProps& props);
        
        virtual ~DarwinWindow();
        
        void OnUpdate();
        static DarwinWindow* Create(const WindowProps& props);
        inline unsigned int GetWidth() const { return m_Data.Width; }
        inline unsigned int GetHeight() const { return m_Data.Height; }
        
        ////inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled);
        bool IsVSync() const;
        
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
        
        GLFWwindow * m_Window;
        
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            
            //EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
}
