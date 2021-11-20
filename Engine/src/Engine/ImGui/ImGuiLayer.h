#pragma once

#include "epch.h"
#include "Engine/Layer.h"

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
    };
}
