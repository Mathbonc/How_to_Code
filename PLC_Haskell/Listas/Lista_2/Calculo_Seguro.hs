import Prelude hiding (Maybe (..))

data Maybe a = Just a |
               Nothing
               deriving(Show)

main = do
       a <- getLine
       safeCalc a

safeCalc :: String -> IO ()
safeCalc a = putStr (show (result a))

result :: String -> Maybe  Int
result [] = Nothing
result a = _result (read (takeWhile (<'a') a)::Int) (take 3 (drop (length (takeWhile (<'a') a)) a)) (read (reverse((takeWhile (<'a') (reverse a))))::Int)

_result :: Int -> String -> Int -> Maybe Int
_result a "sum" b = Just (a + b)
_result a "sub" b = Just (a - b)
_result a "mul" b = Just (a *b )
_result 0 "div" b = Nothing
_result a "div" b = Just (a `div` b)
_result _ _ _ = Nothing

teste :: String -> Int
teste a = read ([x | x <- a, x < 'a'])

meu :: String
meu = "7sum4"