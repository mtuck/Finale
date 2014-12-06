#include <iostream>
#include <stdlib.h> 
using namespace std;

template <class T>
void printArray(T arr[], int size); 

//these are not templated becase they need to be specialized for data type
void FillRandom(int arr[], int size);       
void FillOrdered(int arr[], int size); 		
void FillReverseOrder(int arr[], int size); 	

template <class T>
void mergeSort(T arr[], int size, int & assignments, int & comparisons);
template <class T>
void mergeSort(T arr[], T tmp[], int left, int right, int & assignments, int & comparisons);
template <class T>
void merge(T arr[], T tmp[], int left, int right, int end, int & assignments, int & comparisons);
template <class T>
void bubbleSort(T a[], int size, int & assignments, int & comparisons);
template <class T>
void selectionSort(T arr[], int size, int & assignments, int & comparisons);


int main(){

	int size;
	int *arr;
	int order;
	int choice = 0;
	int assignments = 0;
	int comparisons = 0;
	
	cout<<"What size would you like you list to be?";
	cin>>size;
	if(size > 0 && size < 100000)  //change to while loop
		arr = new int[size];
	cout<<"\nHow would you like the array to be filled?\n"
		"1: Ordered\t"
		"2: Reverse Order\t"
		"3: Random\t";
	do{
		cin>>order;
	}while(order < 1 || order >3);
	
	switch(order){
		case 1: FillOrdered(arr,size); break;
		case 2: FillReverseOrder(arr,size); break;
		case 3: FillRandom(arr, size); break;
	}
	
	while(choice != 9){
		cout<<"\n\n1: Print Array\t2: Bubble Sort\t3: Selection Sort\t4: Merge Sort\n5: Quick Sort\t6: Fill Ordered\t7: FillReverse\t8: Fill Random\t9: Exit\t";
		do{
			cin>>choice;
		}while(choice<1 || choice >9);
		cout<<endl;
		switch(choice){
			case 1: printArray(arr,size); break;
			case 2: bubbleSort(arr,size,assignments,comparisons); break;
			case 3: selectionSort(arr,size,assignments,comparisons); break;
			case 4: mergeSort(arr,size,assignments,comparisons); break;
			case 5: cout<<"Quicksort is not completed"; break;
			case 6: FillOrdered(arr,size); break;
			case 7: FillReverseOrder(arr,size); break;
			case 8: FillRandom(arr, size); break;
			case 9: break;
		}
	} 
	
	
	delete [] arr;

	return 0;
}

void FillRandom(int arr[], int size){
	for(int i = 0; i<size; i++)
		arr[i] = rand() % 999;
}

void FillOrdered(int arr[], int size){
	for(int i = 0; i < size; i++)
		arr[i] = i;
}


void FillReverseOrder(int arr[], int size){
	int k = size-1;
	for(int i = 0; i < size; i++)
		arr[i] = k--;
}


template <class T>
void bubbleSort(T a[],int size, int & assignments, int & comparisons){
    bool cleanPass;
    int i = size-1;
    int j;
	assignments = 0;
	comparisons = 2; 	//first loop gaurd
    
    while(i > 0 && !cleanPass){  
        cleanPass = true; 				assignments++;
        for(j = 0; j < i; j++){ 		comparisons++;
            if(a[j] > a[j+1]){ 			comparisons++;
                swap(a[j], a[j+1]); 	assignments+= 3;   //takes 3 assignments to swap
              	cleanPass = false; 		assignments++;
            }
        }
        i = i-1; 						assignments++;
										comparisons += 2; 
    }

}


template <class T>
void printArray(T arr[], int size){
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<"\t";
}

template <class T>
void selectionSort(T arr[], int size, int & assignments, int & comparisons){
	T min;
	int minIndex;
	comparisons = 1;  //initial loop gaurd.. minimum of one comparisons
	assignments = 0;
	
	for(int i = 0; i < size-1; i++){ 	comparisons++;
		minIndex = i;					assignments++;
		min = arr[i];					assignments++;
		for(int j = i+1; j < size; j++){ comparisons++;
			if(arr[j] < min){			comparisons++;
				min = arr[j];			assignments++;
				minIndex = j;			assignments++;
			}
		}
		swap(arr[i], arr[minIndex]);   assignements+=3;
	}
}


template <class T>
void mergeSort(T arr[], int size, int & assignments, int & comparisons){
	T* tmp = new T[size];
	mergeSort(arr, tmp, 0, size-1,assignments,comparisons);
	delete tmp;
}


template <class T>
void mergeSort(T arr[], T tmp[], int left, int right, int & assignments, int & comparisons){
	if(left < right){
		int middle = (left + right,assignments,comparisons)/2;
		mergeSort(arr,tmp,left,middle,assignments,comparisons);
		mergeSort(arr,tmp,middle+1,right,assignments,comparisons);
		merge(arr, tmp, left, middle+1,right,assignments,comparisons);
	}
}

template <class T>
void merge(T arr[], T tmp[], int left, int right, int end, int & assignments, int & comparisons){
	int leftEnd = right-1;
	int curr = left;
	int size = end - left +1;
	
	
	while(left <= leftEnd && right <= end){
		if(arr[left] <= arr[right])
			tmp[curr++] = arr[left++];      //get the smallest item of the two sorted arrays
		else
			tmp[curr++] = arr[right++];
	}
	
	while(left <= leftEnd)
		tmp[curr++] = arr[left++];
	
	while(right <= end)
		tmp[curr++] = arr[right++];
	
	for(int i = 0; i < size; i++, --end){
		arr[end] = tmp[end];
	}
		
}



