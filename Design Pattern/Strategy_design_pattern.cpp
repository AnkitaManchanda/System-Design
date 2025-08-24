#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Walkable{
	public:
		virtual void walk()=0;
		virtual ~Walkable(){}
};
class NormalWalk:public Walkable{
	public:
		void walk()override{
			cout<<"Normal Walk"<<endl;
		}
};
class NoWalk:public Walkable{
	public:
		void walk()override{
			cout<<"No Walk"<<endl;
		}
};
//------------------------------------------------------
class Talkable{
	public:
		virtual void talk()=0;
		virtual ~Talkable(){}
};
class NormalTalk:public Talkable{
	public:
		void talk()override{
			cout<<"Normal Talk"<<endl;
		}
};
class NoTalk:public Talkable{
	public:
		void talk()override{
			cout<<"No Talk"<<endl;
		}
};
//-------------------------------------------------------
class Flyable{
	public:
		virtual void fly()=0;
		virtual ~Flyable(){}
};
class NormalFly:public Flyable{
	public:
		void fly() override{
			cout<<"Normal Fly"<<endl;
		}
};
class NoFly:public Flyable{
	public:
		void fly()override{
			cout<<"No Fly"<<endl;
		}
};
//-------------------------------------------------------
class Robot{
	protected:
		Talkable* t;
		Walkable* w;
		Flyable* f;
	public:
		Robot(Talkable* t,Walkable* w,Flyable* f){
			this->t=t;
			this->w=w;
			this->f=f;
		}
		void walk(){
			w->walk();
		}
		void talk(){
			t->talk();
		}
		void fly(){
			f->fly();
		}
		virtual void projection()=0;
};
//classification of robots
class CompanionR:public Robot{
	public:
		CompanionR(Talkable* t,Walkable* w,Flyable* f):Robot(t,w,f){
		}
		void projection() override{
			cout<<"Hello Buddy, I'm your companion"<<endl;
		}
};
class WorkerR:public Robot{
	public:
		WorkerR(Talkable* t,Walkable* w,Flyable* f):Robot(t,w,f){}
		void projection() override{
			cout<<"Hello Sir, give me my wage sir aae...."<<endl;
		}
};
int main(){
	Robot* r1=new CompanionR(new NormalTalk(),new NoWalk(),new NoFly());
	Robot* r2=new WorkerR(new NoTalk(),new NormalWalk(),new NormalFly());
	r1->projection();
	r1->fly();
	r1->walk();
	r1->talk();
	r2->projection();
	r2->fly();
	r2->walk();
	r2->talk();
    return 0;
}
