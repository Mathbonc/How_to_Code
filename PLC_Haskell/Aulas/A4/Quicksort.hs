module Quicksort where

{-
    Basicamente, é criado um vetor com todos os números menores que o pivot (nesse caso o primeiro número da lista)
    e essa lista é colocada novamente no qSort, para recursão.
-}

qSort :: [Int] -> [Int]
qSort [] = []
qSort [x] = [x]
qSort (x:xs) = qSort(qSort_lesser x xs) ++ [x] ++ qSort(qSort_greater x xs)

qSort_lesser :: Int -> [Int] -> [Int]
qSort_lesser n [] = []
qSort_lesser n (x:xs) | (x<n) = qSort_lesser n (xs) ++ [x]
                      | otherwise = qSort_lesser n (xs)

qSort_greater :: Int -> [Int] -> [Int]
qSort_greater n [] = []
qSort_greater n (x:xs) | (x>=n) = qSort_greater n (xs) ++ [x]
                      | otherwise = qSort_greater n (xs)