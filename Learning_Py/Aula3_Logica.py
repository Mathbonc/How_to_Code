usario = input('Digite um Nome: ')
qntd_caractere = len(usario)

if (qntd_caractere>20):
    print('Muitos Caracteres!')
elif (qntd_caractere==13):
    print('comunista')
else:
    print('Boa Mlk!')

Num1 = input('Agora, digite dois numeros ')
Num2 = input('')

try:
    Num1 = int(Num1)
    Num2 = int(Num2)

    print(Num1+Num2)
except:  #Esse código tenta executar uma parte, mas caso dê erro, ele parte pro "except"
    print('Digite um NUMERO, oras...')

#Num IF, eu poderia usar um "pass" ou "..." caso não tenha nada dentro dele