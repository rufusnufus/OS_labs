gcc ex1.c -o ex1.o
for (( i = 0; i < 10; i++ )); do
	./ex1.o
	echo "\n"
done