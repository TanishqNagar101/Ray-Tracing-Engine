//This is for ppm file format
#include <iostream>
#include <fstream>
void generate(const double* arr, const int row, const int column){
	std::ofstream file("image.ppm");

	if(file.is_open()){
		std::cout<<"File is open writing content!!"<<std::endl;
		file<<"P3\n"<<column<<" "<<row<<"\n"<<255<<"\n";
		for(int i=0;i<row*column;i++){
			int base=i*3;
			file<<*(arr+base+0)<<" "
			    <<*(arr+base+1)<<" "
			    <<*(arr+base+2)<<"\n";
		};
		file.close();
	}
	else std::cout<<"File cannot open"<<std::endl;
	
};

int main(){
	int h=256;
	int w=256;
	
	double arr[h*w*3];
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int pixel_idx=w*i+j;
			int base = pixel_idx*3;

			arr[base+0]=double(j);
			arr[base+1]=double(i);
			arr[base+2]=double(0);
		};
	};

	generate(arr,w,h);

};
