/* Matriz de adyacencia de un grafo */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<iostream>
using namespace std;
#define max 30 // NÚMERO MAXIMO DE VERTICES DEL GRAFO


//Arreglo de vertices/
typedef struct arregloV{// Estructura para el arreglo de vertices
	char V[max]; // se define un arreglo de caracteres de capacidad max
} VERTICES;

// Arreglo de aristas/
typedef struct arregloA{// estructura para el arreglo de aristas
	int A[max][max]; // se define un areglo bidimensional para almacenar las aristas
					 // 0 = ausencia de arista
}ARISTAS; 

VERTICES VerticesGrafo; // Se define la variable VerticesGrafo de tipo VERTICES 
ARISTAS MatrizAdyacencia; // Se define la variable MatrizAdyacencia de tipo ARISTAS

// se define los prototipos de las funciones
void AgregarVertices();
void AgregarAristas();
void ImprimeMatrizAdyacencia();

int cant;

int main(){
	AgregarVertices();
	AgregarAristas();
	ImprimeMatrizAdyacencia();
	return 0;
}

/* función para ingresar los vertices del grafo */
void AgregarVertices(){
   	
	cout << "CUANTOS VERTICES TIENE EL GRAFO? -->";
	cin >> cant;
	cout << "DEBE INGRESAR LETRAS PARA LOS VERTICES : \n";
	for(int i=0;i<cant;i++){
		cout << "Ingrese vertice " <<i+1 << " => ";
		cin >> VerticesGrafo.V[i];
    }
}

/* función para agregar las aristas */
void AgregarAristas(){
	char respuesta; // variable para obtener la respuesta de la existencia de la arista
	for(int i=0;i<cant;i++){// se recorre las filas de la matriz de adyacencia
		for(int j=0;j<cant;j++){// se recorre las columnas de la matriz de adyacencia
			do { // solo permir como respuesta s,S,n,N
				cout << "\nExiste arista desde " << VerticesGrafo.V[i] << 
				        " hasta " << VerticesGrafo.V[j] << "?";
				cin >> respuesta;
			}
			while (respuesta != 's' && respuesta != 'S' 
			        && respuesta != 'n' && respuesta != 'N');
		if(respuesta == 's' ||  respuesta == 'S'){
				cout << "Ingrese el peso de la arista: ";
				cin  >> MatrizAdyacencia.A[i][j];
		};
		if(respuesta == 'n' ||  respuesta == 'N'){
				MatrizAdyacencia.A[i][j]=0;
		};
	}// fin for J		
}// fin de for i
}


void ImprimeMatrizAdyacencia(){
	printf("\n\nMatriz de Adyacencia del grafo: \n");
	for(int i=0; i<cant; i++){
		for(int j=0;j<cant;j++){
			printf("%d  ",MatrizAdyacencia.A[i][j]);
		}
		printf("\n");
	}
}
