fatPrime :: Int -> [(Int,Int)]
fatPrime a
    |(a `mod` 2 == 0) = [(2,countPrime a 2)] ++ _fatPrime (a `div` (2^(countPrime a 2))) 3 a
    |otherwise = _fatPrime a 3 a

_fatPrime :: Int -> Int -> Int -> [(Int,Int)]
_fatPrime 1 _ _ = []
_fatPrime a b c
    |(b==a) = [(b,1)]
    |(b > ceiling (sqrt(fromIntegral c))) = check a
    |(a `mod` b == 0) = [(b,countPrime a b)] ++ _fatPrime (a `div` (b^(countPrime a b))) (b+2) c
    |otherwise = _fatPrime a (b+2) c

countPrime :: Int -> Int -> Int
countPrime 1 _ = 0
countPrime a b
    |(a `mod` b == 0) = countPrime (a `div` b) b + 1
    |otherwise = 0 

check :: Int -> [(Int,Int)]
check a
    |(a>2) = [(a,1)]
    |otherwise = []

main = do
       a <- getLine
       let result = fatPrime (read a::Int) 
       print result