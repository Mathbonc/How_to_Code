somarListas :: [Int] -> [Int] -> [Int]
somarListas [] [] = []
somarListas a [] = a
somarListas [] b = b
somarListas a b
    |(length a >= length b) = invertList (_somarLista (invertList a) (invertList b))
    |otherwise = invertList (_somarLista (invertList b) (invertList a) )


_somarLista :: [Int] -> [Int] -> [Int]
_somarLista (a:[]) []
    |(a > 9) = [a -10,1]
    |otherwise = [a]
_somarLista (a:as) []
    |(a > 9) = [a -10] ++ _somarLista (as) [1]
    |otherwise = (a:as)
_somarLista (a:[]) (b:[])
    |((a+b)>9) = [(a+b)-10,1]
    |otherwise = [a+b]
_somarLista (a:x:as) (b:bs)
    |((a+b)>9) = [(a+b)-10] ++ _somarLista ((x+1):as) (bs)
    |otherwise = [a+b] ++ _somarLista (x:as) bs

invertList :: [Int] -> [Int]
invertList [] = []
invertList (a:as) = invertList as ++ [a]

main :: IO ()
main = do
input1 <- getLine
input2 <- getLine
let result = somarListas (read input1 :: [Int])  (read input2 :: [Int])
print result