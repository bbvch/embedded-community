#pragma once

#include <string>
#include <string_view>
#include <deque>

class ReadStub
{
public:
    static constexpr int WOULDBLOCK{ -1 };
    static constexpr int ISEOF{ -2 };

    void setEOF();
    void write(std::string_view data);
    int read(std::string& buffer);

private:
    std::deque<std::string> m_buffers;
    bool m_EOF{ false };
};
