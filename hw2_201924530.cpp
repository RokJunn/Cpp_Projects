#include <iostream>
#include <string>
#include <limits>
using namespace std;

string response;
int cchar, cint, clong, cfloat, cdouble;

int main(){	
	cin >> response;
	while (response != "quit") {
		if (response == "char"){
			cchar++;
			cout << static_cast<int>(numeric_limits<char>::min())<< "\t" << static_cast<int>(numeric_limits<char>::max());
		}else if (response == "int"){
			cint++;
			cout << numeric_limits<int>::min() << "\t" << numeric_limits<int>::max();
		}else if (response == "long"){
			clong++;
			cout << numeric_limits<long>::min() << "\t" << numeric_limits<long>::max();
		}else if (response == "float"){
			cfloat++;
			cout << numeric_limits<float>::min() << "\t" << numeric_limits<float>::max();
		}else if (response == "double"){
			cdouble++;
			cout << numeric_limits<double>::min() << "\t" << numeric_limits<double>::max();
		}
		cout << endl;
		cin >> response;		
	}
	cout << "=== A List of # of types ===\n" << "int: " << cint << "\nlong: " << clong << "\nfloat: " << cfloat << "\ndouble: " << cdouble << "\nchar:" << cchar << endl;
}
