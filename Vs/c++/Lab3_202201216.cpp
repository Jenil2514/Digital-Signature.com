#include<iostream>
using namespace std;

class complex{
	public:
	int r1,r2,i1,i2,i,r;    //r=real part,i=imaginary part
	
	void add(){
		//int r=r1+r2;
		//int i=i1+i2;
		if(i>0)
			cout<<r1+r2<<"+i"<<i1+i2<<endl;
		else if(i<0){
			i=(-1)*i;
			cout<<r1+r2<<"-i"<<(-1)*(i1+i2)<<endl;
		}
		else
			cout<<r1+r2<<endl;
	}
	void mul(){
		//int r=r1*r2-(i1*i2);
		//int i=i2*r1+i1*r2;
		if(i>0)
			cout<<r1*r2-(i1*i2)<<"+i"<<i2*r1+i1*r2<<endl;
		else if(i<0){
			i=(-1)*i;
			cout<<r1*r2-(i1*i2)<<"-i"<<(-1)*(i2*r1+i1*r2)<<endl;
		}
		else
			cout<<r1*r2-(i1*i2)<<endl;
	}
};

int main(){
	cout<<"Consider to be a+ib is the equation"<<endl;
	
	complex cp;
	cout<<"First real: ";
	cin>>cp.r1;
	cout<<"First imaginary: ";
	cin>>cp.i1;
	cout<<"Second real: ";
	cin>>cp.r2;
	cout<<"Second imaginary: ";
	cin>>cp.i2;
	
	cout<<"sum :";
	cp.add();
	cout<<"\n";
	cout<<"multi :";
	cp.mul();
	cout<<"\n";
	
	return 0;
}