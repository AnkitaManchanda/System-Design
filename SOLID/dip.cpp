#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Database{
	public:
		virtual void save(string data)=0;
};
class Mongo:public Database{
	public:
		void save(string s) override{
			cout<<s<<" Save in mongodb"<<endl;
		}
};
class Mysql:public Database{
	public:
		void save(string s) override{
			cout<<s<<" Save in MYSQL"<<endl;
		}
};

class User{
	private:
		Database *db; //dependancy injection
	public:
		User(Database * data){
			db=data;
		}
		void store(string s){
			db->save(s);
		}
};
int main(){
	Mysql* mysql=new Mysql(); 
	Mongo mongo;//this is not take as pointer because we need to pass its original object
	User* u1=new User(mysql);
	u1->store("anyone");
	User* u2=new User(&mongo);
	u2->store("someone");
    return 0;
}
