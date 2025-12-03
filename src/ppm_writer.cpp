#include<string>
#include<fstream>
#include<vector>
#include<cstdint>

void write_Image(const std::string filename,int width,int height,const std::vector<std::uint8_t>& pixels){
    std::ofstream out(filename,std::ios::binary);
    if(!out)throw std::runtime_error("File not opening");
    out<<"P6\n"<<width<<" "<<height<<"\n255\n"; //header
    out.write(reinterpret_cast<const char*>(pixels.data()),pixels.size());
}
