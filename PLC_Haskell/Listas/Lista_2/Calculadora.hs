type Comando = String
type Valor = Int

invertList :: [(Comando, Valor)] -> [(Comando, Valor)]
invertList [] = []
invertList (a:as) = invertList as ++ [a]

executa :: [(Comando,Valor)] -> Int
executa a = _executa (invertList a)

_executa :: [(Comando,Valor)] -> Int
_executa (a:[])
    |(fst a == "Soma") = snd a
    |(fst a == "Subtrai") = -(snd a)
    |(fst a == "Multiplica") = 0
    |(fst a == "Divide") = -666
_executa (a:as)
    |(fst a == "Soma") = _executa as + snd a 
    |(fst a == "Subtrai") = _executa as - snd a 
    |(fst a == "Multiplica") = _executa as * snd a
    |((fst a == "Divide") && (snd a == 0)) = -666
    |(fst a == "Divide") = _executa as `div` snd a

main = do
    a <- getLine
    let result = executa (read a)
    print result
