#include <iostream>
#include <vector>
using namespace std;
enum MajorType { CE, EE, ME, UD};

class Major {
private:
	MajorType majorType ;
public:
	friend class Student;
	void setMajorType(const MajorType _major) {
    	majorType = _major ;
    }
    MajorType majorTypegetter(){
    	return majorType;
	}
};

class Student {
private:
	string name ;
	float gpa ;
	Major major ;
public:
	void setName(const string& _name){
		name = _name;
	}
	void setGPA(float _gpa) {
		gpa = _gpa;
	}
	void setMajor(const MajorType _major){
		major.setMajorType(_major);			
	}
	string namegetter(){
		return name;
	}	
	float gpagetter(){
		return gpa;
	}
	MajorType majorgetter(){
		return major.majorTypegetter();
	}
} ;

class School {
private:
	string schoolName ;
	vector<Student> students ;
public:
	School(const string& univname){
		schoolName = univname;
	}
	Student* addStudent(const string& name, const float gpa = 0){
		Student newStud;
		newStud.setName(name);
		newStud.setGPA(gpa);
		students.push_back(newStud);
		return &students[students.size()-1];
	}
	Student* addStudent(const string& _name, MajorType _major){
		Student newStud;
		newStud.setName(_name);
		newStud.setMajor(_major);
		students.push_back(newStud);
		return &students[students.size()-1];
	}
	
	void print() {
		cout << "School Name : " << schoolName << ", Count : " << students.size() << endl; 
		for(int i=0; i<students.size(); i++){
			cout << "\t Name : " << students[i].namegetter() << "\t GPA : " << students[i].gpagetter();
			MajorType StuMajor = students[i].majorgetter() ;
			if ( StuMajor == CE)
				cout << "\tMajor : " << "Computer Eng." << endl; 
			else if ( StuMajor == ME)
				cout << "\tMajor : " << "Mechanical Eng." << endl; 
			else if ( StuMajor == EE)
				cout << "\tMajor : " << "Electrical Eng." << endl; 
			else
				cout << "\tMajor : " << "Undefined" << endl;
		}
		cout << endl;
	}
	
	void sort() {
		for(int i=0; i<students.size()-1;  i++){
			for(int j=0; j<students.size()-1-i; j++){
				if(students[j].gpagetter()<students[j+1].gpagetter()){
					Student temp = students[j];
					students[j]  = students[j+1];
					students[j+1] = temp;	
				}
			}
		}
	}
} ;

int main() {
	School pnu("PNU") ;
	Student* kim = pnu.addStudent("Kim", EE) ;
	kim->setGPA(3.5F) ;
	Student* hong = pnu.addStudent("Hong", CE) ;
	hong->setGPA(4.3F) ;
	Student* lee = pnu.addStudent("Lee", 4.0F) ;
	lee->setMajor(CE) ;
	Student* joo = pnu.addStudent("Joo", 1.5F) ;
	joo->setMajor(ME) ;
	pnu.print() ;
	pnu.sort() ; // descending
	pnu.print() ;
}
