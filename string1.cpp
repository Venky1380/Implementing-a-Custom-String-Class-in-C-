#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
	char *str;
	public:

	Mystring(){
		str=new char[1];
		str[0]='\0';
	};

	Mystring(const char *p){
		str=new char[strlen(p)+1];
		strcpy(str,p);		
	};

	Mystring(Mystring &p){
		str=new char[strlen(p.str)+1];
		strcpy(str,p.str);			
	};
	void getdata(){
		cout<<str<<endl;
	}

	Mystring& operator =(Mystring &p){
		if(this!=&p){	
			char *temp=new char[strlen(p.str)+1];
			strcpy(temp,p.str);
			delete []str;
			str=temp;
		}
		return *this;
	}

	Mystring &  operator +(Mystring &p){
		strcat(this->str,p.str);
		return *this;
	}
	char operator [](int i){
		return this->str[i];
	}

	int operator <(Mystring &p){
		return (strcmp(str,p.str)<0);
	}
	int operator >(Mystring &p){
		return (strcmp(str,p.str)>0);
	}
	int operator ==(Mystring &p){
		return (strcmp(str,p.str)==0);
	}
	int operator >=(Mystring &p){
		return (strcmp(str,p.str)==0 ||strcmp(str,p.str) >0);
	}
	int operator <=(Mystring &p){
		return (strcmp(str,p.str)==0 ||strcmp(str,p.str) <0);	
	}


	~Mystring(){
		if(str!=0 ){
			delete []str;
			str=0;
		}
	}
};

int main(){
	Mystring a("hllo"),b("hllo"),c("vector");
	a.getdata();
	b.getdata();
	c.getdata();
	cout<<(a==b)<<endl;
	cout<<(a>=b)<<endl;
	cout<<(a<c)<<endl;
	cout<<a[2]<<endl;
}
