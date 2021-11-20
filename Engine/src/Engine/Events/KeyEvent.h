#include "Event.h"

namespace Engine
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        
        virtual int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }
    
    protected:
        KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
        
        int m_KeyCode;
    };
    
    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}
        
        inline int GetRepeatCount() const { return m_RepeatCount; }
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        
        static EventType GetStaticType()        { return EventType::KeyPressed; }
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override    { return "KeyPressed"; }
    
    private:
        int m_RepeatCount;
    };

}
