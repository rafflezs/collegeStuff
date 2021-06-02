import gurobipy as gp
from IPython.display import display

m = gp.Model("ati1")
liga1 = m.addVar(lb = 0, name = "liga1")
liga2 = m.addVar(lb = 0, name = "liga2")

cobre = m.addVar(lb = 0, name = "cobre")
zinco = m.addVar(lb = 0, name = "zinco")
chumbo = m.addVar(lb = 0, name = "chumbo")

estoque_cobre = m.addConstr( cobre <= 3, name="estoque_cobre")
estoque_zinco = m.addConstr(zinco <= 1 , name="estoque_zinco")
estoque_chumbo = m.addConstr(chumbo <= 3 , name="estoque_chumbo")

l1 = m.addConstr( cobre*0.5 + zinco*0.1 + chumbo*0.4 == liga1, name="Comp. liga 1" );
l2 = m.addConstr( cobre*0.3 + zinco*0.2 + chumbo*0.5 == liga2, name="Comp. liga 2" );

seila = m.addConstr(liga1 + liga2 >= 1 , name="seila")


m.setObjective(3000*liga1 + 2000*liga2, gp.GRB.MAXIMIZE)

m.write('ati1.lp')
m.write('ati1.mps')

m.optimize()

display(m.getVars())
display(m.objVal)

for v in m.getVars():
    #if v.X > 1e-6:
        print(v.varName,':', round(v.x,3))
print('Lucro total', m.objVal)

m.close()