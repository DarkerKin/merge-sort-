#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[],int starting_index, int middle_index, int ending_index){
	
	

	int size_of_first_array = middle_index - starting_index+ 1;
	int size_of_second_array = ending_index - middle_index;


	vector<int> first_array(size_of_first_array);
	vector<int> second_array(size_of_second_array);

	for(int i = 0; i < size_of_first_array; i++){
		first_array[i] = arr[starting_index+i];
	}

	for(int i = 0; i < size_of_second_array; i++){
		second_array[i] = arr[middle_index+1+i];
	}

	int first_array_pointer = 0, second_array_pointer = 0, arr_pointer = starting_index;

	while( first_array_pointer < size_of_first_array && second_array_pointer < size_of_second_array ){
		if(first_array[first_array_pointer] <= second_array[second_array_pointer]){
			arr[arr_pointer] = first_array[first_array_pointer];
			first_array_pointer++;
		}
		else{
			arr[arr_pointer] = second_array[second_array_pointer];
			second_array_pointer++;
		}
		arr_pointer++;
	}

	while(first_array_pointer < size_of_first_array){
		arr[arr_pointer] = first_array[first_array_pointer];
		arr_pointer++;
		first_array_pointer++;
	}

	while(second_array_pointer < size_of_second_array){
		arr[arr_pointer] = second_array[second_array_pointer];
		arr_pointer++;
		second_array_pointer++;
	}
}

void mergeSort(int arr[], int starting_index, int ending_index){
	if(starting_index < ending_index){
		int middle_index = starting_index + (ending_index - starting_index)/2;
		mergeSort(arr,starting_index,middle_index);
		mergeSort(arr,middle_index + 1, ending_index);
		merge(arr,starting_index,middle_index,ending_index);
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i < size -1; i++)cout <<arr[i] << ", ";
	cout<< arr[size-1]<< endl;
}

void generateRandomArray(int arr[],int size){
	
	for(int i = 0; i < size; i++){
		arr[i] = rand()%301;
	}
}

int main(int argc,char *argv[]){

	//start timer
	auto start = chrono::high_resolution_clock::now();

	srand(time(NULL)); //to generate different random integer

	if(argc == 1){
		cout <<"please enter a array size"<<endl;
		return -1;
	}

	int array_size = atoi(argv[1]);
	int arr[array_size];

	generateRandomArray(arr,array_size);
	cout << "array before sorting: "<<endl;
	printArray(arr,array_size);

	mergeSort(arr,0,array_size-1);
	cout << "array after sorting: "<<endl;
	printArray(arr,array_size);

	// End time
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Elapsed time: " << duration.count() << " nanoseconds " << endl;

	return 0;
}