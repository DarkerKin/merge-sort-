all: compile_file run_file 

compile_file:
	@echo "compiling file...";
	g++ merge_sort.cpp -o merge_sort

run_file:
	@echo "running file..."
	clear
	@./merge_sort 11

clean_file:
	@echo "removing executable"
	@rm merge_sort