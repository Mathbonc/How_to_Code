import Recursao_a2 

addSpace :: Int -> String
addSpace 0 = ""
addSpace x = addSpace (x-1) ++ " "

toRight :: Int -> String -> String
toRight x string = addSpace x ++ string

printWeeks :: Int -> String
printWeeks 0 = toRight 3 "0" ++ toRight 9 (show (vendas 0)) ++ "\n" 
printWeeks n = printWeeks (n-1) ++ printWeek n

printWeek :: Int -> String
printWeek x = toRight 3 (show x) ++ toRight 9 (show (vendas x)) ++ "\n"

printTotal :: Int -> String
printTotal n = "Total" ++ toRight 7 (show(totalVendas n)) ++ "\n"

printMean :: Int -> String
printMean n = "Media" ++ toRight 7 (show((fromIntegral(totalVendas n)) / (fromIntegral n))) ++ "\n"

cabecalho :: String
cabecalho = "Semana" ++ toRight 5 "Vendas" ++ "\n"

printTable :: Int -> String
printTable n = cabecalho ++ printWeeks n ++ printTotal n ++ printMean n