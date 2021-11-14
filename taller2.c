#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T_LINEA 100

void reemplazar(char *texto, int n){
	for(int i=0; i<n; i++){
		if(texto[i]=='\n'){
			texto[i]=0;
		}
	}
}

int main(int argc, char **argv){
	int max, min;
        int res[100]; 
	float suma =0;
	int contPromedio=1;
	float resultado = 0;
	int limite =1;
	int contLimite =0;
	char entrada[T_LINEA];
	if(argc==3 && strcmp(argv[1],"-n")==0){
		limite = atoi(argv[2]);
	}
	fgets(entrada, T_LINEA, stdin);
	reemplazar(entrada, T_LINEA);

	while(strcmp(entrada,"x")!=0 && contLimite < limite){	
		suma+=atof(entrada);
		contPromedio++;
		//maximo y minimo
		res[contPromedio-1]=atoi(entrada);
		max=res[0];
		min =res[1];
		for(int i=0; i<contPromedio; i++){   	
			if(res[i]<min){
				min= res[i];
			}
			if(res[i]>max){
				max=res[i];
			}			
		}
		if (argc==3 && strcmp(argv[1],"-n")==0){
			contLimite++;
		}
		if(contLimite< limite){
			fgets(entrada, T_LINEA, stdin);
			reemplazar(entrada, T_LINEA);
		}
	}
	if(contPromedio>1){
		resultado =suma/(contPromedio-1);		
		
	}
	printf("%.2f\t\t%d\t\t%d\n", resultado,min,max);
	return 0;
}
