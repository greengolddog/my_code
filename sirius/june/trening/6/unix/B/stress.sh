g++ solve.cpp -o solve
g++ stupid.cpp -o stupid
g++ gen.cpp -o gen
while true
do
	./gen < inp.txt > input.txt
	./solve < input.txt > solve.txt
	./stupid < input.txt > stupid.txt
	diff solve.txt stupid.txt || break
	cat ok.txt
done
cat input.txt
