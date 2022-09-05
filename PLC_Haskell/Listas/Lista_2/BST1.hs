data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

arvore :: Tree Int
arvore = Node 40 (Node 35 (Node 29 Nilt Nilt) (Node 37 Nilt Nilt)) (Node 55 Nilt (Node 60 Nilt Nilt))

isBST :: Ord t => Tree t -> Bool
isBST Nilt = True
isBST a = _isBST(collapseTree a)

_isBST :: Ord t => [t] -> Bool
_isBST (a:[]) = True
_isBST (a:b:as)
    |(a < b) = _isBST (b:as)
    |otherwise = False

collapseTree :: Tree t -> [t]
collapseTree Nilt = []
collapseTree (Node a b c) = collapseTree b ++ [a]  ++ collapseTree c

main = do
       s <- getLine
       let result = isBST (read s::Tree Int)
       print result