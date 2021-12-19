nome = 'Formatação Usando Strings'
print(f'\n {nome:#^36}')
print(f'{"A esquerda": >20}')
print(f'{"A direita":-<20}', end = "\n\n\n")

nome = 'Matheus'
print(f'{"Iterando as strings":#^31}')
print(f"{'[0123456]': <10} -> Positivos")
print(f'{nome: ^9}')
print(f"{'[7654321]': <10} -> Negativos", end = '\n\n')

print('É possível escrever até um certo ponto:')
print(f"{'[0123456]': <10}")
print(f'{nome[:-1]: ^9}')
print(f"{'[7654321]': <10}", end = '\n')
print('Ou a partir de um ponto:')
print(f"{'[0123456]': <10}")
print(f'{nome[2:]: >8}')
print(f"{'[7654321]': <10}", end = '\n')
print('Ou até um intervalo:')
print(f"{'[0123456]': <10}")
print(f'{nome[2:5]: ^9}')
print(f"{'[7654321]': <10}", end = '\n')
