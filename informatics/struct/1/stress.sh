g++ gen.cpp -o gen
g++ 7.cpp -o ans
while true
do
	./gen > input.txt
	./ans < input.txt > output.txt || break
done
