#include "byte_array.h"
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstring>

ByteArray::ByteArray() : m_byteArray(new std::vector<uint8_t>) {};

ByteArray::ByteArray(size_t size, uint8_t ch) : m_byteArray(new std::vector<uint8_t>(size, ch)) {};

ByteArray::ByteArray(const ByteArray &other) : m_byteArray(other.m_byteArray)
{
    std::cout << "copy ctor" << std::endl;
}

ByteArray::ByteArray(ByteArray &&other) noexcept : m_byteArray(other.m_byteArray)
{
    m_byteArray = nullptr;
    std::cout << "move ctor" << std::endl;
}

ByteArray::~ByteArray()
{
    delete m_byteArray;
    m_byteArray = nullptr;
}

void ByteArray::chop(size_t n)
{
    if (m_byteArray && n <= m_byteArray->size())
    {
        m_byteArray->resize(m_byteArray->size() - n);
    }
}

void ByteArray::clear()
{
    if (m_byteArray)
    {
        m_byteArray->clear();
    }
}

void ByteArray::resize(size_t size)
{
    if (m_byteArray && size != m_byteArray->size())
    {
        m_byteArray->resize(size);
    }
}

ByteArray &ByteArray::append(uint8_t value)
{
    m_byteArray->push_back(value);

    return *this;
}

ByteArray &ByteArray::append(const char *str)
{
    if (str)
    {
        int len = std::strlen(str);

        for (int i = 0; i < len; ++i)
        {
            m_byteArray->insert(m_byteArray->end(), str[i]);
        }
    }

    return *this;
}

ByteArray &ByteArray::append(const ByteArray &other)
{
    if (m_byteArray && !other.m_byteArray->empty())
    {
        const auto begin = other.m_byteArray->begin();
        const auto end = other.m_byteArray->end();
        m_byteArray->insert(m_byteArray->end(), begin, end);
    }

    return *this;
}

ByteArray &ByteArray::prepend(uint8_t value)
{
    m_byteArray->insert(m_byteArray->begin(), value);

    return *this;
}

ByteArray &ByteArray::prepend(const char *str)
{
    if (str)
    {
        int len = std::strlen(str);
        m_byteArray->insert(m_byteArray->begin(), str, str + len);
    }

    return *this;
}

ByteArray &ByteArray::prepend(const ByteArray &other)
{
    if (m_byteArray && !other.m_byteArray->empty())
    {
        const auto begin = other.m_byteArray->begin();
        const auto end = other.m_byteArray->end();

        m_byteArray->insert(m_byteArray->begin(), begin, end);
    }

    return *this;
}

ByteArray &ByteArray::fill(uint8_t value, size_t size)
{
    if (size == 0)
    {
        size = m_byteArray->size();
    }

    m_byteArray->assign(size, value);

    return *this;
}

ByteArray &ByteArray::remove(size_t pos, size_t len)
{
    if (pos < m_byteArray->size())
    {
        m_byteArray->erase(m_byteArray->begin() + pos, m_byteArray->begin() + pos + len);
    }

    return *this;
}

size_t ByteArray::size() const
{
    return m_byteArray->size();
}

ByteArray &ByteArray::operator=(const ByteArray &other)
{
    if (this != &other)
    {
        delete m_byteArray;
        m_byteArray = new std::vector<uint8_t>(*other.m_byteArray);
        std::cout << "copy assignment operator" << std::endl;
    }

    return *this;
}

ByteArray &ByteArray::operator=(ByteArray &&other) noexcept
{
    if (this != &other)
    {
        delete m_byteArray;
        m_byteArray = other.m_byteArray;
        other.m_byteArray = nullptr;
        std::cout << "move assignment operator" << std::endl;
    }

    return *this;
}

int ByteArray::indexOf(uint8_t value, size_t from) const
{
    if (from >= m_byteArray->size())
    {
        return -1;
    }

    auto it = std::find(m_byteArray->begin() + from, m_byteArray->end(), value);

    return it - m_byteArray->begin();
}

std::ostream &operator<<(std::ostream &os, const ByteArray &byteArray)
{
    for (uint8_t i = 0; i < byteArray.m_byteArray->size(); ++i)
    {
        os << static_cast<char>(byteArray.m_byteArray->at(i));
    }

    return os;
}

// accessors
char *ByteArray::data()
{
    return reinterpret_cast<char *>(m_byteArray->data());
}

const char *ByteArray::data() const
{
    return reinterpret_cast<const char *>(m_byteArray->data());
}

ByteArray ByteArray::left(size_t len) const
{
    ByteArray byteArray;

    if (len == 0 || len > size())
    {
        return byteArray;
    }

    std::vector<uint8_t>::iterator begin = m_byteArray->begin();

    byteArray.m_byteArray->assign(begin, begin + len);

    return byteArray;
}

ByteArray ByteArray::right(size_t len) const
{
    ByteArray byteArray;

    if (len == 0 || len > size())
    {
        return byteArray;
    }

    std::vector<uint8_t>::iterator end = m_byteArray->end();

    byteArray.m_byteArray->assign(end - len, end);

    return byteArray;
}

ByteArray ByteArray::mid(size_t pos, size_t len) const
{
    ByteArray byteArray;

    if (pos == 0 || pos > size())
    {
        return byteArray;
    }

    std::vector<uint8_t>::iterator start = m_byteArray->begin() + pos;

    byteArray.m_byteArray->assign(start, start + len);

    return byteArray;
}

// informators
bool ByteArray::isEmpty() const
{
    return size() > 0 ? false : true;
}

bool ByteArray::contains(uint8_t value) const
{
    auto begin = m_byteArray->begin();
    auto end = m_byteArray->end();
    auto it = std::find(begin, end, value);

    return it != end;
}

// converters
ByteArray ByteArray::toHex(char separator) const
{
    ByteArray result;

    size_t hexLength = m_byteArray->size() * (separator ? 3 : 2);
    result.m_byteArray->reserve(hexLength);

    for (size_t i = 0; i < m_byteArray->size(); ++i)
    {
        uint8_t byte = m_byteArray->at(i);
        char hex[3];
        std::sprintf(hex, "%02x", byte);

        result.m_byteArray->push_back(static_cast<uint8_t>(hex[0]));
        result.m_byteArray->push_back(static_cast<uint8_t>(hex[1]));

        if (separator && i < m_byteArray->size() - 1)
        {
            result.m_byteArray->push_back(static_cast<uint8_t>(separator));
        }
    }

    return result;
}

ByteArray ByteArray::fromHex(const ByteArray &hexEncoded)
{
    ByteArray result;

    if (hexEncoded.m_byteArray->size() % 2 != 0)
    {
        return result;
    }

    result.m_byteArray->reserve(hexEncoded.m_byteArray->size() / 2);

    std::cout << "index: " << hexEncoded.data() << std::endl;
    for (size_t i = 0; i < hexEncoded.m_byteArray->size(); i += 2)
    {
        uint8_t highNibble = hexEncoded.m_byteArray->at(i);
        uint8_t lowNibble = hexEncoded.m_byteArray->at(i + 1);

        uint8_t byte = (hexCharToByte(highNibble) << 4) | hexCharToByte(lowNibble);

        result.m_byteArray->push_back(byte);
    }

    return result;
}

uint8_t ByteArray::hexCharToByte(uint8_t hexChar)
{
    if (hexChar >= '0' && hexChar <= '9')
        return hexChar - '0';
    if (hexChar >= 'A' && hexChar <= 'F')
        return hexChar - 'A' + 10;
    if (hexChar >= 'a' && hexChar <= 'f')
        return hexChar - 'a' + 10;
    return 0;
}

// string manipulators
ByteArray ByteArray::trimmed() const
{
    ByteArray byteArray;
    byteArray.m_byteArray->reserve(m_byteArray->size());

    std::copy_if(m_byteArray->begin(), m_byteArray->end(), std::back_inserter(*byteArray.m_byteArray), [](uint8_t val)
                 { return val != ' '; });

    return byteArray;
}

ByteArray ByteArray::toLower() const
{
    ByteArray byteArray;
    byteArray.m_byteArray->reserve(m_byteArray->size());

    std::transform(m_byteArray->begin(), m_byteArray->end(), std::back_inserter(*byteArray.m_byteArray), [](uint8_t val)
                   { return static_cast<char>(std::tolower(val)); });

    return byteArray;
}

ByteArray ByteArray::toUpper() const
{
    ByteArray byteArray;
    byteArray.m_byteArray->reserve(m_byteArray->size());

    std::transform(m_byteArray->begin(), m_byteArray->end(), std::back_inserter(*byteArray.m_byteArray), [](uint8_t val)
                   { return static_cast<char>(std::toupper(val)); });

    return byteArray;
}