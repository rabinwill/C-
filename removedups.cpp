#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;


int removeDeuplicates(int arr[], int n){

	for (int i = 0; i<n; ++i){
		//comparing each element with all other elemets in the array since its not sorted
		for(int j=i+1; j<n; ++j){

			if(arr[i]==arr[j]){
				cout<<"arr[i]: "<<arr[i]<<" arr[j]:"<<arr[j]<<"\n";
				for (int r =j; r<n-1; ++r){
					//moving elements to the ledt 
					arr[r]=arr[r+1];
				}
				--n;
			}
		}
	}

	return n;
}

int main() {

	int arr[] = {72,77,24,2,35,2,8,24,72,77};

	int n = sizeof(arr)/sizeof(arr[0]);

	n = removeDeuplicates(arr, n);

	for (int j=0; j<n; j++){

		cout<<arr[j]<<"\n";
	}
}