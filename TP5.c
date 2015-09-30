#include <stdio.h>

/*Este programa diferencia el nombre del programa de las opciones, los valores y los parametros*/
/*Integrantes: Dieguez Manuel, Fogg Matias, Schnocca Juan, Silva Gonzalo y Suarez Gonzalo*/

int main(int argc, char *argv[])
{
	char nombre[20];
	char opciones[20][20];
	char valores [50][50]; 
	char parametros[20][20];
	
	system("clear");
	int i;
	int numopcion=0;
	int numparametro=0;
	int l; //vairable utilizada para las columnas de la matriz
	
	for (i=0;i<argc;i++)
	{
		if(i==0) //imprime el nombre del archivo y lo guarda en su respectiva matriz
		{
			printf("El nombre del archivo es: %s\n",argv[i]);	
			for(l=0; argv[i][l]!='\0'; l++)
			{
				nombre[l]=argv[i][l];
			}
			nombre[l]='\0';
			
		}
		
		if (*argv[i]=='-') //imprime las opciones y los valores los guarda a cada uno  en su respectiva matriz.
		{
			printf("Opcion numero %d: %s\n",numopcion+1,argv[i]);
			printf("El valor de la opcion %d es: %s\n",numopcion+1, argv[i+1]);
			
			for(l=0; argv[i][l]!='\0'; l++)
			{
				opciones[numopcion][l]=argv[i][l];
			}
			opciones[numopcion][l]='\0';
			i++;
			for(l=0; argv[i][l]!='\0'; l++)
			{
				valores[numopcion][l]=argv[i][l];
			}
			valores[numopcion][l]='\0';
			numopcion++;
		}
		else //imprime los parametros y los guarda en su matriz
		{
			if (i != 0)
			{
				printf ("Parametro numero %d = %s\n",numparametro+1,argv[i]);
				for(l=0; argv[i][l]!='\0'; l++)
				{
					parametros[numparametro][l]=argv[i][l];
				}
				parametros[numparametro][l]='\0';
				numparametro++;
			}
		}
		
	}	
	
int m, r;

	printf("\n\nNombre:\n"); 
	for(r=0; r<(sizeof(nombre)/sizeof(nombre[0])); r++) //imprime el nombre del archivo
	{
		if (nombre[r]=='\0')
		break;	
		printf("%c",nombre[r]);
	}
	
	printf("\n\nOpciones:\n"); //imprime las opciones una abajo de la otra
	for(m=0; m<numopcion; m++) //serian las filas
	{
		for(r=0; r<(sizeof(opciones[0])/sizeof(opciones[0][0])); r++)
		{
			printf("%c",opciones[m][r]);
			
		}
		printf("\n");
	
	}

	printf("\n\nValores:\n"); //imprime los valores uno abajo del otro
	for(m=0; m<numopcion; m++)
	{
		for(r=0; r<(sizeof(valores[0])/sizeof(valores[0][0])); r++)
		{
			printf("%c",valores[m][r]);
			if (valores[m][r]=='\0')
			break;
		}
		printf("\n");
	}

	printf("\n\nParametros:\n"); //imprime los parametros uno abajo del otro
	for(m=0; m<numparametro; m++)
	{
		for(r=0; r<(sizeof(parametros[0])/sizeof(parametros[0][0])); r++)
		{
			printf("%c",parametros[m][r]);
		}
		printf("\n");
	}

return 0;
}


