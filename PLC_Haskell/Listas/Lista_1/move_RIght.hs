addEspacos :: Int -> String
addEspacos 0 = ""
addEspacos x = addEspacos (x-1) ++ " "

paraDireita :: Int -> String -> String
paraDireita x string = addEspacos x ++ string

parseInput str = let [n, s] = words str
                 in (read n, s)
main :: IO()
main = interact $ uncurry paraDireita . parseInput