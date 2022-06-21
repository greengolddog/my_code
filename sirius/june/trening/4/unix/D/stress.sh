g++ solve.cpp -o solve.out
g++ stupid.cpp -o stupid.out
g++ gen.cpp -o get.out
cp empty.txt solve.txt
cp empty.txt stupid.txt
while (diff solve.txt stupid.txt) {
	./gen < inp.txt > input.txt
	./solve.out < input.txt > solve.txt
	./stupid.out < input.txt > stupid.txt
}
cat input.txt
