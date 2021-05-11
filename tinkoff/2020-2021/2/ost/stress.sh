g++ gen.cpp -o gen
g++ to1.cpp -o smart
g++ to12.cpp -o stup

while true
do
  ./gen >input.txt
  ./smart <input.txt >smart.out
  ./stup <input.txt >stup.out
  diff smart.out stup.out || break
done
