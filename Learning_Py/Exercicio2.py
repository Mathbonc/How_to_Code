import re
 
def is_float(val):
    if isinstance(val, float): return True
    if re.search(r'^\-{,1}[0-9]+\.{1}[0-9]+$', val): return True
 
    return False
 
def is_int(val):
    if isinstance(val, int): return True
    if re.search(r'^\-{,1}[0-9]+$', val): return True
 
    return False
 
def is_number(val):
    return is_int(val) or is_float(val)
###################################################################
Num = input('Digite um numero: ')

if(is_int(Num)):
    Num = int(Num)
    if(Num%2 == 0):
        print('Esse número e par.')
    else:
        print('Esse numero nao e par.')
else:
    print('Isso nao e um numero inteiro.')
###################################################################
Hora = input('Digite uma hora: ')

if(is_number(Hora)):
    if(is_float(Hora)):
        Hora = float(Hora)
    elif(is_int(Hora)):
        Hora = int(Hora)
    
    if(Hora>=0 and Hora<=11):
        print('Bom dia!')
    elif(Hora>=12 and Hora <=17):
        print('Boa tarde!')
    elif(Hora>=18 and Hora<=23):
        print('Boa noite!')
    else:
        print(f'{Hora} Não e um horario valido.')
else:
    print('Isso nao e um digito valido.')
###################################################################
Nome = input('Digite um nome: ')
qntd_Caractere = len(Nome)

if not(Nome.isnumeric()):
    if(qntd_Caractere<=4):
        print('Seu nome e muito curto!')
    elif(qntd_Caractere>4 and qntd_Caractere<=6):
        print('Seu nome e mediano.')
    else:
        print('Seu nome e gigantesco!')
else:
    print("Que nome peculiar!")
        