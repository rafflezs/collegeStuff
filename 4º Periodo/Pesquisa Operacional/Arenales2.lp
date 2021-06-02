\ Model Racao2
\ LP format - for model browsing. Use MPS format to capture full model detail.
Minimize
  6 x1 + 7 x2 + 18 x3
Subject To
 c1: 0.05 x2 + 0.2 x3 >= 10
 c2: 0.1 x1 + 0.35 x2 + 0.78 x3 >= 0.2
 c3: 0.2 x1 + 0.6 x2 + 0.02 x3 >= 0.35
 c4: 0.7 x1 >= 0.35
 c5: x1 + x2 + x3 = 1
 c6: x1 + x2 + x3 >= 0
Bounds
End
