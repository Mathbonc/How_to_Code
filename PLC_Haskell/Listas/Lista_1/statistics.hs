minMaxCartao :: String -> (Double, Double)
minMaxCartao a = (mini,maxi)
    where
    mini = minimum (listOnlyValues (convertToList a))
    maxi = maximum (listOnlyValues (convertToList a))
    
-- ! OK ! --
convertToList :: String -> [String]
convertToList a = words (_convertToList a)


_convertToList :: String -> String
_convertToList [] = []
_convertToList (x:xs) 
        | (x == ';') = ' ' : _convertToList xs
        | otherwise = x : _convertToList xs

-- ! OK ! --
listOnlyValues :: [String] -> [Double]
listOnlyValues [] = []
listOnlyValues (x:y:z:w:xs) = read w : listOnlyValues xs

main = do
    a <- getLine
    let result = minMaxCartao a
    print result