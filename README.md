# EdmondKarp
Implementacion del algoritmo presentado en el paper: Implementing the Ford-Fulkerson labeling algorithm with fixed-order scanning. Shin, k., Corder, S., (1992). 

Esta es la version del codigo pero en C++.

Para su ejecucion primero se debe compilar, para ello se debe abrir una terminal en la carpeta con el archivo y ejecutar:

```
g++ -o EdmondKarp EdmondKarp.cpp
```
Luego
```
./EdmondKarp
```

En caso de querer testear el codigo con datos propio cambiar los siguientes valores:

i_node[k] y j_node[k] representan el arco i->j
Para esa arista k, su capacidad sera capacidad[k] y su flujo flow[k]
```
int i_node[13] = {0,0,1,2,2,2,3,3,4,4,5,5,6};
int j_node[13] = {1,2,4,1,3,5,1,6,6,7,6,7,7};
int capacidad[13] = {8,12,10,3,3,6,2,4,2,7,1,5,7};
int flow[13] = {0,0,0,0,0,0};
```

El valor "8" en este caso representa el total de nodos en el grafo, en caso de hacer un grafo mas grande o mas pequeño cambiar este valor.

```
first_string first[8];//representa de donde viene el flujo, y en caso de ser negativo, a donde lo esta enviando
int second[8] = {100,0,0,0,0,0,0,0};//cantidad de flujo disponible en el nodo
bool label[8] = {true,false,false,false,false,false,false,false};
```
