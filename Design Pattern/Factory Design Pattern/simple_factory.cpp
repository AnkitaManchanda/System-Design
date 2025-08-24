#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//simple burger wali class
class Burger{
	public:
		virtual void prepare()=0;
		virtual ~Burger(){}
};
class BasicB: public Burger{
	public:
		void prepare()override{
			cout<<"Simple Basic Burger "<<endl;
		}
};
class StdB: public Burger{
	public:
		void prepare()override{
			cout<<"Simple Standard Burger "<<endl;
		}
};
class PremiumB: public Burger{
	public:
		void prepare()override{
			cout<<"Premium Burger "<<endl;
		}
};
//abh factory banayenge
class Factory{
	public:
		Burger* createBurger(string& type){
			if(type=="basic") return new BasicB();
		    if(type=="standard") return new StdB();
			if(type=="premium") return new PremiumB();
			cout<<"An Invalid Burger"<<endl;
			return NULL;
		}
};
int main(){
	string type="standard";
	Factory* factory=new Factory();
	Burger* burger=factory->createBurger(type);
	burger->prepare();
    return 0;
}
