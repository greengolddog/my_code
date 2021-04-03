from math import floor
minn = int(input("enter from"))
maxx = int(input("enter to"))
sotni = ["", "сто ", "двести ", "тристо ", "четыресто ", "пятьсот ", "шестьсот ", "семьсот ", "восемьсот ", "девятьсот "]
tens = ["", "десять ", "двадцать ", "тридцать ", "сорок ", "пятьдесят ", "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто "]
ones_10 = ["десять манулов", "одиннадцать манулов", "двенадцать манулов", "тринадцать манулов", "четырнадцать манулов", "пятнадцать манулов", "шестнадцать манулов", "семьнадцать манулов", "восемьнадцать манулов", "девятнадцать манулов"]
ones = ["манулов", "один манул", "два манула", "три манула", "четыре манула", "пять манулов", "шесть манулов", "семь манулов", "восемь манулов", "девять манулов"]
for i in range(minn, maxx):
    kus = floor(i / 1000) % 1000
    if kus == 1:
        print("тысяча ", end='')
    elif kus > 0:
        sto = floor(kus / 100) % 10
        print(sotni[sto], end='')
        ten = floor(kus / 10) % 10
        one = kus % 10
        if ten == 1:
            print(ones_10[one].split()[0], end=' ')
            print("тысяч ", end='')
        else:
            print(tens[ten], end='')
            if one > 1:
                if one == 2:
                    print("две", end=' ')
                    print("тысячи ", end='')
                elif one < 4:
                    print(ones[one].split()[0], end=' ')
                    print("тысячи ", end='')
                else:
                    print(ones[one].split()[0], end=' ')
                    print("тысяч ", end='')
            else:
                print("тысяч ", end='')
    sto = floor(i / 100) % 10
    print(sotni[sto], end='')
    ten = floor(i / 10) % 10
    one = i % 10
    if ten == 1:
        print(ones_10[one])
    else:
        print(tens[ten], end='')
        print(ones[one])

