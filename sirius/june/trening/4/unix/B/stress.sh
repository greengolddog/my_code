g++ solve.cpp -o solve.out
g++ stupid.cpp -o stupid.out
g++ gen.cpp -o get.out
while true
do
	./gen.out < inp.txt > input.txt
	./solve.out < input.txt > solve.txt
	./stupid.out < input.txt > stupid.txt
	diff solve.txt stupid.txt || break
	cat ok.txt
done
cat input.txt
