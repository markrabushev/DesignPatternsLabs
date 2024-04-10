#pragma once
#include <string>

class Context {
public:
    Context(std::string& text) : m_text(text) {}
    std::string& GetText()
    {
        return m_text;
    }
    void SetText(const std::string& text)
    {
        m_text = text;
    }
private:
    std::string& m_text;
};