-- TODO: Data Structs

intPair :: (Int,Int)
intPair = (33,43)

addPair :: (Int,Int) -> Int
addPair (x,y) = x+y

shift :: ((Int,Int),Int) -> (Int,(Int,Int))
shift ((x,y),z) = (x,(y,z))

-- TODO: typedef

type Name = String
type Age = Int
type Phone = [Int]
type Person = (Name,Age,Phone)

name :: Person -> Name
name (p,o,g) = p

-- TODO: EQ. Segundo Grau

-- * Funções auxilires
oneRoot :: Float -> Float -> Float -> Float
oneRoot a b c = -b/(2.0*a)

twoRoots :: Float -> Float -> Float -> (Float,Float)
twoRoots a b c = (d-e,d+e)
    where 
    d = -b/(2.0*a)
    e = sqrt(b^2 - 4.0*a*c)/(2.0 * a)

-- * Função Principal
roots :: (Float, Float, Float) -> String
roots (a, b, c) 
    | (b^2 == 4.0*a*c) = show (oneRoot a b c)
    | (b^2 > 4.0*a*c) = show f ++ " " ++ show s
    | otherwise = "no roots"
    where (f,s) = twoRoots a b c

-- ? Poderíamos chamar a função duas vezes para f e s, usando as funções "fst" e "snd" para pegarmos a primeira e segunda posições da tupla, respectivamente

-- TODO: EXERCÍCIO 1

type Ponto = (Float,Float)
type Reta = (Ponto,Ponto)

pontoY :: Float -> Reta -> Float
pontoY x ((x1,y1),(x2,y2)) = ((((y2-y1)*(x-x1))/(x2-x1)) + y1)