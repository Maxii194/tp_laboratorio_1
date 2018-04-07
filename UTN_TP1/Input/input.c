#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un numero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
	
	int retorno = -1;
		
	do{
		
		printf(message);
		scanf("%d",input);
		if(*input < lowLimit || *input > hiLimit){
			
			printf(eMessage);
		}
		
		retorno = 0;
		
	}while(*input < lowLimit || *input > hiLimit);
	


    return retorno;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{

	int retorno = -1;

	do{
		
		printf(message);
		scanf("%f",input);
		if(*input < lowLimit || *input > hiLimit){
				
			printf(eMessage);
		}
			
		retorno = 0;
		
	}while(*input < lowLimit || *input > hiLimit);
		
    
    return retorno;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char primerOpcion, char segundaOpcion, char terceraOpcion)
{
	
	int retorno = -1;
		
	do{
    	
		fflush(stdin);
		printf(message);
		scanf("%c",input);
		if(*input != primerOpcion && *input > segundaOpcion && *input != terceraOpcion){
			
			printf(eMessage);
		}
		
		retorno = 0;
		
	}while(*input != primerOpcion && *input > segundaOpcion && *input != terceraOpcion);

    return retorno;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    
    int retorno = -1;
    
    do{
		fflush(stdin);	
		printf(message);
		scanf("%s",input);
		if(strlen(input) < lowLimit || strlen(input) > hiLimit){
			
			printf(eMessage);
		}
				
		retorno = 0;
		
	}while(strlen(input) < lowLimit || strlen(input) > hiLimit);
		

    return retorno;
}
