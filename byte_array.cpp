#include "byte_array.h"

ByteArray::ByteArray() : m_byteArray(new std::vector<uint8_t>) {};

ByteArray::ByteArray(size_t size, char ch) : m_byteArray(new std::vector<uint8_t>(size))
{
    for (std::vector<uint8_t>::size_type i = 0; i < m_byteArray->size(); ++i)
    {
        m_byteArray->push_back(ch);
    }
};