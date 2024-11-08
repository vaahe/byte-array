#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <vector>
#include <cstdint>
#include <ostream>
class ByteArray
{
public:
    ByteArray();
    ByteArray(size_t size, uint8_t ch);
    ByteArray(const ByteArray &other);
    ByteArray(ByteArray &&other) noexcept;
    ~ByteArray();

public:
    // modificators
    void clear();
    void chop(size_t n);
    void resize(size_t size);

    ByteArray &append(uint8_t value);
    ByteArray &append(const char *str);
    ByteArray &append(const ByteArray &other);

    ByteArray &prepend(uint8_t value);
    ByteArray &prepend(const char *str);
    ByteArray &prepend(const ByteArray &);

    ByteArray &fill(uint8_t value, size_t size = 0);
    ByteArray &remove(size_t pos, size_t len);

    // accessors
    char *data();
    const char *data() const;
    ByteArray left(size_t len) const;
    ByteArray right(size_t len) const;
    ByteArray mid(size_t pos, size_t len = 0) const;

    // informators
    size_t size() const;
    bool isEmpty() const;
    bool contains(uint8_t value) const;
    int indexOf(uint8_t value, size_t from = 0) const;

    // converters
    ByteArray toHex(char separator = '\0') const;
    static ByteArray fromHex(const ByteArray &hexEncoded);

    // string manipulators
    ByteArray trimmed() const;
    ByteArray toUpper() const;
    ByteArray toLower() const;

    // operators
    ByteArray &operator=(const ByteArray &other);
    ByteArray &operator=(ByteArray &&other) noexcept;
    friend std::ostream &operator<<(std::ostream &out, const ByteArray &byteArray);

    // helpers
    static uint8_t hexCharToByte(uint8_t hexChar);

private:
    std::vector<uint8_t> *m_byteArray;
};

#endif // !BYTE_ARRAY_H