#pragma once

#include "epch.h"
#include "Engine/Layer.h"
#include "ApplicationEvent.h"
#include "MouseEvent.h"
#include "KeyEvent.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizedEvent(WindowResizeEvent& e);
        
        float m_Time = 0.0f;
    };
}
