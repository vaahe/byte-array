#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <vector>
#include <cstdint>
#include <ostream>
class ByteArray
{
public:
    ByteArray();
    ByteArray(size_t size, char ch);
    ByteArray(const ByteArray &other);
    ByteArray(ByteArray &&other);
    ~ByteArray();

public:
    // modificators
    void clear();
    void chop(size_t n);
    void resize(size_t size);

    ByteArray &append(char ch);
    ByteArray &append(const char *str);
    ByteArray &append(const ByteArray &);

    ByteArray &prepend(char ch);
    ByteArray &prepend(const char *str);
    ByteArray &prepend(const ByteArray &);

    ByteArray &fill(char ch, size_t size = 0);
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
    bool contains(char ch) const;
    int indexOf(char ch, size_t from = 0) const;

    // converters
    ByteArray toHex(char separator = '\0') const;
    ByteArray fromHex(const ByteArray &hexEncoded);

    // string manipulators
    ByteArray trimmed() const;

    // operators
    ByteArray &operator=(const ByteArray &other);
    ByteArray &operator=(ByteArray &&other) noexcept;
    friend std::ostream &operator<<(std::ostream &out, const ByteArray &byteArray);

private:
    std::vector<uint8_t> *m_byteArray;
};

#endif // !BYTE_ARRAY_H