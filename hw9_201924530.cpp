#include <iostream>
using namespace std;

class Matrix {
	int** values ;
	int row, column ;
public:
	Matrix(const int _row=2, const int _column=2){
		row = _row;
		column = _column;
		values = new int*[column];
		for (int i=0; i<_column; ++i){
			values[i] = new int[row];	
		}
	}
	Matrix(const Matrix& another){
		row = another.row;
		column = another.column;
		for (int i=0; i<another.row; ++i)
			for (int j=0; j<another.column; ++j)
				values[i][j] = another.values[i][j];
	}
	~Matrix(){
		for(int i=0; i<column; i++)
			delete [] values[i];
		delete [] values;
	}
	Matrix operator + (const Matrix& m) const{
		Matrix newmatrix(2,2);
		for (int i=0; i<row; i++){
			for (int j=0; j<column; j++){
				newmatrix.values[i][j] = values[i][j] + m.values[i][j];
			}
		}
		return newmatrix;
	}
	Matrix operator * (const int number) const{
		Matrix newmatrix(2,2);
		for (int i=0; i<row; i++){
			for (int j=0; j<column; j++){
				newmatrix.values[i][j] = values[i][j] * number;	
			}
		}
		return newmatrix;	
	}
	Matrix& operator = (const Matrix& another){
		delete [] values;
		values = new int*[row];
		for (int i=0; i<row; ++i){
			values[i] = new int[column];	
		}
		for (int i=0; i<row; i++){
			for (int j=0; j<column; j++){
				values[i][j] = another.values[i][j];
			}
		}
		return *this;
	}
	friend ostream& operator << (ostream& os, const Matrix& m);
	friend istream& operator >> (istream& is, Matrix& m);
};

ostream& operator << (ostream& os, const Matrix& m){
	for (int i=0; i<m.column; ++i){
		for (int j=0; j<m.row; ++j){
			os << m.values[i][j] << "\t";
		}
		os << endl;	
	}
	return os;	
}
istream& operator >> (istream& is, Matrix& m){
	for (int i=0; i<m.column; i++){
		for (int j=0; j<m.row; j++){
			is >> m.values[i][j];
		}
	}	
	return is;	
}

int main() {
	Matrix m1(2, 2), m2(2, 2) ;
	cin >> m1 ;
	cin >> m2 ;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

    m4 = m3 * 10 ;

	cout << m3 << endl << m4 << endl ;
}

