sumSquare x y :: Int -> Int -> Int

sumSquare = sqX + sqY
where sqX = x * x
      sqY = y * y

-- Forma 2

{-
sumSquare x y = sq x + sq y
    where sq z = z * z
-}

--Forma 3

{-
sumSquare x y = let sqX = x * x
                    sqY = y * y
                in sqX + sqY
-}