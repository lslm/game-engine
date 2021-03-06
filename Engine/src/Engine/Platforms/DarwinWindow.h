#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Window.h"
#include "Engine/Log.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace Engine
{
    class DarwinWindow : public Window
    {
    public:
        DarwinWindow(const WindowProps& props);
        virtual ~DarwinWindow();
        
        void OnUpdate() override;
        
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }
        
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
        
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
        
        GLFWwindow * m_Window;
        
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
}
