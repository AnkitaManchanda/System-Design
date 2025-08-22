#include<iostream>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;
class DocumentEditor{
	protected:
		vector<string>elements;
		string document;
	public:
		void addText(string t){
			elements.push_back(t);
			cout<<"text added"<<endl;
		}
		void addImage(string p){
			elements.push_back(p);
			cout<<"image added"<<endl;
		}
		string renderDocument(){
			if(document.empty()){
				for(auto i:elements){
				if(i.length()>4 && (i.substr(i.size()-4)==".jpg" ||i.substr(i.size()-4)==".png")){
					//cout<<"IMAGE PATH : "<<i;
					string x="Image:path "+i+"\n";
					document+=x;
				}
				else{
//					cout<<i;
                    document+=i+"\n";
				}
				cout<<endl;
			}
			}
			return document;
		}
		void saveToFile(){
			ofstream file("document.txt");
			if(file.is_open()){
				file<<renderDocument();
				file.close();
				cout<<"SAVED..."<<endl;
			}
			else{
				cout<<"UNABLE TO OPEN FILE"<<endl;
			}
		}
};
int main(){
	DocumentEditor editor;
	editor.addText("hola");
	editor.addText("Amigo");
	editor.addImage("uff.txt");
	cout<<editor.renderDocument()<<endl;
	editor.saveToFile();
    return 0;
}
