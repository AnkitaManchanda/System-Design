#include<iostream>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;
class DocumentElement{
	public:
		virtual string render()=0;
};
class TextElement:public DocumentElement{
	private:
		string txt;
	public:
		TextElement(string s):txt(s){
		}
		string render() override{
			return txt;
		}
};
class ImageElement:public DocumentElement{
	private:
		string path;
	public:
		ImageElement(string s):path(s){
		}
		string render() override{
			return "[Image : "+path+" ]";
		}
};
class NewLineElement:public DocumentElement{
//	private:
//		string txt;
	public:
//		TextElement(string s):txt(s){
//		}
		string render() override{
			return "\n";
		}
};
class NewTabElement:public DocumentElement{
//	private:
//		string txt;
	public:
//		TextElement(string s):txt(s){
//		}
		string render() override{
			return "\t";
		}
};

class Document{
	private:
		vector<DocumentElement*>elements;
	public:
		void addElement(DocumentElement* e1){
			elements.push_back(e1);
		}
		string render(){
			string ans="";
			for(auto i:elements){
				ans+=i->render();
			}
			return ans;
		}
};

class Persistence{
	public:
		virtual void save(string data)=0;
};
class SaveToFile:public Persistence{
	public:
		void save(string data) override{
			ofstream file("updated_doc.txt");
			if(file.is_open()){
				file<<data;
				file.close();
			}
			else{
				cout<<"UMM SOMETHING WENT WRONG"<<endl;
			}
		}
};
class SaveToDB:public Persistence{
	public:
		void save(string data)override{
			cout<<"SAVE TO DB"<<endl;
		}
};
class DocumentEditor{
	private:
		Document* doc;
		Persistence* db;
		string renderDoc;
	public:
		DocumentEditor(Document* document,Persistence* storage):doc(document),db(storage){
		}
		
		void addText(string t){
			doc->addElement(new TextElement(t));
		}
		void addImage(string p){
			doc->addElement(new ImageElement(p));
		}
		void addNewLine(){
			doc->addElement(new NewLineElement());
		}
		void addNewTab(){
			doc->addElement(new NewTabElement());
		}
		
		string renderDocument(){
			if(renderDoc.empty()){
				renderDoc=doc->render();
			}
			return renderDoc;
		}
		
		void saveDoc(){
			db->save(renderDocument());
		}
};

int main(){
	Document* document=new Document();
	Persistence* persistence=new SaveToFile();
	DocumentEditor* editor=new DocumentEditor(document,persistence);
	
	editor->addText("hola");
	editor->addNewLine();
	editor->addText("amigo");
	editor->addNewLine();
	editor->addImage("umm.png");
    editor->addNewLine();
    
    cout<<editor->renderDocument()<<endl;
    editor->saveDoc();
	
    return 0;
}
