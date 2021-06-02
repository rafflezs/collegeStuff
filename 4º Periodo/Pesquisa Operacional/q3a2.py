from IPython.display import display
import numpy as np

c = np.array([-2,-1,0,0,0])
A = np.array([[1,2,1,0,0],[1,0,0,-1,0],[0,1,0,0,-1]])
b = np.array([10,4,3])
display(A)
m = A.shape[0]
n = A.shape[1]


XB = np.array([2,3,4])
XN = np.array([0,1])
B = A[:,XB]
N = A[:,XN]
cB = c[XB]
cN = c[XN]
print('Variáveis básicas:',XB)
print('Variáveis não-básicas:',XN)
print('Matriz básica:')
display(B)
print('Matriz não-básica:')
display(N)
print('Custos básicos:',cB)
print('Custos não-básicos:',cN)

B_inv = np.linalg.inv(B)
print ('Matriz inversa de B:')
display(B_inv)

xb_hat = B_inv @ b
xn_hat = np.zeros(n-m)
x_hat = np.zeros(n)
for i in range(n): 
    if i in XN: x_hat[i] = 0
    else: x_hat[i] = xb_hat[np.where(XB == i)[0][0]]
print (xb_hat)
print (xn_hat)
print ('X =',x_hat)

lbda = cB @ B_inv
print('Vetor multiplicador simplex:',lbda)

cN_hat = cN - lbda @ N
print('Custos Reduzidos:', cN_hat)

k = XN[np.argmin(cN_hat)]
print('A variável do índice',k,'vai entrar na base')

if np.where(cN_hat < 0)[0].size > 0:
    print('Iterando')
else: print('A solução atual é ótima!')

y = B_inv @ A[:,k]
print ('Direção simplex', y)

if np.where(y > 0)[0].size > 0: 
    print ('Iterando ')
else: 
    print('Problema não possui solução finita. ')

eps = np.inf
l = -1
for i in range(m):
    if (y[i]>0): 
        aux = xb_hat[i]/y[i]
        if aux < eps:
            eps = aux
            l = XB[i]
print ('Tamanho do passo epsilon: ',eps)
print('A variável do índice',l,'vai sair da base')

print('Portanto, teremos mais uma iteração!')
print('A variável do índice',k,'entra na base')
print('A variável do índice',l,'sai da base')

XB = np.array([1,3,4])
XN = np.array([0,2])
B = A[:,XB]
N = A[:,XN]
cB = c[XB]
cN = c[XN]
print('Variáveis básicas:',XB)
print('Variáveis não-básicas:',XN)
print('Matriz básica:')
display(B)
print('Matriz não-básica:')
display(N)
print('Custos básicos:',cB)
print('Custos não-básicos:',cN)

B_inv = np.linalg.inv(B)
print ('Matriz inversa de B:')
display(B_inv)

xb_hat = B_inv @ b
xn_hat = np.zeros(n-m)
x_hat = np.zeros(n)
for i in range(n): 
    if i in XN: x_hat[i] = 0
    else: x_hat[i] = xb_hat[np.where(XB == i)[0][0]]
print (xb_hat)
print (xn_hat)
print ('X =',x_hat)


lbda = cB @ B_inv
print('Vetor multiplicador simplex:',lbda)

cN_hat = cN - lbda @ N
print('Custos Reduzidos:', cN_hat)

k = XN[np.argmin(cN_hat)]
print('A variável do índice',k,'vai entrar na base')

if np.where(cN_hat < 0)[0].size > 0:
    print('Iterando')
else: print('A solução atual é ótima!')

y = B_inv @ A[:,k]
print ('Direção simplex', y)

if np.where(y > 0)[0].size > 0: 
    print ('Iterando ')
else: 
    print('Problema não possui solução finita. ')

eps = np.inf
l = -1
for i in range(m):
    if (y[i]>0): 
        aux = xb_hat[i]/y[i]
        if aux < eps:
            eps = aux
            l = XB[i]
print ('Tamanho do passo epsilon: ',eps)
print('A variável do índice',l,'vai sair da base')

print('Portanto, teremos mais uma iteração!')
print('A variável do índice',k,'entra na base')
print('A variável do índice',l,'sai da base')

## 3a iteração

XB = np.array([1,0,4])
XN = np.array([3,2])
B = A[:,XB]
N = A[:,XN]
cB = c[XB]
cN = c[XN]
print('Variáveis básicas:',XB)
print('Variáveis não-básicas:',XN)
print('Matriz básica:')
display(B)
print('Matriz não-básica:')
display(N)
print('Custos básicos:',cB)
print('Custos não-básicos:',cN)

B_inv = np.linalg.inv(B)
print ('Matriz inversa de B:')
display(B_inv)

xb_hat = B_inv @ b
xn_hat = np.zeros(n-m)
x_hat = np.zeros(n)
for i in range(n): 
    if i in XN: x_hat[i] = 0
    else: x_hat[i] = xb_hat[np.where(XB == i)[0][0]]
print (xb_hat)
print (xn_hat)
print ('X =',x_hat)


lbda = cB @ B_inv
print('Vetor multiplicador simplex:',lbda)

cN_hat = cN - lbda @ N
print('Custos Reduzidos:', cN_hat)

k = XN[np.argmin(cN_hat)]
print('A variável do índice',k,'vai entrar na base')

if np.where(cN_hat < 0)[0].size > 0:
    print('Iterando')
else: print('A solução atual é ótima!')

y = B_inv @ A[:,k]
print ('Direção simplex', y)

if np.where(y > 0)[0].size > 0: 
    print ('Iterando ')
else: 
    print('Problema não possui solução finita. ')

eps = np.inf
l = -1
for i in range(m):
    if (y[i]>0): 
        aux = xb_hat[i]/y[i]
        if aux < eps:
            eps = aux
            l = XB[i]
print ('Tamanho do passo epsilon: ',eps)
print('A variável do índice',l,'vai sair da base')

print('Portanto, teremos mais uma iteração!')
print('A variável do índice',k,'entra na base')
print('A variável do índice',l,'sai da base')

XB = np.array([1,0,3])
XN = np.array([4,2])
B = A[:,XB]
N = A[:,XN]
cB = c[XB]
cN = c[XN]
print('Variáveis básicas:',XB)
print('Variáveis não-básicas:',XN)
print('Matriz básica:')
display(B)
print('Matriz não-básica:')
display(N)
print('Custos básicos:',cB)
print('Custos não-básicos:',cN)

B_inv = np.linalg.inv(B)
print ('Matriz inversa de B:')
display(B_inv)

xb_hat = B_inv @ b
xn_hat = np.zeros(n-m)
x_hat = np.zeros(n)
for i in range(n): 
    if i in XN: x_hat[i] = 0
    else: x_hat[i] = xb_hat[np.where(XB == i)[0][0]]
print (xb_hat)
print (xn_hat)
print ('X =',x_hat)


lbda = cB @ B_inv
print('Vetor multiplicador simplex:',lbda)

cN_hat = cN - lbda @ N
print('Custos Reduzidos:', cN_hat)

k = XN[np.argmin(cN_hat)]
print('A variável do índice',k,'vai entrar na base')

if np.where(cN_hat < 0)[0].size > 0:
    print('Iterando')
else: print('A solução atual é ótima!')

y = B_inv @ A[:,k]
print ('Direção simplex', y)

if np.where(y > 0)[0].size > 0: 
    print ('Iterando ')
else: 
    print('Problema não possui solução finita. ')

eps = np.inf
l = -1
for i in range(m):
    if (y[i]>0): 
        aux = xb_hat[i]/y[i]
        if aux < eps:
            eps = aux
            l = XB[i]
print ('Tamanho do passo epsilon: ',eps)
print('A variável do índice',l,'vai sair da base')

print('Portanto, teremos mais uma iteração!')
print('A variável do índice',k,'entra na base')
print('A variável do índice',l,'sai da base')

XB = np.array([1,0,2])
XN = np.array([4,3])
B = A[:,XB]
N = A[:,XN]
cB = c[XB]
cN = c[XN]
print('Variáveis básicas:',XB)
print('Variáveis não-básicas:',XN)
print('Matriz básica:')
display(B)
print('Matriz não-básica:')
display(N)
print('Custos básicos:',cB)
print('Custos não-básicos:',cN)

B_inv = np.linalg.inv(B)
print ('Matriz inversa de B:')
display(B_inv)

xb_hat = B_inv @ b
xn_hat = np.zeros(n-m)
x_hat = np.zeros(n)
for i in range(n): 
    if i in XN: x_hat[i] = 0
    else: x_hat[i] = xb_hat[np.where(XB == i)[0][0]]
print (xb_hat)
print (xn_hat)
print ('X =',x_hat)


lbda = cB @ B_inv
print('Vetor multiplicador simplex:',lbda)

cN_hat = cN - lbda @ N
print('Custos Reduzidos:', cN_hat)

k = XN[np.argmin(cN_hat)]
print('A variável do índice',k,'vai entrar na base')

if np.where(cN_hat < 0)[0].size > 0:
    print('Iterando')
else: print('A solução atual é ótima!')

y = B_inv @ A[:,k]
print ('Direção simplex', y)

if np.where(y > 0)[0].size > 0: 
    print ('Iterando ')
else: 
    print('Problema não possui solução finita. ')

eps = np.inf
l = -1
for i in range(m):
    if (y[i]>0): 
        aux = xb_hat[i]/y[i]
        if aux < eps:
            eps = aux
            l = XB[i]
print ('Tamanho do passo epsilon: ',eps)
print('A variável do índice',l,'vai sair da base')

print('Portanto, teremos mais uma iteração!')
print('A variável do índice',k,'entra na base')
print('A variável do índice',l,'sai da base')