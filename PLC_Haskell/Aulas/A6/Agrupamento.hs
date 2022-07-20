agrupar :: [t] -> [(t,Int)]
agrupar [] = 
agrupar (a:as) = (a, contar as a) ++ agrupar as 

contar :: [t] -> t -> Int
contar [] b = 0
contar (a:as) b 
    |(a == b) = contar as b + 1
    |otherwise = contar as b