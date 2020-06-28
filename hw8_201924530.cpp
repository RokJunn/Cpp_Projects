#include <iostream>
#include <cstring>
using namespace std;

class MyString {
	char* str ;
	int size ;
public:
	MyString()
		: str(new char[size]), size(0){}
	MyString(const char* _str)
		: str(new char[size]), size(strlen(_str)+1){
			for(int i=0; i<size; i++)
				str[i]=_str[i];
		}
	MyString(const MyString& _str)
		: str(new char[size]), size(_str.size){
			for(int i=0; i<size; i++)
				str[i]=_str.str[i];
		}
	~MyString(){
		delete [] str;
	}
	set(const char* _str){
		size = strlen(_str);
		for(int i=0; i<size; i++)
			str[i]=_str[i];
	}
	bool isEqual (const MyString& target) const {
		for(int i=0; i<size; i++){
			if(str[i]!=target.str[i])
				return false;
		}
		return true;	
	}
	void print () const {
		for(int i=0; i<size; i++){
			cout << str[i];
		}
		cout << endl;
	}
} ;


int main() {
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")
	} ;
	strs[1].set("C++") ;

	const MyString target("Java") ;
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString str(strs[i]) ;
		if ( str.isEqual(target) ) {
			cout << "[" << i << "]: " ;
			str.print() ;
			break ;
		}
	}
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString& str = strs[i] ;
		str.print() ;
	}
}

