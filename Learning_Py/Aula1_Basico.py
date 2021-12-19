#Temos o comando print
"""""
print('Helllo World!')
print('Ele', 'separa', 'automaticamente.')
print('Podemos', 'usar', 'um', 'separador.', sep='-', end='')  #Usando o end, ele diz oque colocar no final da string
print(' Dessa forma')
"""

#Usando isso para um CPF:
""""
print('824', '176', '070', sep='.', end='')
print('-18')
"""

#Tipos de Dados
"""
print("TIPOS DE DADOS")
print(type('Vai devolver o tipo desse valor (str)'))
print(10,type(10))
print(30.30,type(30.30))
print(3==3,type(3==3))

#Convertendo Valoroes
print("CONVERTENDO VALORES")
print('10', type('10'), type(int('10')))  #É possível converter uma str '10' em um inteiro/float
"""

#Operadores
"""
print('Além dos já Sabidos temos:')
print("// -> Divisão inteira", "** -> Exponenciação", sep='\n')
print('É possíve multiplicar uma str várias', 5*'vezes ')
print('O sinal de + pode ser' + ' usado para concatenar strings')
"""
#Usando Formatação de Strings:
nome = 'Matheus'
idade = 20; peso = 70; altura = 1.70; 
curso = 'Eng. da Computação'
imc = peso/(altura**2)

print(f'{nome} tem {idade} anos de idade e cursa {curso} e tem um IMC de {imc:.2f}')  #Usa-se f antes da string
print('{} tem {} anos de idade e cursa {} e tem um IMC de {:.2f}'.format(nome , idade, curso, imc))
print('{2} tem {3} anos de idade e cursa {0} e tem um IMC de {1:.2f}'.format(nome , idade, curso, imc)) #indicando as posições
