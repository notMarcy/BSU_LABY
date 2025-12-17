#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	srand(time(NULL));
	const int size = 100;
	double arr[size];
	cout<<"Напишите 0, чтобы ввести элементы массива, или 1, чтобы сгенерировать элементы случайным образом: ";
	int a;
	cin>>a;
	int s;
	if(a == 0){
		cout<<"Введите размер массива от 1 до "<<size<<":";
		cin>>s;
		if(s<1 || s>=size){
			s = size-1;
			cout<<"Ха-ха, очень смешно. Количество элементов:"<<s<<endl;
		}

		cout<<"Введите элементы массива:"<<endl;
		for(int i = 0; i<s; i++)
			cin>>arr[i];
	}else if(a == 1){
		int b1;
		int b2;
		cout<<"Введите размер массива от 1 до "<<size<<":";
		cin>>s;
		if(s<1 || s>=size){
			s = size-1;
			cout<<"Ха-ха, очень смешно. Количество элементов:"<<s<<endl;
		}
		cout<<"Введите интервал для генерации элементов массива: ";
		cin>>b1>>b2;
		if(b1>b2)
			swap(b1,b2);
		for(int i = 0; i<s; i++){
			arr[i] = (rand()%(b2*1000-b1*1000))*1./1000+b1;
		}
	}else{
		cout<<"Что ж, ничего не будем делать.";
		return 0;
	}

	cout<<"Массив: ";
	for(int i = 0; i<s; i++)
			cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"Сумма положительных элементов массива: ";
	double sum = 0;
	for(int i = 0; i<s; i++)
		sum += arr[i] > 0 ? arr[i] : 0;
	cout<<sum<<endl;

	cout<<"Произведение элементов, расположенных между максимальным по модулю и минимальным по модулю элементами: ";
	int i_max = 0, i_min=0;
	for(int i = 1; i<s; i++)
	{
		if(abs(arr[i])>abs(arr[i_max]))
			i_max = i;
		if(abs(arr[i])<abs(arr[i_min]))
			i_min = i;
	}
	if(i_min<i_max)
		swap(i_min, i_max);
	double mult = 1;
	for(int i = i_max+1; i<i_min; i++)
		mult*=arr[i];
	if(i_min == i_max)
		mult = 0;
	cout<<mult<<endl;

	cout<<"Массив с упорядоченными элементами на нечетных позициях по убыванию: ";
	for(int i = 1; i<s-2; i+=2)
		for(int j = i+2; j<s; j+=2)
			if(arr[i]<arr[j]){
				double bucket = arr[i];
				arr[i] = arr[j];
				arr[j] = bucket;
			}
	for(int i = 0; i<s; i++)
		cout<<arr[i]<<" ";
	return 0;
}