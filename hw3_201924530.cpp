#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "Enter the score count: ";
	int maxSize;
	cin >> maxSize;
	
	int* const scores = new int[maxSize];
	int count = 0;
	string command;
	
	while (command.compare("quit")!=0){
		cout << "Enter command: (add, sum, average, quit) ";
		cin >> command;
		
		for (int i=0; i<command.size(); i++){
			command[i]=tolower(command[i]); 
		}
		

		if(command=="add"){
			if(count > maxSize-1){
				cout << "Too many scores" << endl;
			}
			else{
				cout << "Enter score: ";
				cin >> scores[count];
				if(scores[count]<0 || scores[count]>100){
					cout << "Score should be between 0 and 100" << endl;
					scores[count] = 0;
				}
				else{
					cout << "\t" << scores[count] << " added" << endl;
					count++;	
				}	
			}
		}
		else if(command.compare("sum")==0){
			int sum=0;
			for(int j=0; j<count; j++)
				sum+=scores[j];
			cout << "\tSum: " << sum << endl;
		}
		else if(command.compare("average")==0){
			if(count < 1){
				cout << "Enter at least one integer." << endl;
			}
			else{
				float aver=0, sum=0;
				for(int j=0; j<count; j++)
					sum+=scores[j];
				aver = sum / count	;
				cout << "\tAverage: " << aver << endl;
			} 
		}
	}
	cout << "Bye";
	delete [] scores;	
}
