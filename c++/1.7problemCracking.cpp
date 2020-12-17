#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int matrix[n][n];
	int b = 0;
	for(int i=0; i < n; i++){
		cout << "Inserta la fila\n";
		for(int j=0; j < n; j++){
			cin >> matrix[j][i];
		}
	}
	int rn=n-1;
	for(int i=0; i < n/2; i++){
		for(int j=b; j < rn-b; j++){
			int a = matrix[j][i];
			//cout << to_string(a)+"\n";
			matrix[j][i] = matrix[rn-i][j];
			matrix[rn-i][j] = matrix[rn-j][rn-i];
			matrix[rn-j][rn-i] = matrix[i][rn-j];
			matrix[i][rn-j] = a;
		}
		b++;
	}

	cout << "\n";
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cout << to_string(matrix[j][i])+" ";
		}
		cout << "\n";
	}
	return 0;
}