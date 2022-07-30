type Pessoa = String
type Livro = String
type BancoDados = [(Pessoa,Livro)]

baseExemplo :: BancoDados
baseExemplo = [("Sergio","O Senhor dos Aneis"),
                ("Andre","Duna"),
                ("Fernando","Jonathan Strange & Mr.Norrell"),
                ("Fernando","A Game of Thrones")]
-- livros emprestados

livros :: BancoDados -> Pessoa -> [Livro]
livros bs p = [livro | (pessoa,livro) <- bs, isPessoa pessoa p]

emprestimos :: BancoDados -> Livro -> [Livro]
emprestimos bs l = [pessoa | (pessoa,livro) <- bs, isLivro livro l]

isPessoa :: Pessoa -> Pessoa -> Bool
isPessoa p1 p2
    | (p1 == p2) = True
    | otherwise = False

isLivro :: Livro -> Livro -> Bool
isLivro l1 l2
    | (l1 == l2) = True
    | otherwise = False

emprestado :: BancoDados -> Livro -> Bool
emprestado bd livro = (emprestimos bd livro /= [])

qtdEmprestado :: BancoDados -> Pessoa -> Int
qtdEmprestado bd pessoa = length (livros bd pessoa)

emprestar :: BancoDados -> Pessoa -> Livro -> BancoDados
emprestar bd pessoa livro = (pessoa,livro) : bd
-- ! emprestar bd pessoa livro = bd ++ [(pessoa,livro)]

devolver :: BancoDados -> Pessoa -> Livro -> BancoDados
devolver bd pessoa livro = [(p1,p2) | (p1,p2) <- bd, (p1,p2) /= (pessoa,livro)]