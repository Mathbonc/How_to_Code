data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

arvore :: Tree Int
arvore = Node 432 (Node 5 Nilt (Node 378 Nilt Nilt)) (Node 698 Nilt Nilt)

arvore2 :: Tree Int
arvore2 = Node 960 (Node 228 (Node 102 Nilt (Node 222 Nilt Nilt)) (Node 456 (Node 244 Nilt Nilt) (Node 784 Nilt (Node 920 (Node 861 Nilt Nilt) (Node 952 Nilt Nilt))))) Nilt

collapseTree :: Tree t -> [t]
collapseTree Nilt = []
collapseTree (Node a b c) = collapseTree b ++ [a]  ++ collapseTree c

dna1 :: Tree Int -> [String]
dna1 a = packEight(collapseTree a)

packEight :: [Int] -> [String]
packEight [] = []
packEight a
    |(length a > 8) = [convert (take 8 a)] ++ packEight (drop 8 a)
    |otherwise = [convert a]

convert :: [Int] -> String
convert [] = []
convert (a:as)
    |(a `mod` 5 == 0) = 'E' : convert as
    |(a `mod` 5 == 1) = 'M' : convert as
    |(a `mod` 5 == 2) = 'A' : convert as
    |(a `mod` 5 == 3) = 'C' : convert as
    |(a `mod` 5 == 4) = 'S' : convert as
    
main :: IO ()
main = do

  input <- getLine

  let result = dna1 (read bin :: Tree Int)

  print result