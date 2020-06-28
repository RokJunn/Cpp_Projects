#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

struct Rectangle {
	int width ;
	int height ;
} ;

enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID} ;

CommandKind getCommandKind(string commandstr);
Rectangle getRectangle();
void print(const vector<Rectangle>& prectangle);
void recprint(const Rectangle&);
void sort(vector<Rectangle>& srectangle);
void swap(vector<Rectangle>& rect, int i);

int main() {
	vector<Rectangle> rectangles ;
	while ( true ) {
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString) ;
		switch ( command ) {
			case ADD : {
				const Rectangle& newRectangle = getRectangle() ;
				rectangles.push_back(newRectangle) ;
				break ;
			}
			case PRINT:
				print(rectangles) ;
				// use const_iterator in print()
				// define and call print(const Rectangle&)
				break ;
			case SORT: {
				sort(rectangles) ; // define and call swap in sort()
				print(rectangles) ;
				break ;
			}
			case CLEAR: rectangles.clear() ; break ;
			case EXIT: break ;
			default: assert (false) ; break ;
		}
		if ( command == EXIT ) break ;
	}
}

CommandKind getCommandKind(string commandstr){
	if(commandstr == "ADD")
		return static_cast<CommandKind>(0);
	else if(commandstr == "SORT")
		return static_cast<CommandKind>(1);
	else if(commandstr == "PRINT")
		return static_cast<CommandKind>(2);
	else if(commandstr == "CLEAR")
		return static_cast<CommandKind>(3);
	else if(commandstr == "EXIT")
		return static_cast<CommandKind>(4);
	else
		return static_cast<CommandKind>(5);			
}

Rectangle getRectangle(){
	int width=0, height=0;
	cin >> width >> height;
	static Rectangle newrec;
	newrec.width = width;
	newrec.height = height;
	return newrec;
}

void print(const vector<Rectangle>& prectangle){
	cout<<"Rectangle Count: "<< prectangle.size() << endl;
	vector<Rectangle>::const_iterator it = prectangle.begin();
	for (int i=0; i<prectangle.size(); i++){
		cout << it[i].width << '\t' ;
		cout << it[i].height << '\t';
		recprint(it[i]);
	}
}

void recprint(const Rectangle& rect){
	cout<< rect.width * rect.height<<endl;
}

void sort(vector<Rectangle>& srectangle){
	vector<Rectangle>::iterator it = srectangle.begin();
	for (int i=0; i<srectangle.size()-1; i++){
		for(int j=0; j<srectangle.size()-1-i; j++){
			int Area1 = it[j].height * it[j].width;
			int Area2 = it[j+1].height * it[j+1].width;
			if (Area1>Area2) swap(srectangle, j);	
		}
	}
}

void swap(vector<Rectangle>& rect,int i){
	vector<Rectangle>::iterator sit = rect.begin();
	Rectangle temp = sit[i+1];
	sit[i+1] = sit[i];
	sit[i] = temp;
}
