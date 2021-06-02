import gurobipy as gp
from IPython.display import display

m = gp.Model("Arenales")
x1 = m.addVar(lb = 0, name = "x1")
x2 = m.addVar(lb = 0, name = "x2")
x3 = m.addVar(lb = 0, name = "x3")

protein = m.addConstr(0.2*x1+0.5*x2+0.4*x3 >= 0.3, name="protein")
calcium = m.addConstr(0.6*x1+0.4*x2+0.4*x3 >= 0.5, name="calcium")
unit = m.addConstr(x1+x2+x3 == 1, name="unit")

m.setObjective(0.56*x1+0.81*x2+0.46*x3, gp.GRB.MINIMIZE)

m.write('Arenales1.lp')
m.write('Arenales1.mps')

m.optimize()

display(m.getVars())
display(m.objVal)

for v in m.getVars():
    #if v.X > 1e-6:
        print(v.varName,':', round(v.x,3))
print('Preço do quilo da mistura: $', m.objVal)

m.close()