data Tree t = Nilt |
               Node t (Tree t) (Tree t)
               deriving (Read, Show)

testTree :: Tree Int
testTree = Node 10 (Node 5 (Nilt) (Nilt)) (Nilt)

insertList :: Ord t => Tree t -> [t] -> Tree t
insertList tree [] = tree
insertList tree (a:as) = insertList (_insertList tree a) as

_insertList :: Ord t => Tree t -> t -> Tree t
_insertList Nilt x = (Node x Nilt Nilt)
_insertList (Node a b c) x
    |(x<a) = Node a (_insertList b x) c
    |otherwise = Node a b (_insertList c x)

main = do
       a <- getLine
       b <- getLine
       let result = insertList (read a::Tree Int) (read b)
       print result