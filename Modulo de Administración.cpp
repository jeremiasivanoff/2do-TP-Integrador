#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct veterinario
{
	char ApeNom[60];
	int matri;
	int dni;
	char tel[25];
};

struct usuario
{
	char usuario[10];
	char contra[10];
	char ApeNom[60];
};

void registrarvet(FILE *vet1, veterinario vet);
void registrarusuario(FILE *usuario1, usuario user);
int menuprincipal();
main()
{
	setlocale(LC_ALL,"spanish");
	veterinario vet;
	usuario user;
	int op;
	FILE *usuario;
	FILE *vete;
	do
	{
		op=menuprincipal();
		switch(op)
		{
			case 1:
			registrarvet(vete,vet);
			system("pause");
			break;
			case 2:
			registrarusuario(usuario,user);
			system("pause");
			break;
			case 3:
			system("pause");
			break;
			case 4:
			system("pause");
			break;
			case 5:
			system("pause");
			break;
			
		}
	}while(op!=5);

}

void registrarvet(FILE *vet1, veterinario vet)
{
	system("CLS");
	vet1=fopen("Veterinario.dat","ab");
	printf("\tIngrese los datos del veterinario ");
	printf("\nIngrese el nombre del veterinario: ");
	_flushall();
	gets(vet.ApeNom);
	printf("\nIngrese su matricula: ");
	scanf("%d",&vet.matri);
	printf("\nIngrese su dni: ");
	scanf("%d",&vet.dni);
	printf("\nIngrese su n�mero de tel�fono: ");
	_flushall();
	gets(vet.tel);
	fwrite(&vet,sizeof(veterinario),1,vet1);
	fclose(vet1);
}

void registrarusuario(FILE *usuario1, usuario user)
{
	int i,v=0;
	char letras[28]= "abcdefghijklmn�opqrstuvwxyz";
	system("CLS");
	printf("\tIngrese los datos del usuario");
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(user.usuario);
	do
	{
		if(user.usuario[0]>96 and user.usuario[0]<123)
		{
			printf("\n La primera letra es minuscula.");
			//v++;
		}
		i++;
		/*if(v==0)
		{
			printf("Error usuario no v�lido - El primer car�cter debe ser min�scula Ingrese nuevamente.");
			system("pause");
			system("CLS");
			printf("\nNombre de Usuario: ");
			_flushall();
			gets(user.usuario);
		}*/
	}
	while(strlen(user.usuario)>=6 and strlen(user.usuario)<=10);
}

int menuprincipal()
{
	int opc=0;
	system("CLS");
	printf("\tM�dulo Administraci�n");
	printf("\n======================");
	printf("\n1.- Registrar Veterinario");
	printf("\n2.- Registrar Usuario Asistente");
	printf("\n3.- Atenciones por Veterinarios");
	printf("\n4.- Ranking de Veterinarios por atenciones");
	printf("\n5.- Registrar Veterinario");
	printf("\n6.- Cerrar Aplicaci�n");
	printf("\nSeleccione una opci�n: ");
	scanf("%d",&opc);
	return opc;
}



