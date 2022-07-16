type Translation = (Char,Char)

decEnigma :: String -> [Translation] -> String
decEnigma [] b = []
decEnigma (x:xs) b =  (convertLetter x b) : decEnigma xs b

convertLetter :: Char -> [Translation] -> Char
convertLetter c (b:bs)
    | (c == (fst b)) = snd b
    | otherwise = convertLetter c bs 

-- ! Main ! -- 
main = do
    a <- getLine
    b <- getLine
    let result = decEnigma a (read b)
    print result