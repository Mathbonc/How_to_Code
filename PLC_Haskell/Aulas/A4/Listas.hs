import Fibonacci
import Quicksort

double :: [Int] -> [Int]
double [] = [] --caso base
double (a:as) = (a*2) : double as

member :: [Int] -> Int -> Bool
member [] _ = False -- !Nesse caso, o '_' serve como dontcare.
member (cabess:cauda) n | (cabess == n) = True
                        | otherwise = member cauda n

digits :: String -> String
digits [] = []
digits (cb:ca) | (cb >= '0' && cb <= '9') = cb : digits ca
               | otherwise = digits ca

sumPairs :: [Int] -> [Int] -> [Int]
sumPairs [] [] = []
sumPairs (x:xs) (y:ys) = (x+y) : sumPairs xs ys
sumPairs [] (y:ys) = (y) : sumPairs [] ys
sumPairs (x:xs) [] = (x) : sumPairs xs []

-- TODO: CASAMENTO DE PADRÕS

--Fibonacci
