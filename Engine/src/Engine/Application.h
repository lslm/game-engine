#pragma once

#include "Engine/Event.h"

namespace Engine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void EngineVersion();
    };

    Application* CreateApplication();
}
