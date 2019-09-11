gcc ex2.c -o ex2.o
./ex2.o &
for (( i = 0; i < 4; i++ )); do
	pstree $!
	sleep 5
done