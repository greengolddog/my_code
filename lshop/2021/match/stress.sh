g++ gen.cpp -o gen -std=c++11
g++ D.cpp -o smart -std=c++11
g++ stupid.cpp -o stup -std=c++11  # скомпилили генератор и оба решения
while true
do
	./gen < input.txt > output.txt  # сгенерили и сохранили в input.txt
    cp output.txt input.txt
	./smart < input.txt > smart.out  # считали из input.txt и сохранили в smart.out
	./stup < input.txt > stup.out  # считали из input.txt и сохранили в stup.out
	diff smart.out stup.out || break  # сравнили вывод smart и stup. если отличаются, брейкнулись. теперь в input.txt тест, на котором ломается
    cat input.txt
done
