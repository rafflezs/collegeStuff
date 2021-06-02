\ Model ati1
\ LP format - for model browsing. Use MPS format to capture full model detail.
Maximize
  3000 liga1 + 2000 liga2
Subject To
 estoque_cobre: cobre <= 3
 estoque_zinco: zinco <= 1
 estoque_chumbo: chumbo <= 3
 Comp._liga_1: - liga1 + 0.5 cobre + 0.1 zinco + 0.4 chumbo = 0
 Comp._liga_2: - liga2 + 0.3 cobre + 0.2 zinco + 0.5 chumbo = 0
 seila: liga1 + liga2 >= 1
Bounds
End
