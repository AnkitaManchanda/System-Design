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
class BasicWB: public Burger{
	public:
		void prepare()override{
			cout<<"Simple Basic Wheat Burger "<<endl;
		}
};
class StdWB: public Burger{
	public:
		void prepare()override{
			cout<<"Simple Standard Wheat Burger "<<endl;
		}
};
class PremiumWB: public Burger{
	public:
		void prepare()override{
			cout<<"Premium Wheat Burger "<<endl;
		}
};
//garlic bread
class GB{
	public:
		virtual void prepare()=0;
		virtual ~GB(){}
};
class BasicGB: public GB{
	public:
		void prepare()override{
			cout<<"Simple Basic garlic bread "<<endl;
		}
};
class StdGB: public GB{
	public:
		void prepare()override{
			cout<<"Simple Standard garlic bread "<<endl;
		}
};
class PremiumGB: public GB{
	public:
		void prepare()override{
			cout<<"Chessy garlic bread "<<endl;
		}
};
class BasicWGB: public GB{
	public:
		void prepare()override{
			cout<<"Simple Basic wheat garlic bread "<<endl;
		}
};
class StdWGB: public GB{
	public:
		void prepare()override{
			cout<<"Simple Standard Wheat garlic bread "<<endl;
		}
};
class PremiumWGB: public GB{
	public:
		void prepare()override{
			cout<<"Chessy Wheat garlic bread "<<endl;
		}
};
//abh factory banayenge
class Factory{
	public:
		virtual Burger* createBurger(string& type)=0;
		virtual GB* createGB(string& type)=0;
		virtual ~Factory(){}
};
class Singh: public Factory{
	public:
	Burger* createBurger(string& type) override{
		if(type=="basic") return new BasicB();
		    if(type=="standard") return new StdB();
			if(type=="premium") return new PremiumB();
			cout<<"An Invalid Burger"<<endl;
			return NULL;
	}
	GB* createGB(string& type) override{
		if(type=="basic") return new BasicGB();
		    if(type=="normal") return new StdGB();
			if(type=="cheesy") return new PremiumGB();
			cout<<"An Invalid Garlic Bread"<<endl;
			return NULL;
	}
};
class King: public Factory{
	public:
	Burger* createBurger(string& type) override{
		if(type=="basic") return new BasicWB();
		    if(type=="standard") return new StdWB();
			if(type=="premium") return new PremiumWB();
			cout<<"An Invalid Burger"<<endl;
			return NULL;
	}
	GB* createGB(string& type) override{
		if(type=="basic") return new BasicWGB();
		    if(type=="normal") return new StdWGB();
			if(type=="cheesy") return new PremiumWGB();
			cout<<"An Invalid Garlic Bread"<<endl;
			return NULL;
	}
};
int main(){
	string type="standard";
	Factory* factory=new King();
	Burger* burger=factory->createBurger(type);
	burger->prepare();
	Factory* factory1=new Singh();
	Burger* burger1=factory1->createBurger(type);
	burger1->prepare();
	
	string t1="cheesy";
	GB* p1=factory->createGB(t1);
	p1->prepare();
    return 0;
}
