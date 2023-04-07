GC=gcc -g -Wall -Werror -Wextra
O=-o compile

all: sih snh prs
	$(GC) stack_info.o stack_num.o parser.o $(O)

sih:
	$(GC) -c stack_info.c 

snh:
	$(GC) -c stack_num.c

prs:
	$(GC) -c parser.c
