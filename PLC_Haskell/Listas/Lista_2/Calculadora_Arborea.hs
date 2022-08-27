data Ops = SUM | MUL | SUB
           deriving (Read)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)

evalTree :: IntTree -> Int
evalTree (Nilt a) = a
evalTree (Node SUM a b) = evalTree a + evalTree b
evalTree (Node SUB a b) = evalTree a - evalTree b
evalTree (Node MUL a b) = evalTree a * evalTree b

main = do
    s <- getLine
    let result = evalTree (read s)
    print result