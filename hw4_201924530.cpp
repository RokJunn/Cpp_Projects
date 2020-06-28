#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
	string name;
	int score[SUBJECT_NO];
	int sum;
	float average;
} ;

void computeSum(StudentInfo& st);			
void computeAverage(StudentInfo& st);		
void vprintStudents(const vector<StudentInfo>& vstudent, const int no);
void Totalprint(const vector<StudentInfo>& vstudent, const int no);

int main() {
	int studentNo;
	cin >> studentNo;
	vector<StudentInfo> vstudent(studentNo);

	for ( int i = 0 ; i < studentNo ; i ++ ){
		cin >> vstudent[i].name;
		for ( int subject = 0; subject < SUBJECT_NO; subject ++ )
			cin >> vstudent[i].score[subject] ;
		computeSum(vstudent[i]);
		computeAverage(vstudent[i]);
	}
	
	vprintStudents(vstudent, studentNo);
	Totalprint(vstudent, studentNo);
}

void computeSum(StudentInfo& st) {
	for ( int subject = 0; subject < SUBJECT_NO; subject ++ )
		st.sum += st.score[subject];
}

void computeAverage(StudentInfo& st){
	st.average = static_cast<float> (st.sum) / SUBJECT_NO;
}

void vprintStudents(const vector<StudentInfo>& vstudent, const int no){
	vector<StudentInfo>::const_iterator it = vstudent.begin();
	for ( int i = 0 ; i < no ; i ++ ){
		cout << i + 1 << '\t' ;
		cout << it[i].name << '\t';
		for ( int subject = 0; subject < SUBJECT_NO; subject ++ )
			cout << it[i].score[subject] << '\t';
		cout << it[i].sum << '\t' << it[i].average << endl;
	}
}
void Totalprint(const vector<StudentInfo>& vstudent, const int no){
	int Tsub1=0, Tsub2=0, Tsub3=0, Tsum=0;
	for(int i=0; i<no; i++){
		Tsub1 += vstudent[i].score[0];
		Tsub2 += vstudent[i].score[1];
		Tsub3 += vstudent[i].score[2];
		Tsum += vstudent[i].sum;
	}
	cout << "Total\t\t" << Tsub1 << "\t" << Tsub2 << "\t" << Tsub3 << "\t" << Tsum << "\t";
}
