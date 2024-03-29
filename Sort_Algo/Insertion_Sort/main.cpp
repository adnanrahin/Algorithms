#include <iostream>
#include <cmath>

using namespace std;

void insertion_sort(int arr[],int n){
	for(int i=0; i<n; i++){
		int j = i-1;
		while(j>=0 and arr[j]<arr[j-1]){
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
}

int main(){

	int arr[1005];
	
	srand(time(0));
	
	for(int i=0; i<1000; i++) arr[i] = rand()%100;
	insertion_sort(arr,1000-1);
	for(int i=0; i<1000; i++) cout << arr[i] << " ";
	
	cout << endl; 

}
