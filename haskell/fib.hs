fib :: Integer -> Integer
fib n = fib_h n 1 1

fib_h :: Integer -> Integer -> Integer -> Integer
fib_h 0 res1 res2 = res1
fib_h n res1 res2 = fib_h (n - 1) (res2) (res2 + res1)

main = do
	putStrLn $ show $ map fib [0..10]
