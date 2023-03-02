#include "read_stub.h"

#include <iostream>

void ReadStub::setEOF()
{
	std::cout << "WRITING EOF" << std::endl;
	m_EOF = true;
}

void ReadStub::write(std::string_view data)
{
	std::cout << "WRITING: " << data << std::endl;
	m_buffers.emplace_back(data);
	m_EOF = false;
}

int ReadStub::read(std::string& buffer)
{
    if (m_buffers.empty())
    {
        return m_EOF ? ISEOF : WOULDBLOCK;
    }
    std::cout << "READING: " << m_buffers.front() << std::endl;
    buffer += m_buffers.front();
    auto readSize{ m_buffers.front().size() };
    m_buffers.pop_front();
    return readSize;
}
