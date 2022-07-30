-- TODO: map (\x -> x*2) [1..10]
-- TODO: map ((\x -> \y -> x + y*2) 5) 6
-- TODO: map (\x -> \y -> x+y*2) 5 in g 6

-- ? Função de composição (f.g) x

-- fill :: String -> [String]
-- --fill s = splitLines (splitWords s)
-- fill s = splitLines.splitWords s

-- type Word = String
-- type LIne = String

-- splitWords :: String -> [Word]
-- splitLines :: [Word] -> [Line]

-- ! Exercício

inv :: (t -> u -> v) -> u -> t -> v
inv f x y = f y x

-- inv div 2 10 -> dividir 10 por 2
-- * map (\x -> div x 100) [1000,1100..2000] mesmo que map (\x -> div)

-- ! Exercício 2
-- Defina uma função que insira um elemento em uma lista ordeada, na posição correta, mantendo a lista ordenada

insere :: Ord t => t -> [t] -> [t]
insere n [] = [n]
insere n (a:as)
    |(n>a) = a : insere n as
    |otherwise = n : (a:as)

-- ! Exercício 3

insSort :: Ord t => [t] -> [t]
insSort [] = []
insSort (a:as) = insere a (insSort as)