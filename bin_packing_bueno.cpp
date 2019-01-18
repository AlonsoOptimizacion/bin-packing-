#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
#define CAPACIDAD 50
#define CONTENEDORES 500

using namespace std;


int LeerArchivo(int *arreglo){
	int i;
	FILE *Archivo; 
	Archivo = fopen ("datos_2.txt", "r"); 
	if(Archivo == NULL){ 
		cout<<"No se ha podido abrir el fichero."<<endl;
		exit(1);
	} 
	for(i=0;!feof(Archivo);i++){ 
		
        fscanf(Archivo,"%d", &arreglo[i]);
        cout<<arreglo[i]<<" ";
	} 
	return i;	
	fclose (Archivo);
}

int insercion(int *arreglo, int tam ){
	   int i, pos, aux;
	
	    for(i=0;i<tam;i++){
	    	aux=arreglo[i];
		  	pos=i;
	        while ((pos>0) && (aux>arreglo[pos-1])){
				arreglo[pos]=arreglo[pos-1];
				pos--; 
			}
		 	arreglo[pos]=aux;
	    }
        //printf("\n");  
}
int llena(int tam, int *arreglo, int *optimos, int *numeros, int *unos){
	int i, j, cont=0, indice=0, aux1, aux2, resultado=0, x=0, contenedores=0,aux=0;
	
	for(i=0;i<tam;i++){
    	if(arreglo[i]==1){
    		unos[cont]=arreglo[i];
    		cont++;
		}
	}
	cout<<cont<<"contadores"<<endl;
	for(i=0;i<cont;i++){
		cout<<" "<<unos[i]<<" ";
	}
	
	for(i=0;i<(tam-cont);i++){
		numeros[indice]=arreglo[i];
		indice++;
	}
	cout<<endl;
	cout<<indice<<"indice de numeros "<<endl;
	cout<<endl;
	for(i=0;i<indice;i++){
		cout<<" "<<numeros[i]<<" ";
	}
	
	for(i=0;i<indice;i++){
		aux1=numeros[i];
			for(j=i+1;j<indice;j++){
				aux2=numeros[j];
				resultado=aux1+aux2+x;
				//cout<<"resultado: "<<resultado<<endl;
				if(resultado<=CAPACIDAD && numeros[i]!=0){
					x=resultado;
					aux1=0;	
					numeros[j]=0;
					numeros[i]=0;
				}else if(x!=0 && resultado<=CAPACIDAD){
					x=resultado;
					aux1=0;
					numeros[j]=0;
				}
			}
		if(numeros[i]!=0){
			optimos[contenedores]=numeros[i];
			//cout<<"resultado guardado: "<<optimos[contenedores]<<endl;
			numeros[i]=0;
			contenedores++;
		}else if (x>0){
			optimos[contenedores]=x;
		//	cout<<"resultado guardado: "<<optimos[contenedores]<<endl;
			contenedores++;
			x=0;
		}
	}
	int ele=0;
	aux=cont;//pone los unos en los contenedores que les hace falta llenarse 
	for(i=0; i<contenedores; i++){
		if(optimos[i]<CAPACIDAD && aux>0){
			while(optimos[i]<CAPACIDAD){
				optimos[i]=optimos[i]+1;
				aux--;
				unos[ele]=0;
				ele++;
				if(aux==0){
					break;
				}
			}
		}
	}
	return contenedores;
}

int main(){
	int arreglo[MAX];
	int optimos[CONTENEDORES]; 
	int numeros[CONTENEDORES];
	int unos[MAX];
	int tam, i, j=0, numero, cont=0, optimo=0, resultado=0, contenedores, indice=0;
	int mitad=CAPACIDAD/2;
	double div=0, sum=0, res;
	
	tam=LeerArchivo(arreglo);
	cout<<endl;
	cout<<tam<<"tamaño"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\tNumeros ordenados"<<endl;	
	insercion(arreglo, tam);
	for(i=0;i<tam;i++){
		cout<<arreglo[i]<<" ";
		sum+=arreglo[i];
	}
	cout<<endl;
	cout<<"suma de articulos "<<sum<<endl;
	div=sum/CAPACIDAD;
	optimo=div;
	res =div-optimo;
	if(res>0){
		optimo=optimo+1;
	}
	printf("numeros de contenedores en enteros %d\n", optimo);
	printf("capacidad del contenedor %d \n", CAPACIDAD);

	contenedores=llena(tam, arreglo, optimos, numeros, unos);	
	
	cout<<endl;
    cout<<"tamaño de contenendores: "<<contenedores<<endl;

	cout<<endl;
/*	cout<<"contenedores "<<endl;
	cout<<endl;
	for(i=0;i<contenedores;i++){
		cout<<optimos[i]<<" ";
	}*/
	return 0;
}
