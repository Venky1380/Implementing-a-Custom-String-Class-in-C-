#include<iostream>
#include<fstream>
using namespace std;



int strlen(const char *p){
	int i=0;
	while(p[i])
		i++;
	return i;
}

void strcpy(char *p,const char *q){
	int i=0;
	while(q[i]){
		p[i]=q[i];
		i++;
	}
	p[i]='\0';
}

int strcmp(char *p,char *q){
	int i=0;
	while(q[i]||p[i]){
		if(p[i]!=q[i])
			return (p[i]-q[i]);
		i++;
	}
	return 0;
}




class Mystring{
	char *str;
	public:

	Mystring(){
		//str=new char[1];
		//str[0]='\0';
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

	Mystring & operator =(const Mystring &p){
		if(this!=&p){	
			char *temp=new char[strlen(p.str)+1];
			strcpy(temp,p.str);
			delete []str;
			str=temp;
		}
		return *this;
	}

	Mystring  operator +(Mystring &p){
		int i=0,j=0;

		Mystring temp;
		temp.str=new char[strlen(str)+strlen(p.str)+1 ];

		strcpy(temp.str,this->str);

		while(temp.str[i])
			i++;

		while(p.str[j]){
			temp.str[i]=p.str[j];
			j++,i++;
		}
		temp.str[i]=0;

		return temp;
	}

	char& operator [](int i){
		return this->str[i];
	}

	bool operator <(Mystring &p){
		return (strcmp(str,p.str)<0);
	}
	bool operator >(Mystring &p){
		return (strcmp(str,p.str)>0);
	}
	bool operator ==(Mystring &p){
		return (strcmp(str,p.str)==0);
	}
	bool operator >=(Mystring &p){
		return (strcmp(str,p.str)==0 ||strcmp(str,p.str) >0);
	}
	bool operator <=(Mystring &p){
		return (strcmp(str,p.str)==0 ||strcmp(str,p.str) <0);	
	}


	~Mystring(){
		if(str!=0 ){
			delete []str;
			str=0;
		}
	}
	friend void  str_cpy(Mystring &,Mystring &);
	friend void strn_cpy(Mystring &,Mystring &,int);
	friend void str_cat(Mystring &,Mystring &);
	friend void strn_cat(Mystring &,Mystring &,int);
	friend void str_rev(Mystring &);
	friend void str_upr(Mystring &);
	friend void str_lwr(Mystring &);
	friend int str_len(Mystring &);
	friend char* str_chr(Mystring &,const char);
	friend char* strr_chr(Mystring &,const char);
	friend char * str_str(Mystring &,char*);
	friend int str_cmp(Mystring &,Mystring &);
	friend int strn_cmp(Mystring &,Mystring &,int);
	friend istream & operator>>(istream & in,Mystring &s);
	friend ostream & operator<<(ostream & out,Mystring &s);
};




void str_cpy(Mystring &p,Mystring &q){
	int i=0;
	while(q.str[i]){
		p.str[i]=q.str[i];
		i++;
	}
	p.str[i]='\0';
}
void strn_cpy(Mystring &p,Mystring &q,int n){
	int i=0;
	while(i<n){
		p.str[i]=q.str[i];
		i++;
	}
	p.str[i]='\0';
}
int strn_cmp(Mystring &p,Mystring &q,int n){
	int i=0,k=0;
	while(i<n){
		if((p.str[i]-q.str[i])==0)
			return (p.str[i]-q.str[i]);
		i++;
	}
	return 0;
}

int str_cmp(Mystring &p,Mystring &q){
	int i=0,k=0;
	while(p.str[i]||q.str[i]){
		if((p.str[i]-q.str[i])==0)
			return (p.str[i]-q.str[i]);
		i++;
	}
	return 0;
}


void str_cat(Mystring &p,Mystring &q){
	int i=0,j=0;
	char *temp=new char[strlen(p.str)+strlen(q.str)+1];

	while(p.str[i]){
		temp[i]=p.str[i];
		i++;
	}

	while(q.str[j]){
		temp[i]=q.str[j];
		j++,i++;
	}

	temp[i]='\0';
	delete []p.str;

	p.str=temp;
}

void strn_cat(Mystring &p,Mystring &q,int n){
	int i=0,j=0;
	char *temp=new char[strlen(p.str)+strlen(q.str)+1];

	while(p.str[i]){
		temp[i]=p.str[i];
		i++;
	}
	while(j<n){
		temp[i]=q.str[j];
		j++,i++;
	}
	temp[i]='\0';
	delete []p.str;
	p.str=temp;
}

void str_rev(Mystring &p){
	int i=0,j;
	char ch;

	for(j=0;p.str[j];j++);
	j--;

	while(i<j){
		ch=p.str[i];
		p.str[i]=p.str[j];
		p.str[j]=ch;
		i++,j--;
	}
}

void str_upr(Mystring &p){
	int i=0;
	while(p.str[i]){
		if(p.str[i]>='a' && p.str[i]<='z')
			p.str[i]=p.str[i]-32;
		i++;
	}
}
void str_lwr(Mystring &p){
	int i=0;
	while(p.str[i]){
		if(p.str[i]>='A' && p.str[i]<='Z')
			p.str[i]=p.str[i]+32;
		i++;
	}
}

int str_len(Mystring &p){
	int i;
	for(i=0;p.str[i];i++);
	return i;
}

char* str_chr(Mystring &p,const char ch){
	int i=0;
	while(p.str[i]){
		if(p.str[i]==ch)
			return p.str;
		i++;
	}
	return 0;
}

char* strr_chr(Mystring &p,const char ch){
	int i=0;
	for(i=0;p.str[i];i++);
	i--;
	while(i>=0){
		if(p.str[i]==ch)
			return p.str+i;
		i--;
	}
	return 0;
}

char* str_str(Mystring &p,char* q){
	int i,j,k;
	for(i=0;p.str[i];i++){
		if(p.str[i]==q[0]){
			for(j=0;q[j];j++)
				if(q[j]!=p.str[i+j])
					break;
		}
		if(q[i]=='\0')
			return p.str+i;
	}
	return 0;
}


istream & operator>>(istream & in,Mystring &s){

	char ch;
	int c=0;

	fstream fout("data",ios::out|ios::trunc);

	while (cin.get(ch))
	{
		if (ch == '\n')
			break;
		fout.put(ch);
		c++;
	}
	fout.close();

	ifstream fin("data");

	char *temp=new char[c+1];

	fin.getline(temp,c+1);
	fin.close();
	temp[c+1]=0;

	delete []s.str;
	s.str=temp;
	return in;
}

ostream & operator<<(ostream & out,Mystring &s){
	out<<s.str;
	return out;
}

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



