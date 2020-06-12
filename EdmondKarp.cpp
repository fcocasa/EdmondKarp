// C++ program to print values of INT_MAX 
// and INT_MIN 
#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <iostream>

struct first_string{
	char signo;
	int nodo;
};

int main() 
{ 
   /*int i_node[6] = {0,0,1,1,2,3};	
   int j_node[6] = {1,2,4,3,3,4};
   int capacidad[6] = {3,5,7,8,4,3};
   int flow[6] = {0,0,0,0,0,0};
   first_string first[5];
   int second[5] = {100,0,0,0,0};
   bool label[5] = {true,false,false,false,false};
   
   int num_nodos = 5;
   int num_arc = 6;*/
//representa de donde viene el flujo, y en caso de ser negativo, a donde lo esta enviando
//cantidad de flujo disponible en el nodo

	int i_node[13] = {0,0,1,2,2,2,3,3,4,4,5,5,6};	
    int j_node[13] = {1,2,4,1,3,5,1,6,6,7,6,7,7};
    int capacidad[13] = {8,12,10,3,3,6,2,4,2,7,1,5,7};
    int flow[13] = {0,0,0,0,0,0};
    first_string first[8];
    int second[8] = {100,0,0,0,0,0,0,0};
    bool label[8] = {true,false,false,false,false,false,false,false};
   
   int num_nodos = 8;
   int num_arc = 13;

   bool path = true;
   bool scan_done = false;
   bool source ;
   int prev_label = 1;
   int current_label = 1;
   int trace;
   int trace_node;
   int max_flow =0;

   first[0].nodo = 0;
   first[0].signo = '-';
   
	while (path)  { //mientras haya un camino entr 's' -> 't'
		for(int i=1;i<num_nodos;i++){//reinicia los valores first, second y label para volver a encontrar un augmenthing path(ap)
			first[i].signo = ' ';
			first[i].nodo = -1;
			second[i] = 0;
			label[i] = false;
		}
		prev_label = 1; //cuantos nodos pase la vez pasada
		current_label = 1;//cuantos nodos pase ahora
		scan_done = false;
		while(!scan_done){
			for(int i=0;i<num_arc;i++){ //recorre todos los arcos
				if(label[i_node[i]]&&first[j_node[i]].signo==' '&&(flow[i]<capacidad[i])){//si esta en el nodo i, y no paso por el nodo j, y tiene capacidad en el arco, voy
					first[j_node[i]].signo = '+';
					first[j_node[i]].nodo = i_node[i];
					//se manda todo lo que se puede, considerando el second del nodo i y el flujo aceptado por el arco 
					if (capacidad[i] - flow[i] < second[i_node[i]])
						second[j_node[i]] = capacidad[i] - flow[i];
					else
						second[j_node[i]] = second[i_node[i]]; 
					label[j_node[i]] = true;//pase por j
					current_label++;//sumo un  nodo mas al recorrido
					
				} else if(!label[i_node[i]] && label[j_node[i]] && flow[i]>0) { //utilizo el grafo residual, en lugar de ir de i -> j, voy de j -> i y resto flow previo
					first[i_node[i]].signo = '-';
					first[i_node[i]].nodo = j_node[i];

					if(flow[i] < second[j_node[i]])//se manda todo lo que se pouede en el sentido contrario a la arista(j -> i)
						second[i_node[i]] = flow[i];
					else
						second[i_node[i]] = second[j_node[i]];
					label[i_node[i]] = true;
					current_label++;
				}
			}
			if(label[num_nodos-1] || current_label == prev_label)//si llegue al ultimo encontre un camino, por otro lado si no llegue al ultimo
				scan_done = true;								//me fijo si desde el ulitmo escaneo recorrido algun nodo mas
			else
				prev_label = current_label;//actualizo para volver a recorrer el grafo
		} // end while(!scan_done)
		
		if(!label[num_nodos - 1])//sino llegue al ultimo, es que no encontre un camino para aumentar flujo 
			path = false;//actualiza para salir del while principal
		else {//actualiza los flows en funcion del path que encontro
			trace = num_nodos - 1;
			trace_node = first[trace].nodo;
			source = false;
			while(!source){//quiero llegar a la fuente
				for(int i = num_arc-1;i>=0;i--){// se actualizan los flujos, respetando las capacidades de las aristas que tiene el trace
					if(j_node[i] == trace && i_node[i] == trace_node && first[trace].signo == '+'){
										//si el arista llega a t, y si ese arista sale nodo que le envio flujo a 
										//t(es decir, que encontre el arista que buscaba), y etsa en +, es porque le esta llegando flujo
						flow[i]+=second[num_nodos - 1];
						trace = i_node[i];
						trace_node = first[trace].nodo;
					} else if(i_node[i] == trace && j_node[i] == trace_node && first[trace].signo == '-'){
						flow[i]-=second[num_nodos - 1];
						trace = j_node[i];
						trace_node = first[trace].nodo;
					}
				}
				if (trace == 0)
					source = true;
			}
		}
		
	} //end while(path)
	
	for(int i = 0;i<num_arc;i++){
		if(label[i_node[i]] && !label[j_node[i]])
			max_flow+=flow[i];
	}

	/*for(int i = 0;i<num_arc;i++){//suma de los flujos que salen del nodo fuente, para obtener el flujo maximo
		if(i_node[i] == 0){
			max_flow+=flow[i];
		}
	}/*

	cout<<"El flujo maximo es: "<<max_flow<<endl;
   
   
   return 0; 
} 
