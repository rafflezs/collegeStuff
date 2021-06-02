\ Model Arenales
\ LP format - for model browsing. Use MPS format to capture full model detail.
Minimize
  0.56 x1 + 0.81 x2 + 0.46 x3
Subject To
 protein: 0.2 x1 + 0.5 x2 + 0.4 x3 >= 0.3
 calcium: 0.6 x1 + 0.4 x2 + 0.4 x3 >= 0.5
 unit: x1 + x2 + x3 = 1
Bounds
End
