data Cmd = Cursor Int
           | Backspace Int
           | Delete Int
           | Insert String
           deriving (Read)

testeString :: String
testeString = "String de Teste"

editText :: String -> [Cmd] -> String
editText a [] = a
editText a cmd = _editText (a,0) cmd

_editText :: (String,Int) -> [Cmd] -> String
_editText a [] = fst a 
_editText (s, n) (Cursor c :cs) = _editText (s, n + c) cs
_editText (s, n) (Backspace c :cs) = _editText ((take (n - c) s) ++ (drop n s), n-c) cs
_editText (s, n) (Delete c :cs) = _editText ((take (n) s) ++ (drop (n + c) s), n) cs
_editText (s, n) (Insert c :cs) = _editText ((take (n) s) ++ c ++ (drop (n) s), n) cs

main = do
       a <- getLine
       b <- getLine
       let result = editText a (read b)
       print result