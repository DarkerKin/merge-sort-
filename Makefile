all: compile_file run_file 

compile_file:
	@echo "compiling file...";
	g++ merge_sort.cpp -o merge_sort

run_file:
	@echo "running file..."
	clear
	@touch output.txt
	@./merge_sort 11 > output.txt

clean_file:
	@echo "removing executable"
	@rm merge_sort output.txt