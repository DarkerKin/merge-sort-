#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int starting_index, int middle_index, int ending_index) {
    int size_of_first_array = middle_index - starting_index + 1;
    int size_of_second_array = ending_index - middle_index;

    vector<int> first_array(size_of_first_array);
    vector<int> second_array(size_of_second_array);

    for (int i = 0; i < size_of_first_array; i++) {
        first_array[i] = arr[starting_index + i];
    }
    for (int i = 0; i < size_of_second_array; i++) {
        second_array[i] = arr[middle_index + 1 + i];
    }

    int first_array_pointer = 0, second_array_pointer = 0, arr_pointer = starting_index;

    while (first_array_pointer < size_of_first_array && second_array_pointer < size_of_second_array) {
        if (first_array[first_array_pointer] <= second_array[second_array_pointer]) {
            arr[arr_pointer++] = first_array[first_array_pointer++];
        } else {
            arr[arr_pointer++] = second_array[second_array_pointer++];
        }
    }

    while (first_array_pointer < size_of_first_array) {
        arr[arr_pointer++] = first_array[first_array_pointer++];
    }

    while (second_array_pointer < size_of_second_array) {
        arr[arr_pointer++] = second_array[second_array_pointer++];
    }
}

void mergeSort(int arr[], int starting_index, int ending_index) {
    if (starting_index < ending_index) {
        int middle_index = starting_index + (ending_index - starting_index) / 2;
        mergeSort(arr, starting_index, middle_index);
        mergeSort(arr, middle_index + 1, ending_index);
        merge(arr, starting_index, middle_index, ending_index);
    }
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 301;
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // generate different random integers

    if (argc < 2) {
        cout << "Usage: ./merge_sort <size> OR ./merge_sort <start> <end> <step>" << endl;
        return -1;
    }

    ofstream outfile("results.jsonl", ios::app); // append results to file

    if (argc == 2) {
        // Single size
        int array_size = atoi(argv[1]);
        vector<int> arr(array_size);

        generateRandomArray(arr.data(), array_size);

        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr.data(), 0, array_size - 1);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        outfile << "{\"size\": " << array_size << ", \"Elapsed time\": " << duration.count() << "}" << endl;
    } 
    else if (argc == 4) {
        // Range mode: start, end, step (looping in reverse)
        int start_size = atoi(argv[1]);
        int end_size = atoi(argv[2]);
        int step = atoi(argv[3]);

        for (int array_size = end_size; array_size >= start_size; array_size -= step) {
            vector<int> arr(array_size);

            generateRandomArray(arr.data(), array_size);

            auto start = chrono::high_resolution_clock::now();
            mergeSort(arr.data(), 0, array_size - 1);
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

            outfile << "{\"size\": " << array_size << ", \"Elapsed time\": " << duration.count() << "}" << endl;
        }
    } 
    else {
        cout << "Invalid arguments. Use:" << endl;
        cout << "  ./merge_sort <size>" << endl;
        cout << "  ./merge_sort <start> <end> <step>" << endl;
        return -1;
    }

    outfile.close();
    return 0;
}

