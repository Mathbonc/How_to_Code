dna2 :: [String] -> [String] -> [Int]
dna2 a b = _dna2 a b (0,0,0)

_dna2 :: [String] -> [String] -> (Int,Int,Int) -> [Int]
_dna2 [] _ (x,y,z) = [x, y, z]
_dna2 _ [] (x,y,z) = [x, y, z]
_dna2 (a:as) (b:bs) (x,y,z)
    |(i >= 0.1 && i <= 0.3) = _dna2 as bs (x+1,y,z)
    |(i >= 0.4 && i <= 0.7) = _dna2 as bs (x,y+1,z)
    |(i >= 0.8) = _dna2 as bs  (x,y,z+1)
    |otherwise = _dna2 as bs (x,y,z)
    where i = getSim a b

getSim :: String -> String -> Float
getSim a b
    |(length a > length b) = ((compareStr a b)/fromIntegral(length a)::Float) 
    |otherwise = ((compareStr a b)/fromIntegral(length b)::Float) 

compareStr :: String -> String -> Float
compareStr [] _ = 0.0
compareStr _ [] = 0.0
compareStr (a:as) (b:bs)
    |(a == b) = compareStr as bs + 1.0
    |otherwise = compareStr as bs

main = do
  firstExtract <- words <$> getLine                       -- equivalente a (read firstExtract :: [String])
  secondExtract <- words <$> getLine
  let result = dna2 firstExtract secondExtract
  print result