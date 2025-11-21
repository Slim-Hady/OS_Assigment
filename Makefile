all: linker_ex fork_ex

linker_ex: file1.c file2.c
	gcc file1.c file2.c -o linker_ex

fork_ex: main.c
	gcc main.c -o fork_ex

clean:
	rm -f linker_ex fork_ex
