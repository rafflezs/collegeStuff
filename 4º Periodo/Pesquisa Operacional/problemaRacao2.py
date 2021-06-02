from IPython.display import display
import gurobipy as gp

# cria um modelo
model = gp.Model("Racao2")

# cria variaveis de decisão
x1 = model.addVar(lb = 0, name = "x1")
x2 = model.addVar(lb = 0, name = "x2")
x3 = model.addVar(lb = 0, name = "x3")

# restrição 2

c1 = model.addConstr( 0.05*x2 + 0.2*x3 >= 10, name = "c1" )
c2 = model.addConstr( 0.10*x1+ 0.35*x2 + 0.78*x3 >= 0.20, name = "c2" )
c3 = model.addConstr( 0.20*x1+ 0.60*x2 + 0.02*x3 >= 0.35, name = "c3" )
c4 = model.addConstr( 0.70*x1 >= 0.35, name = "c4" )
c5 = model.addConstr( x1 + x2 + x3 == 1 , name = "c5" )
c6 = model.addConstr( x1 + x2 + x3 >= 0 , name = "c6" )

model.setObjective( 6*x1 + 7*x2 + 18*x3 )

# Minimizar f(x1 , x2, x3) = 6x1 + 7x2 + 18x3
#
# 0,05x2 + 0,20x3 ≥ 0,10
# 0,10x1+ 0,35x2 + 0,78x3 ≥ 0,20
# 0,20x1+ 0,60x2 + 0,02x3 ≥ 0,35 0,70x1 ≥ 0,35
# x1+ x2 + x3 = 1 x1 ≥ 0,
# x2 ≥ 0, x3 ≥ 0.

# Salva o modelo (formatos lp e mps)
model.write('Arenales2.lp')
model.write('Arenales2.mps')

# Otimiza o problema
model.optimize()

# Apresenta a solução
display(model.getVars())
display(model.objVal)

# Apresenta a solução
for v in model.getVars():
    #if v.X > 1e-6:
        print(v.varName,':', round(v.x,3))
print('$', model.objVal)

# Encerra o modelo
model.close()