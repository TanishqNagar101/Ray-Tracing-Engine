#include<iostream>
class vec3{
    float x,y,z;
   public:
    vec3();
    vec3(float x,float y,float z);

    
};
vec3::vec3(){
    x=0.0;
    y=0.0;
    z=0.0;
}
vec3::vec3(float x,float y, float z){
    x=x;
    y=y;
    z=z;
}

int main(){
    return 0;
}