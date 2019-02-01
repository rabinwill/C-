#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;


int removeDeuplicates(int arr[], int n){

	for (int i = 0; i<n; ++i){
		if(arr[i] == arr[i+1]){
			//shifting elements to the left
			for(int r=i; r<n-1; ++r){
				arr[r]=arr[r+1];
			}
			--n;
		}
	}

	return n;
}

int main() {

	int arr[] = {1,1,2,2,3,4,5,5,7,7};

	int n = sizeof(arr)/sizeof(arr[0]);

	n = removeDeuplicates(arr, n);

	for (int j=0; j<n; j++){

		cout<<arr[j]<<"\n";
	}
}