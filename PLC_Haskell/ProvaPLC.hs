-- Aluno: Matheus Júlio Boncsidai de Oliveira
-- Login: mjbo

-- !QUESTÃO 1 --

type Urna = (Int,[(String,Int)])

teste :: [Urna]
teste = [(99,[("Candi1",89),("Candi2",93),("Candi3",99),("Candi4",91)])
        ,(98,[("Candi1",85),("Candi2",98),("Candi3",89),("Candi4",90)])
        ,(97,[("Candi1",97),("Candi2",93),("Candi3",99),("Candi4",92)])]

totalize :: [Urna] -> [(String,Int)]
totalize [] = []
totalize (a:as) = colapseTupla ((snd a) ++ totalize as)

-- !QUESTÃO 2 --

ordena :: [(String,Int)] -> [(String,Int)]
ordena [] = []
ordena [a] = [a]
ordena (a:as) = ordena(qSort_greater a as) ++ [a] ++ ordena (qSort_lesser a as)

qSort_lesser :: (String,Int) -> [(String,Int)] -> [(String,Int)]
qSort_lesser n [] = []
qSort_lesser (cand1,n) ((cand2,x):xs) | (x<n) = qSort_lesser (cand1,n) (xs) ++ [(cand2,x)]
                                      | otherwise = qSort_lesser (cand1,n) (xs)

qSort_greater :: (String,Int) -> [(String,Int)] -> [(String,Int)]
qSort_greater n [] = []
qSort_greater (cand1,n) ((cand2,x):xs) | (x>=n) = qSort_greater (cand1,n) (xs) ++ [(cand2,x)]
                                       | otherwise = qSort_greater (cand1,n) (xs)

-- !QUESTÃO 3 --

teste2 :: String
teste2 = "este texto tem um teste"

frequencia :: String -> [(String,Int)]
frequencia a = dropTupas(colapseTupla (gerarTuplas a))

gerarTuplas :: String -> [(String,Int)]
gerarTuplas (a:b:[]) = [([a] ++ [b],1)]
gerarTuplas (a:b:as) = [([a] ++ [b],1)] ++ gerarTuplas (b:as)

colapseTupla :: [(String,Int)] -> [(String,Int)]
colapseTupla [] = []
colapseTupla ((str1,a):as) = colapseTupla (myDropWhile str1 as) ++ [getTotal (str1,0) ((str1,a):as)]

getTotal :: (String,Int) -> [(String,Int)] -> (String,Int)
getTotal a [] = a
getTotal a (b:bs)
    |(fst a == fst b) = getTotal (fst a,snd a + snd b) bs
    |otherwise = getTotal a bs

myDropWhile :: String -> [(String,Int)] -> [(String,Int)]
myDropWhile _ [] = []
myDropWhile a ((str2,b):bs)
    |(a == str2) = myDropWhile a bs
    |otherwise = [(str2,b)] ++ myDropWhile a bs

dropTupas :: [(String,Int)] -> [(String,Int)]
dropTupas [] = []
dropTupas (a:as)
    |(snd a < 2) = dropTupas as
    |otherwise = [a] ++ dropTupas as

-- !QUESTÃO 4 --

teste3 :: String
teste3 = "76 6xto 6m um 6s6"

data Chaves = No Int String Chaves Chaves | Folha

chaveTeste :: Chaves
chaveTeste = No 6 "te" (No 4 " t" Folha (No 5 "m " Folha Folha))
                       (No 8 "st" (No 7 "es" Folha Folha)  Folha)

descompacta :: Chaves -> String -> String
descompacta a b = _descompacta (collapseTree a) b

_descompacta :: [(Int,String)] -> String -> String
_descompacta _ [] = []
_descompacta a (b:bs) = translate a b ++ _descompacta a bs

translate  :: [(Int,String)] -> Char-> String
translate [] b = [b]
translate (a:as) b 
    |(show (fst a) == [b]) = snd a
    |otherwise = translate as b

collapseTree :: Chaves -> [(Int,String)]
collapseTree Folha = []
collapseTree (No a b c d) = collapseTree c ++ [(a,b)]  ++ collapseTree d

