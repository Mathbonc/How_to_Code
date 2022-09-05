bSort :: [String] -> [String]
bSort [] = []
bSort [x] = [x]
bSort (x:xs) = bSort(bSort_lesser x xs) ++ [x] ++ bSort(bSort_greater x xs)

bSort_lesser :: String -> [String] -> [String]
bSort_lesser n [] = []
bSort_lesser n (x:xs) | (not(stringOrder n x)) = bSort_lesser n (xs) ++ [x]
                      | otherwise = bSort_lesser n (xs)

bSort_greater :: String -> [String] -> [String]
bSort_greater n [] = []
bSort_greater n (x:xs) | ((stringOrder n x)) = bSort_greater n (xs) ++ [x]
                      | otherwise = bSort_greater n (xs)

stringOrder :: String -> String -> Bool -- A < B -> True 
stringOrder [] [] = True
stringOrder a [] = False 
stringOrder [] a = True
stringOrder (a:as) (b:bs)
    |(a<b) = True
    |(a==b) = stringOrder as bs
    |otherwise = False

teste :: [String]
teste = ["zab","bza","azb","baz","zba"]

main = do
       a <- getLine
       let result = bSort (read a :: [String])
       print result