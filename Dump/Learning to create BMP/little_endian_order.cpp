#include<iostream>
#include<bitset>
using namespace std;

int main(){
	int a=10294;
	bitset<16> b(a);
	cout<<"INT Rep:="<<a<<endl;
	cout<<"BI Rep:="<<b<<endl;
	cout<<"Size of a :="<<sizeof(a)<<endl;
	for(int i=1;i<=sizeof(a);i++){
		bitset<8> temp((a & 0xFF));
		cout<<"The "<<i<<"Byte of a:="<<temp<<endl;
		a=a>>8;
	}
}
