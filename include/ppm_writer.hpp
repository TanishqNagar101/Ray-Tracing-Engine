#ifndef PPM_WRITER_H
#define PPM_WRITER_H

#include<string>
#include<vector>
#include<cstdint>
void write_Image(const std::string filename,int width,int height,const std::vector<std::uint8_t>& pixels);

#endif // MY_HEADER_H