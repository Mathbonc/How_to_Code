twice :: (t -> t) -> (t -> t)
twice f = f . f

-- ? (succ.succ) 12 == (twice succ) 12

-- ! Expressões que definem funções (NOTAÇÃO LAMBDA)

-- * addNum :: Int -> (Int -> Int)
-- * addNum n = h
-- *     where
-- *    h m = n + m

addNum :: Int -> (Int -> Int) -- Devolve uma função
addNum n = (\m -> n+m)

-- ? Essa notação indica os parâmetros a serem usados numa expressão, ex: \x y -> g (f x) (f y)

sqr2 = \x -> (x*x)
concat2 = \l1 l2 -> (l1 ++ l2)