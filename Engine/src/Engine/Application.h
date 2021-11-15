#pragma once

#include <stdio.h>
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
