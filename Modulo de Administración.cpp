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
	printf("\nIngrese su número de teléfono: ");
	_flushall();
	gets(vet.tel);
	fwrite(&vet,sizeof(veterinario),1,vet1);
	fclose(vet1);
}

void registrarusuario(FILE *usuario1, usuario user)
{
	int i,v=0;
	char letras[28]= "abcdefghijklmnñopqrstuvwxyz";
	system("CLS");
	printf("\tIngrese los datos del usuario");
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(user.usuario);
	do
	{
		if(user.usuario[i]=='a' or user.usuario[i]=='b' or user.usuario[i]=='c' or user.usuario[i]=='d' or user.usuario[i]=='e' or user.usuario[i]=='f' or user.usuario[i]=='g' or user.usuario[i]=='h'or user.usuario[i]=='i'or user.usuario[i]=='o' or user.usuario[i]=='j' or user.usuario[i]=='k' or user.usuario[i]=='l' or user.usuario[i]=='m' or user.usuario[i]=='n' or user.usuario[i]=='ñ' or user.usuario[i]=='o' or user.usuario[i]=='p' or user.usuario[i]=='q' or user.usuario[i]=='r' or user.usuario[i]=='s' or user.usuario[i]=='t' or user.usuario[i]=='u' or user.usuario[i]=='v' or user.usuario[i]=='w' or user.usuario[i]=='x' or user.usuario[i]=='y' or user.usuario[i]=='z')
		{
			v++;
		}
		i++;
		if(v==0)
		{
			printf("Error usuario no válido - El primer carácter debe ser minúscula Ingrese nuevamente.");
			system("pause");
			system("CLS");
			printf("\nNombre de Usuario: ");
			_flushall();
			gets(user.usuario);
		}
	}
	while(strlen(user.usuario)>=6 and strlen(user.usuario)<=10);
}

int menuprincipal()
{
	int opc=0;
	system("CLS");
	printf("\tMódulo Administración");
	printf("\n======================");
	printf("\n1.- Registrar Veterinario");
	printf("\n2.- Registrar Usuario Asistente");
	printf("\n3.- Atenciones por Veterinarios");
	printf("\n4.- Ranking de Veterinarios por atenciones");
	printf("\n5.- Registrar Veterinario");
	printf("\n6.- Cerrar Aplicación");
	printf("\nSeleccione una opción: ");
	scanf("%d",&opc);
	return opc;
}



