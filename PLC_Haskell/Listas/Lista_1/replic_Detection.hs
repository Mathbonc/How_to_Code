isReplica :: String -> Int -> Char -> Bool
isReplica a b c | ((aux_isReplica b c) == a) = True
                | otherwise = False

aux_isReplica :: Int -> Char -> String
aux_isReplica 0 c = []
aux_isReplica b c = c : aux_isReplica (b-1) c

main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b) c
    print result