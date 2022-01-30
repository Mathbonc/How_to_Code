from ast import While
from itertools import count
from re import A
from tkinter import E
from xmlrpc.client import boolean


Acertos = 0
Erros = 0
titulo = "Bem vindo ao jogo da forca em Python!"


palavra = "yamete"
forca = []
digitadas = []

for m in palavra:
    forca.append("_")

print(f'{titulo:#^51}', end='\n\n')

while (Acertos<len(palavra)) and Erros<6: 

    for elem in forca:
        print(f"{elem}", end=' ') 

    letra = input('\nDigite uma letra: ')

    if letra.islower() and letra.isalpha():
        if (palavra.__contains__(letra) and not digitadas.__contains__(letra)):
            digitadas.append(letra)
            for m in range(palavra.count(letra)):
                forca[palavra.find(letra)]=letra
                palavra = palavra.replace(letra,"_",1)
                Acertos += 1
        elif (digitadas.__contains__(letra)):
            print("Essa letra já foi adivinhada.")
        else:
            digitadas.append(letra)
            print("Não foi dessa vez :(")
            Erros += 1
    else:
        print("A letra precisa ser minúscula.")
else:
    if Erros == 6:
        print("Fim de jogo, infelizmente você não conseguiu...")
    else:
        print("Parabéns! Você acertou todas as letras!")

