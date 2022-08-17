agrupar :: Eq t => [[t]] -> [(t,Int)]
agrupar a = contar (stringao a)

stringao :: Eq t => [[t]] -> [t]
stringao [] = []
stringao (a:as) = a ++ (stringao as)

contar :: Eq t => [t] -> [(t,Int)]
contar [] = []
contar (a:as) = (a, _contar a as + 1) : (contar [x | x <- as, x/=a])

_contar :: Eq t => t -> [t] -> Int
_contar _ [] = 0
_contar b (a:as)
    |(b==a) = _contar b as + 1
    |otherwise = _contar b as

