#include <iostream>
#include <fstream>
#include <string>

// Packs a string of '0's and '1's into actual binary bits and saves to a file
void saveBitsToFile(const std::string& bitString, const std::string& fileName) {
    std::ofstream file(fileName, std::ios::binary);
    
    unsigned char byte = 0; // Holds 8 bits before writing
    int count = 0;          // Tracks how many bits are collected (0 to 8)

    for (char bit : bitString) {
        // Shift bits left to make room, then set the last bit if character is '1'
        byte = (byte << 1) | (bit == '1' ? 1 : 0);
        count++;

        // Every 8 bits, write the byte to disk and reset
        if (count == 8) {
            file.put(byte);
            byte = 0;
            count = 0;
        }
    }

    // Pad remaining bits with zeros to complete the final byte
    if (count > 0) {
        byte <<= (8 - count);
        file.put(byte);
    }

    file.close();
}

int main() {
    std::string huffmanBits = "0100000101000010"; // Example: "AB" in binary
    saveBitsToFile(huffmanBits, "compressed.bin");
    std::cout << "Binary data saved successfully!\n";
    return 0;
}
