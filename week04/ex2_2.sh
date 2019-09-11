gcc ex2_2.c -o ex2_2.o
./ex2_2.o &
for (( i = 0; i < 6; i++ )); do
	pstree $!
	sleep 5
done