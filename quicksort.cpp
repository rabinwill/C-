

#include<stdio.h>
#include <array>
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);	//index of smaller elemenet

	//if current elemet is less than or equal to the pivot
	for (int j = low; j <= high - 1; j++){
		if(arr[j] <= pivot)
		{
			i++;	//incrementing the index of smaller element
			swap(&arr[i], &arr[j]);
		}

	}
	swap (&arr[i+1], &arr[high]);
	return (i+1);
}
void printArray(int arr[], int size)
{
	int z;
	for (z = 0; z < size; z++){
		cout<<" Array[" << z <<"]: "<< arr[z];
	}
	cout<<"\n";
}
void quicksort(int arr[], int low, int high)
{
	if (low<high)		//making sure array is not empty
	{
		int pi = partition(arr, low, high);

		cout<<"\nPartition: "<<pi<<"\n";
		cout<<"1st attempt!";
		printArray(arr, high+1);
		quicksort(arr, low, pi -1);

		quicksort(arr, pi+1, high);
	}
}


int main() {
	
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	//cout<<"sizeof(arr): "<< sizeof(arr) << " sizeof(arr[0]): "<< sizeof(arr[0]);

	quicksort(arr, 0, n-1);
	cout<<"\nSorted array : "<< n << "\n";
	printArray(arr, n);
	return 0;
	
}

