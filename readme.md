# **Implementation of ByteArray in C++**

## **Overview**

A `ByteArray` in C++ is a sequence or collection of bytes, often used to handle
binary data, manage raw memory, or work with data streams like files, network
packets, or encoded data.

## Implementation in C++

In C++, the `std::vector<uint8_t>` is a popular choice for a dynamic
`ByteArray`, while `std::array<uint8_t, N>` provides a fixed-size alternative.

### **Here are the descriptions of each method implemented in this project:**

- `append` – Adds data to the end of the byte array.
- `prepend` – Adds data to the beginning of the byte array.
- `remove` – Removes a specified number of bytes starting from a given index.
- `mid` – Returns a part of the byte array from a specific index and length.
- `size` – Gets the number of bytes in the byte array.
- `clear` – Empties the byte array.
- `contains` – Checks if the byte array contains the specified data.
- `indexOf` – Finds the index of the first occurrence of the specified data.
- `left / right` – Returns the leftmost or rightmost bytes.
- `toHex` – Converts the byte array to a hexadecimal representation.
- `fromHex` – Creates a byte array from a hexadecimal string.
- `chop` – Removes a specified number of bytes from the end of the array.
- `resize` – Resizes the byte array to the specified length.
- `isEmpty` – Checks if the byte array is empty.
- `data` – Provides access to the underlying data as a char\*.
- `fill` – Fills the byte array with a specific character.
- `trimmed` – Removes whitespace from the beginning and end of the byte array.
