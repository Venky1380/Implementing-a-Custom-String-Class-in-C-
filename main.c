#include"string.h"

int main(){
	Mystring a("vector"),b("india"),c,d; 
	a.getdata();
	//assignment operator
	c=a;
	c.getdata();
	//concatenation op
	c=c+a;
	c.getdata();
	//Subscript operator ([])
	cout<<c[2]<<endl;
	//comaprison op
	cout<<"a==b: "<<(a==b)<<endl;
	cout<<"a<b: "<<(a<b)<<endl;
	cout<<"a>b: "<<(a>b)<<endl;
	cout<<"a<=b: "<<(a<=b)<<endl;
	cout<<"a>=b: "<<(a>=b)<<endl;
	//strcpy();
	str_cpy(d,a);
	d.getdata();
	//strncpy
	strn_cpy(d,a,2);
	d.getdata();

	cin>>c;
	cout<<c<<endl;
}



