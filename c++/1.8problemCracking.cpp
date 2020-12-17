#include <iostream>
using namespace std;

int main(){
	int M,N;
	cin >> M;
	cin >> N;
	bool arrM[M]={false};
	bool arrN[N]={false};
	int matrix[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> matrix[i][j];
		}
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(arrM[i]==false && arrN[j]==false && matrix[i][j]==0){
				for(int ip=0; ip<M; ip++){
					matrix[ip][j]=0;
				}
				for(int jp=0; jp<N; jp++){
					matrix[i][jp]=0;
				}
				arrM[i]=true;
				arrN[j]=true;
			}
		}
	}
	cout << "\n";
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cout << to_string(matrix[i][j])+ " ";
		}
		cout << "\n";
	}
	return 0;
}