data Expr = Lit Int
            | Add Expr Expr
            | Sub Expr Expr
            deriving(Eq,Show)


showExpr :: Expr -> String
showExpr (Lit a) = show a
showExpr (Add a b) = showExpr a ++ "+" ++ showExpr b
showExpr (Sub a b) = showExpr a ++ "-" ++ showExpr b

data List t = Nil 
             | Cons t (List t)
             deriving (Show)

toList :: List t -> [t]
toList Nil = []
toList (Cons a b) = a:toList b

fromList :: [t] -> List t
fromList [] = Nil
fromList (a:as) = Cons a (fromList as)

data Tree t = NilT 
            | Node t (Tree t) (Tree t)
            deriving (Eq, Show)

depth :: Tree t -> Int
depth NilT = 0
depth (Node a b c) = max (depth b) (depth c) + 1

collapse :: Tree t -> [t]
collapse NilT = []
collapse (Node a b c) = [a] ++ collapse b ++ collapse c

-- mapTree :: (t -> u) -> Tree t -> Tree u
