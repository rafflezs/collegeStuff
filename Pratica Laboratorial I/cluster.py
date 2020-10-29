import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt 
from sklearn.cluster import KMeans 

df = pd.read_csv('artigos.csv')
df.head()

def fillMissingData(X, column):
    from sklearn.impute import SimpleImputer
    imputer = SimpleImputer(missing_values=np.nan, strategy='median')
    X[:,column:column + 1] = imputer.fit_transform(X[:,column:column + 1])
    return X

df_numpy = fillMissingData(df.to_numpy(), 4)
df_numpy[:,4] = df_numpy[:,4].astype("int")
X = pd.DataFrame({'citacoes':df_numpy[:,4]})
X.head()

wcss = []
for i in range(1,20):
    kmeans = KMeans(n_clusters = i, init = 'k-means++', max_iter = 300, n_init = 10)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
    
plt.plot(range(1,20),wcss)
plt.title("Método do cotovelo")
plt.xlabel("Número de Clusters")
plt.ylabel("Within-Cluster-Sum-of-Squares")
plt.show()

kmeans = KMeans(n_clusters = 5, init = 'k-means++', max_iter = 300, n_init = 10)
clusters = kmeans.fit_predict(X)
clusters

df['Cluster'] = clusters

sb.pairplot(X)

boolArray = df['Cluster'] == 0
df[boolArray]

boolArray = df['Cluster'] == 1
df[boolArray]

boolArray = df['Cluster'] == 2
df[boolArray]

boolArray = df['Cluster'] == 3
df[boolArray]

boolArray = df['Cluster'] == 4
df[boolArray]

x = X.to_numpy()

plt.scatter(
    x[clusters==0,0], x[clusters == 0, 0],
    s=50, c='lightgreen',
    edgecolor='black',
    label='grupo 0'
)

plt.scatter(
    x[clusters==1,0], x[clusters == 1, 0],
    s=50, c='orange',
    edgecolor='black',
    label='grupo 1'
)

plt.scatter(
    x[clusters==2,0], x[clusters == 2, 0],
    s=50, c='yellow',
    edgecolor='black',
    label='grupo 2'
)

plt.scatter(
    x[clusters==3,0], x[clusters == 3, 0],
    s=50, c='pink',
    edgecolor='black',
    label='grupo 3'
)

plt.scatter(
    x[clusters==4,0], x[clusters == 4, 0],
    s=50, c='blue',
    edgecolor='black',
    label='grupo 4'
)

plt.scatter(
    kmeans.cluster_centers_[:,0], kmeans.cluster_centers_[:,0],
    s=200, c='red', edgecolor='black',
    label='centroides'
)

plt.title("Quantidade de citacoes de artigos")
plt.xlabel("Citacoes")
plt.ylabel("Citacoes")
plt.legend()
plt.show()