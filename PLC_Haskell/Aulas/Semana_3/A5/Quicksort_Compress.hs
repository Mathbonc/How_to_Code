qSort :: [Int] -> [Int]
qSort [] = []
qSort [x] = [x]
qSort (x:xs) = qSort(qSort_lesser x xs) ++ [x] ++ qSort(qSort_greater x xs)

qSort_lesser :: Int -> [Int] -> [Int]
qSort_lesser n b = [less | less <- b, less < n]

qSort_greater :: Int -> [Int] -> [Int]
qSort_greater n b = [greater | greater <- b, greater >= n]