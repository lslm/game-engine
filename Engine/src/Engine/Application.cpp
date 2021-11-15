#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Log.h"

namespace Engine {
    Application::Application() {}
    Application::~Application() {}

    void Application::Run() {
        KeyPressedEvent e(1, 1);
        ENGINE_CORE_TRACE(e);
        while (true) {}
    }

    void Application::EngineVersion() {
        printf("0.0.1");
    }
}
