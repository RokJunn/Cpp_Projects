#include <iostream>
#include <string>

using namespace std;
int main(){
	string name;
	int score;
	while(score >=0 && score <= 100){
		cout << "Enter a name and score : ";
		cin >> name >> score;
	
		if (score >= 90 && score <= 100)
			cout << "Hi " << name << "! Your grade is A" << endl;
		if (score >= 80 && score < 90)
			cout << "Hi " << name << "! Your grade is B" << endl;
		if (score >= 70 && score < 80)
			cout << "Hi " << name << "! Your grade is C" << endl;	
		if (score >= 60 && score < 70)
			cout << "Hi " << name << "! Your grade is D" << endl;
		if (score >= 0 && score < 60)
			cout << "Hi " << name << "! Your grade is F" << endl;	
	}
	cout << "Bye " << name << endl;
}
