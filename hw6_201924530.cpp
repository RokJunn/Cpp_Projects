#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
	string name ;
	float gpa ;
public:	
	void setName(const string& _name){
		name = _name;
	}
	void setGPA(float _gpa) {
		gpa = _gpa;
	}
	string namegetter(){
		return name;
	}	
	float gpagetter(){
		return gpa;
	}
};

class School {
private:
	string schoolName ;
	vector<Student> students ;
public:
	School(const string& univname){
		schoolName = univname;
	}
	
	void addStudent(const string& name, const float gpa = 0){
		Student newStud;
		newStud.setName(name);
		newStud.setGPA(gpa);
		students.push_back(newStud);
	}
	
	void print() {
		cout << "School Name : " << schoolName << ", Count : " << students.size() << endl; 
		for(int i=0; i<students.size(); i++){
				cout << "\t Name : " << students[i].namegetter() << " GPA : " << students[i].gpagetter() << endl;
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
	
	Student& findStudentWithName(const string& findname){
		for(int i=0; i<students.size(); i++)
			if(students[i].namegetter() == findname) return students[i];
	}
};
	
int main() {
	School pnu("PNU") ;
	pnu.addStudent("Kim", 2.7F) ;
	pnu.addStudent("Hong", 3.5F) ;
	pnu.addStudent("Lee") ;
	pnu.addStudent("Joo", 1.5F) ;
	pnu.print() ;
	pnu.sort() ; // descending
	pnu.print() ;
	School knu("KNU") ;
	knu.addStudent("Seo", 2.5F) ;
	knu.addStudent("Lee", 3.8F) ;
	knu.print() ;
	Student& lee = pnu.findStudentWithName("Lee") ;
	lee.setGPA(3.3F) ;
	lee.setName("Yoon") ;
	pnu.print() ;
	knu.addStudent("Hong", 4.3F) ;
	Student& hong = knu.findStudentWithName("Hong") ;
	hong.setGPA(3.3F) ;
	hong.setName("Joon") ;
	knu.print() ;
}

