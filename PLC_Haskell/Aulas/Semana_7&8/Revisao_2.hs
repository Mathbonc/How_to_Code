data Time = Australia | Dinamarca | Franca | Peru 
          | Argentina | Croacia | Islandia | Nigeria
          deriving(Eq)

type Jogo = (Time, Int, Time, Int)

jogos1 :: [Jogo]
jogos1 = [(Australia, 1, Dinamarca, 3), (Franca, 2, Peru, 0), 
          (Australia, 0, Franca, 2),(Dinamarca, 0, Peru, 0), 
          (Dinamarca, 0, Franca, 1), (Australia, 0, Peru, 0), 
          (Argentina, 1, Croacia, 0), (Islandia, 0, Nigeria, 1), 
          (Argentina, 1, Islandia, 0), (Argentina, 1, Nigeria, 1), 
          (Croacia, 0, Islandia, 0), (Croacia, 1, Nigeria, 2)]

-- ! a)

gols :: Time -> [Jogo] -> Int
gols a [] = 0
gols a ((t1,x,t2,y):bs)
    |(a == t1) = gols a (bs) + x
    |(a == t2) = gols a (bs) + y
    |otherwise = gols a (bs)

-- ! b)

saldo :: Time -> [Jogo] -> Int
saldo a [] = 0
saldo a ((t1,x,t2,y):bs)
    |(a == t1) = saldo a (bs) + x - y
    |(a == t2) = saldo a (bs) + y - x
    |otherwise = saldo a (bs)

-- ! c)

pontos :: Time -> [Jogo] -> Int
pontos a [] = 0
pontos a ((t1,x,t2,y):bs)
    |(a == t1  && x > y) = pontos a (bs) + 3
    |(a == t2  && y > x) = pontos a (bs) + 3 
    |((a == t1 || a == t2) && x == y) = pontos a (bs) + 1
    |otherwise = pontos a (bs)

-- ! d)

data Grupo = Grupo NomeDeGrupo Time Time Time Time
data NomeDeGrupo = A | B | C | D | E | F | G | H deriving(Eq)

-- ! e)

classificados :: Grupo -> [Jogo] -> (Time, Time)
classificados (Grupo n t1 t2 t3 t4) jogos = (time r1, time r2)
    where
        time (t,_,_,_) = t
        getData time = (time, pontos (time) (jogos), saldo (time) (jogos), gols (time) (jogos))
        ordena [] = [] -- Quick Sort
        ordena (time1:times) = ordena [x | x <- times, x `lt` time1] ++ [time1] ++ 
                               ordena [y | y <- times, y `gte` time1]
        lt (t1,ponto1,saldo1,gols1) (t2,ponto2,saldo2,gols2)
            | ponto1 < ponto2 = True
            | ponto1 > ponto2 = False
            | saldo1 < saldo2 = True
            | saldo1 > saldo2 = False
            | gols1 < gols2 = True
            | gols1 >= gols2 = False
        gte dado1 dado2 = not (dado1 `lt` dado2)
        (r1:r2:resto) = ordena (map getData [t1,t2,t3,t4])