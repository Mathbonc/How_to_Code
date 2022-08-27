data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

depth :: Tree t -> Int
depth Nilt = 0
depth (Node a b c) = max (depth b) (depth c) + 1

maiorDiametro :: Ord t => Tree t -> Int
maiorDiametro Nilt = 0
maiorDiametro (Node a b c) = max (1 + depth b + depth c) (max (maiorDiametro b) (maiorDiametro c))

main = do
       s <- getLine
       let result = maiorDiametro (read s::Tree Int)
       print result

