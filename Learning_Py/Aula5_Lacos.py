x= 0;
while(x<10):
    x+=1 
    print(x)
else:
    print("Cheguei no final da string.", end="\n\n")

##########
##########

string = 'Amogus'
novaString = ''
stringSize = len(string)
contador = 0

while contador < stringSize:
    print(f"O caractere: '{string[contador]}' foi adicionado a nova string.")
    novaString += string[contador]
    print(f"Nova string:  '{novaString}'")
    contador+=1
    
##########
##########

for letter in string:
    print(letter) 
print('\n')

print('Função range(start, stop, step)')
for n in range(50, 33, -1):
    print(n, end=' ')
print('\n')

print('Listas:')
lista = ['A','b', 10.5, 20, 'Yamete']

print(f"Tamanho da lista: {lista.__len__()}")

for m in range(len(lista)):
    print(lista[m])

print('Usando range para criar uma lista:')
lista2 = list(range(0,100,3))

for m in lista2:
    print(m, end=' ')