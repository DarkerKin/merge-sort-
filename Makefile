all: compile_file  

compile_file:
	@g++ merge_sort.cpp -o merge_sort -std=c++11