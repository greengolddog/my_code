g++ E.cpp -o E.out
g++ Estupid.cpp -o Estupid.out
g++ Egen.cpp -o Eget.out
while true
do
        ./Egen.out < inp.txt > input.txt
        ./E.out < input.txt > E.txt
        ./Estupid.out < input.txt > Estupid.txt
        diff E.txt Estupid.txt || break
        cat ok.txt
done
cat input.txt
