sumTo :: Int -> Int
sumTo 1 = 1
sumTo n = sumTo (n-1) + n

main :: IO()
main = interact $ show . sumTo . read