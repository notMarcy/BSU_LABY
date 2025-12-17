#include <iostream>
using namespace std;

int get_element(int* m[], int size, int a, int b){
	if(b>=size-a)
		return m[size-b-1][size-a-1];
	return m[a][b];
}

void matrix_output(int* m[], int size){
	int a,b;
	for(int i = 0; i<size;i++){
		for(int j = 0; j<size; j++){
			cout<<get_element(m,size,i,j)<<" ";
		}
		cout<<endl;
	}
}

bool if_local_min(int* m[], int size, int a, int b){
	const int pair[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
	for(int k = 0; k<8; k++){
				if(a+pair[k][0]>=0 && a+pair[k][0] < size && b+pair[k][1]>=0 && b+pair[k][1]<size)
					if(m[a][b]>=m[a+pair[k][0]][b+pair[k][1]])
						return false;
			}
	return true;
}

void count_local_min(int* m[], int size){
	int a,b, counter = 0;
	for(int i = 0; i<size;i++){
		for(int j = 0; j<size; j++){
			a = i,b = j;
			if(j>=size-i){
				a = size-j-1;
				b = size-i-1;
			}
			if(if_local_min(m, size, a, b)) counter++;
		}
	}
	cout<<"Количество локальных минимумов: "<<counter<<endl;
}

void count_above_diag(int* m[], int size){
	int a,b, sum = 0;
	for(int i = 0; i<size-1;i++){
		for(int j = i+1; j<size; j++){
			sum += get_element(m,size,i,j);
		}
	}
	cout<<"Сумма элементов выше главной диагонали: "<<sum<<endl;
}

int main(){
	int size;
	cout<<"Введите размер матрицы от 1 до 10: ";
	cin>>size;

	if(size<1 || size>10){
		cout<<"Размер введен неверно, дальнейшие действия не будут выполнены"<<endl;
		return 0;
	}

	cout<<"Введите элементы матрицы в указанном количестве: "<<endl;
	int* m[size];
	for(int i = 0; i<size; i++){
		m[i] = new int[size-i];
		cout<<"Введите "<<size-i<<" элементов"<<endl;
		for(int j = 0; j<size-i; j++)
				cin>>m[i][j];
	}
	
	cout<<"Матрица: "<<endl;
	matrix_output(m, size);
	count_local_min(m,size);
	count_above_diag(m, size);
	return 0;
}