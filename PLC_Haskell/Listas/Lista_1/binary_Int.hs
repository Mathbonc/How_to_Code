btoi :: String -> Int
btoi a = aux_btoi (reverse a) 0

aux_btoi :: String -> Int -> Int
aux_btoi [] _ = 0
aux_btoi (x:xs) b | (x == '1') = aux_btoi xs (b+1) + 2^b
                  | otherwise = aux_btoi xs (b+1)

main = do
    s <- getLine
    let result = btoi s
    print result