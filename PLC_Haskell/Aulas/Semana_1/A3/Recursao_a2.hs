module Recursao_a2 where

vendas :: Int -> Int
vendas 0 = 10
vendas 1 = 13
vendas 2 = 13
vendas 3 = 40
vendas 4 = 50
vendas n = 0

{-
totalVendas :: Int -> Int
totalVendas n | n==0 = vendas 0
              | otherwise = totalVendas (n-1) + vendas n
-}

 --Escreveno de outra forma

totalVendas :: Int -> Int
totalVendas 0 = vendas 0
totalVendas n = totalVendas(n-1) + vendas n



--Exercício 1
vendasIguais :: Int -> Int -> Int
vendasIguais s n | (n==0) && (vendas 0 == s) = 1  
                 | (vendas n == s) = vendasIguais s (n-1) + 1
                 | (vendas n /= s) = vendasIguais s (n-1)
