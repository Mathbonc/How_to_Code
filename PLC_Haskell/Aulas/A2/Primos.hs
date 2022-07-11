
isPrime :: Int -> Bool
isPrime n | (isPrime_ n (floor((sqrt n))) > 1) = True
          | otherwise = False

isPrime_ :: Int -> Int -> Int
isPrime_  n r |(isPrime_ > 1) || (r == 0) = 0
              |((n `mod` r) == 0) = 1
              |otherwise = isPrime_ n (r-1)

{-
ehPrimo :: Int -> Bool
ehPrimo n = indivisivel n (n-1)

indivisivel :: Int -> Int -> Bool
indivisivel n 1 = True
indivisivel n x = (n `mod` x /= 0) && indivisivel (x-1)
-}

