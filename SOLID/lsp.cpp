#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class NWA{
	public:
		virtual void deposit(double amount)=0;
};
class WA:public NWA{
	
	public:
		virtual void withdraw(double amount)=0;
};
class FD:public NWA{
	private:
		double balance;
	public:
		void deposit(double amount){
		}
};
class CA: public WA{
	private:
		double balance;
	public:
		void withdraw(double amount){
		}
};
class SA: public WA{
	private:
		double balance;
	public:
		void withdraw(double amount){
		}
};

class Client{
	private:
		vector<NWA*>nwa;
		vector<WA*>wa;
	public:
		void process(){
			for(auto i:nwa){
				i->deposit(1000);
			}
			for(auto i:wa){
				i->deposit(1000);
				i->withdraw(500);
			}
		}
};
int main(){
    return 0;
}
