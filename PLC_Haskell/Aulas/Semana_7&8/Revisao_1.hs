type Chave = [(Char, Char)]

rot13parcial :: Chave
rot13parcial = [('a','n'),('b','o'),('c','p'),('d','q'),('e','r'),('f','s'),
                ('g','t'),('h','u'),('i','v'),('j','w'),('k','x'),('l','y'), ('m','z')]

cipher :: Chave -> String -> String
cipher _ [] = []
cipher a (b:bs) = check a b : cipher a bs

check :: Chave -> Char -> Char
check [] b = b
check (a:as) b 
    |(fst(a)==b) = snd(a)
    |otherwise = check as b

-- ! Q2

inverteChave :: Chave -> Chave
inverteChave [] = []
inverteChave (a:as) = (snd(a),fst(a)) : inverteChave as

-- ! Q3

type FuncaoChave = (Char -> Char)

trocaSoLetraL :: FuncaoChave
trocaSoLetraL 'l' = 'b'
trocaSoLetraL 'e' = 'a'
trocaSoLetraL c = c

cipherf :: FuncaoChave -> String -> String
cipherf _ [] = []
cipherf f (a:as) = trocaSoLetraL a : cipherf f as

-- ! Q4

chaveToFuncaoChave :: Chave -> FuncaoChave
chaveToFuncaoChave key = \ch -> check key ch

-- ! Q5

data KeyTree = Node Char Char KeyTree KeyTree | Empty

chaveParcial :: KeyTree
chaveParcial = Node 'h' 'u' (Node 'c' 'p' (Node 'b' 'o' (Node 'a' 'n' Empty Empty) Empty) (Node 'e' 'r' Empty Empty)) (Node 'l' 'y' Empty (Node 'm' 'z' Empty Empty))

cipherT :: KeyTree -> String -> String
cipherT _ [] = []
cipherT t (a:as) = bst t a : cipherT t as

bst :: KeyTree -> Char -> Char
bst Empty a = a 
bst (Node c1 c2 tree1 tree2) a
    |(a == c1) = c2
    |(a > c1) = bst tree2 a
    |otherwise = bst tree1 a
