logMes :: String -> String -> Double 
logMes a b = foldl (+) 0 (sumMonth a (listOnlyMonths (convertToList b)) (listOnlyValues (convertToList b)))
-- a: month 
-- b: string

sumMonth :: String -> [String] -> [Double] -> [Double]
sumMonth a [] [] = []
sumMonth a (month:xs) (value:ys) 
    | (a == month) = value : (sumMonth a xs ys)
    | otherwise = (sumMonth a xs ys)
    
-- ! Convertion ! --
convertToList :: String -> [String]
convertToList a = words (_convertToList a)


_convertToList :: String -> String
_convertToList [] = []
_convertToList (x:xs) 
        | (x == ';') = ' ' : _convertToList xs
        | otherwise = x : _convertToList xs

listOnlyValues :: [String] -> [Double]
listOnlyValues [] = []
listOnlyValues (x:y:z:w:xs) = read w : listOnlyValues xs

listOnlyMonths :: [String] -> [String]
listOnlyMonths [] = []
listOnlyMonths (x:y:z:w:xs) = y : listOnlyMonths xs

-- ! Main ! --
main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result