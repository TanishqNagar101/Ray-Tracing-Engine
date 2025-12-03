#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
/*
The BMP file is in little endian format so the numbers are written in opposite format!!!!
*/

const int BYTES_PER_PIXEL=3;
const int HEIGHT=100;
const int WIDTH=100;
const int INFO_HEADER_SIZE=40;
const int FILE_HEADER_SIZE=14; 

unsigned char* generate_INFO_header();
unsigned char* generate_FILE_header(int file_size);
vector<unsigned char> generate_pixel_array(int array_size,int row_width,int padding);

int main(){
	int row_width=WIDTH*BYTES_PER_PIXEL;
	int padding=(4-(row_width%4))%4;
	int pixel_array_size=(row_width+padding)*HEIGHT;
	unsigned char* FILE_HEADER=generate_FILE_header(((row_width+padding)*HEIGHT)+14+40);
	unsigned char* INFO_HEADER=generate_INFO_header();
	vector<unsigned char> pixel_array=generate_pixel_array(pixel_array_size,row_width,padding);
	
	ofstream outfile;
	outfile.open("output.bmp",ios:: out|ios::binary);
	if(outfile.is_open()){
		outfile.write(reinterpret_cast<const char*>(FILE_HEADER),FILE_HEADER_SIZE);
		outfile.write(reinterpret_cast<const char*>(INFO_HEADER),INFO_HEADER_SIZE);
		outfile.write(reinterpret_cast<const char*>(pixel_array.data()),pixel_array.size());
		outfile.close();
	}
	else cout<<"File not open"<<endl;


		


};

unsigned char* generate_FILE_header(int file_size){
	unsigned char* header=new unsigned char[FILE_HEADER_SIZE]{
	0,0,      //Needs to ber B andf M
	0,0,0,0, //size
	0,0,	 // defautl to 0
	0,0,     //default to 0
	0,0,0,0  //starting of pixel data
	};
	int pixel_array=INFO_HEADER_SIZE+FILE_HEADER_SIZE;
	header[0]='B';
	header[1]='M';
	for(int i=0;i<4;i++){
		header[2+i]=(file_size>>(8*i)) & 0xFF;
		header[10+i]=(pixel_array>>(8*i)) & 0xFF;
	};
	return header;
};

unsigned char* generate_INFO_header(){
	unsigned char* header=new unsigned char[INFO_HEADER_SIZE]{
	0,0,0,0,  //size of the header
	0,0,0,0,  //width in pixels
	0,0,0,0,  //height in pixels
	0,0,      //number of colour pannels must be 1
	0,0,      //no of BITS_PER_PIXEL
	0,0,0,0,  //the compression method used
	0,0,0,0,  //the raw image size before comprtession, 0 can be given
	0,0,0,0,  //horizonlat res of image in pix/meter
	0,0,0,0,  //vertical res of image in pix/meter
	0,0,0,0,  //no of colour pallets
	0,0,0,0,  //no of imp colour used, o for all colour is imp
	};
	for(int i=0;i<4;i++){
		header[0+i]=(INFO_HEADER_SIZE>>(8*i)) & 0xFF;
		header[4+i]=(WIDTH>>(8*i)) & 0xFF;
		header[8+i]=(HEIGHT>>(8*i)) & 0xFF;
	};
	header[12]=1;
	header[13]=0;
	header[14]=(24&0xFF);
	header[15]=(24>>8)&0xFF;
	return header;
};

vector<unsigned char> generate_pixel_array(int array_size,int row_width,int padding){
	vector<unsigned char> arr(array_size);
	
	for (int i = HEIGHT - 1; i >= 0; i--) {
        int k = i * (row_width + padding);
        for (int j = 0; j < row_width; j += 3) {
            unsigned char r = static_cast<unsigned char>(((j / 3.0f) / (row_width / 3 - 1)) * 255);
            unsigned char g = static_cast<unsigned char>(((HEIGHT - 1 - i) / static_cast<float>(HEIGHT - 1)) * 255);
            unsigned char b = 125; 

            arr[k++] = b;
            arr[k++] = g;
            arr[k++] = r;
        }

        for (int j = 0; j < padding; j++)
            arr[k++] = 0x00;
    }
	return arr;

}
