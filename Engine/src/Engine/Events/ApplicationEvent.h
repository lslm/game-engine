#pragma once

#include "Event.h"

namespace Engine
{
    class WindowResizeEvent :  public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
        unsigned int GetWidth()  const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: Width: " << m_Width << ", Heigh: " << m_Height;
            return ss.str();
        }
        
        static EventType GetStaticType()        { return EventType::WindowResize; }
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override    { return "WindowResize"; }
        
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
        
    private:
        unsigned int m_Width, m_Height;
    };
}
