data Shape = Circle Float 
            | Rectangle Float Float

area :: Shape -> Float
area (Circle r) = pi*r*r
area (Rectangle b h) = b*h

-- ! Tipos Recursivos
data Expr = Lit Int 
            | Add Expr Expr 
            | Sub Expr Expr

eval :: Expr -> Int
eval (Lit n) = n
eval (Add e1 e2) = (eval e1) + (eval e2)
eval (Sub e1 e2) = (eval e1) - (eval e2)

-- ! Tipos Polimórficos
data Pairs t = Pair t t
-- * Pair 6 8 :: Pairs Int
-- * Pair True True :: Pairs Bool
-- * Pair [] [1,3] :: Pair [Int]

-- ! Listas e Árvores
data List t = Nil | Cons t (List t) -- ? Nil == Null

data Tree t = NilT -- ? NilT = Nil Tree
            | Node t (Tree t) (Tree t)
            deriving (Eq,Show) -- ? Indica que tudo que eu posso fazer com (Eq,Show)
                               -- ? eu posso fazer com Tree