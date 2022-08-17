-- ? Funções de alta ordem recebem funções como parâmetros

applyBinOper::(t -> t -> t) -> t -> t -> t
applyBinOper f x y = f x y

-- ? Funções de mapeamento transformam uma lista em outra, baseada numa função

sqrList :: [Int] -> [Int]
sqrList [] = []
sqrList (a:x)= (a*a) : sqrList x

-- ! Função fold
fold :: (t -> t -> t) -> [t] -> t
fold f [a] = a
fold f (a:as) = f a (fold f as)

-- ! Exercício
isCrescent :: (Int -> Int) -> Int -> Bool
isCrescent f 0 = True
isCrescent f n
    | f n >= f (n-1) = isCrescent f (n-1) -- f n -> significar "função no ponto n"
    | otherwise = False

-- TODO: Filtro

myFilter :: (t->Bool) -> [t] -> [t]
myFilter p [] = []   
myFilter p (a:as)
    | (p a) = a : myFilter p as -- Se a estiver na condição do filtro "p", ele é mantido na lista
    | otherwise = myFilter p as -- Caso contrário, a não é adicionado à nova lista e a filtragem continua

-- TODO: Exercícios

myTakeWhile :: (t -> Bool) -> [t] -> [t]
myTakeWhile p [] = []
myTakeWhile p (a:as)
    |(p a) = a : myTakeWhile p as
    |otherwise = []

myDropWhile :: (t -> Bool) -> [t] -> [t]
myDropWhile p [] = []
myDropWhile p (a:as)
    |(p a) = myDropWhile p as
    |otherwise = a : as