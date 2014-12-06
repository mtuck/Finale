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
void mergeSort(T arr[], int size);
template <class T>
void mergeSort(T arr[], T tmp[], int left, int right);
template <class T>
void merge(T arr[], T tmp[], int left, int right, int end);
template <class T>
void bubbleSort(T a[], int size);
template <class T>
void selectionSort(T arr[], int size);
void printMatrixBubble();

int main(){

	int size;
	int *arr;
	int order;
	int choice = 0;
	
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
			case 2: bubbleSort(arr,size); break;
			case 3: selectionSort(arr,size); break;
			case 4: mergeSort(arr,size); break;
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
void bubbleSort(T a[],int size){
    bool cleanPass;
    int i = size-1;
    int j;
	int assignments = 0;
    
    while(i > 0 && !cleanPass){
        cleanPass = true; assignments++;
        for(j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]); assignments += 3;   //takes 3 assignments to swap
              	cleanPass = false; assignments++;
            }
        }
        i = i-1; assignments++;        
    }

}


template <class T>
void printArray(T arr[], int size){
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<"\t";
}

template <class T>
void selectionSort(T arr[], int size){
	T min;
	int minIndex;
	for(int i = 0; i < size-1; i++){
		minIndex = i;
		min = arr[i];
		for(int j = i+1; j < size; j++)
			if(arr[j] < min){
				min = arr[j];
				minIndex = j;
			}
		swap(arr[i], arr[minIndex]);
	}
}


template <class T>
void mergeSort(T arr[], int size){
	T* tmp = new T[size];
	mergeSort(arr, tmp, 0, size-1);
	delete tmp;
}


template <class T>
void mergeSort(T arr[], T tmp[], int left, int right){
	if(left < right){
		int middle = (left + right)/2;
		mergeSort(arr,tmp,left,middle);
		mergeSort(arr,tmp,middle+1,right);
		merge(arr, tmp, left, middle+1,right);
	}
}

template <class T>
void merge(T arr[], T tmp[], int left, int right, int end){
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



