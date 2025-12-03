// gradient_bmp.cpp
// Build: g++ -std=c++17 gradient_bmp.cpp -o gradient_bmp
// Run:   ./gradient_bmp
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

// Write a 4-byte little-endian integer
void write_le_uint32(std::ofstream &out, uint32_t v) {
    unsigned char b[4];
    b[0] = v & 0xFF;
    b[1] = (v >> 8) & 0xFF;
    b[2] = (v >> 16) & 0xFF;
    b[3] = (v >> 24) & 0xFF;
    out.write(reinterpret_cast<char*>(b), 4);
}

// Write a 2-byte little-endian integer
void write_le_uint16(std::ofstream &out, uint16_t v) {
    unsigned char b[2];
    b[0] = v & 0xFF;
    b[1] = (v >> 8) & 0xFF;
    out.write(reinterpret_cast<char*>(b), 2);
}

int main() {
    // Image size (change as you like)
    const int width = 800;
    const int height = 600;
    const int bytesPerPixel = 3; // 24-bit BMP (B,G,R)
    // Each row must be padded to a multiple of 4 bytes
    const int rowSize = (width * bytesPerPixel + 3) & ~3;
    const uint32_t pixelDataSize = rowSize * height;

    const uint32_t fileHeaderSize = 14;
    const uint32_t dibHeaderSize = 40; // BITMAPINFOHEADER
    const uint32_t offsetToPixelData = fileHeaderSize + dibHeaderSize;
    const uint32_t fileSize = offsetToPixelData + pixelDataSize;

    std::string filename = "gradient.bmp";
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cerr << "Failed to open file for writing\n";
        return 1;
    }

    // --- BITMAPFILEHEADER (14 bytes) ---
    // bfType: 2 bytes 'BM'
    out.put('B');
    out.put('M');
    // bfSize: 4 bytes
    write_le_uint32(out, fileSize);
    // bfReserved1 + bfReserved2: 2 bytes each
    write_le_uint16(out, 0);
    write_le_uint16(out, 0);
    // bfOffBits: 4 bytes
    write_le_uint32(out, offsetToPixelData);

    // --- BITMAPINFOHEADER (40 bytes) ---
    write_le_uint32(out, dibHeaderSize);        // biSize
    write_le_uint32(out, static_cast<uint32_t>(width)); // biWidth
    write_le_uint32(out, static_cast<uint32_t>(height)); // biHeight (positive => bottom-up)
    write_le_uint16(out, 1);                    // biPlanes
    write_le_uint16(out, 24);                   // biBitCount
    write_le_uint32(out, 0);                    // biCompression (0 = BI_RGB)
    write_le_uint32(out, pixelDataSize);        // biSizeImage (can be 0 for BI_RGB, but we fill it)
    write_le_uint32(out, 2835);                 // biXPelsPerMeter (~72 DPI). 2835 = 72 DPI
    write_le_uint32(out, 2835);                 // biYPelsPerMeter
    write_le_uint32(out, 0);                    // biClrUsed
    write_le_uint32(out, 0);                    // biClrImportant

    // --- Pixel data ---
    // BMP stores rows bottom-up: first row written is the bottom scanline.
    std::vector<unsigned char> padding(rowSize - width*bytesPerPixel, 0);

    for (int y = 0; y < height; ++y) {
        int row = height - 1 - y; // bottom-up indexing: row=0 => top line, but we write bottom first
        (void)row; // just clarifying usage; we compute colors using y or row as preferred
        for (int x = 0; x < width; ++x) {
            // Example gradient (colorful):
            // R varies left->right, G varies top->bottom, B varies by combined position.
            unsigned char r, g, b;
            if (width > 1)
                r = static_cast<unsigned char>((x * 255) / (width - 1));
            else
                r = 0;
            if (height > 1)
                g = static_cast<unsigned char>(((height - 1 - y) * 255) / (height - 1)); // top brighter
            else
                g = 0;
            if (width + height > 2)
                b = static_cast<unsigned char>(((x + y) * 255) / (width + height - 2));
            else
                b = 0;

            // BMP pixel order: Blue, Green, Red
            out.put(static_cast<char>(b));
            out.put(static_cast<char>(g));
            out.put(static_cast<char>(r));
        }
        // write padding bytes at end of row
        if (!padding.empty())
            out.write(reinterpret_cast<char*>(padding.data()), padding.size());
    }

    out.close();
    if (!out) {
        std::cerr << "Error writing file\n";
        return 1;
    }

    std::cout << "Wrote " << filename << " (" << width << "x" << height << ")\n";
    return 0;
}

