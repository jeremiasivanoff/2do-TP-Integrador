#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct Mascota
{
	char ApeyNom[60];
	char domicilio[60];
	int dni_duenio;
	char localidad[60];
	fecha fecha_nacimiento;
	float peso;
	char telefono[25];
};

struct Turnos
{
	int matricula_vet;
	fecha fecha_turno;
	int dni_duenio;
	char detalles_atencion[380];
};

int menuprincipal();

main()
{
	setlocale(LC_ALL,"spanish");
	Mascota mcota[20];
	Turnos tur[20];
	
	int op;
	
	do
	{
		op=menuprincipal();
		switch(op)
		{
			case 1:
				system("cls");
				
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				printf("\nSaliendo de la aplicacion,");
				system("pause");
				system("cls");
				break;	
		}
	}while(op!=5);
	
}


int menuprincipal()
{
	int op;
	
	printf("\nModulo del asistente.");
	printf("\n===============================");
	printf("\n1.- Iniciar sesion.");
	printf("\n2.- Registrar mascota.");
	printf("\n3.- Registrar turno.");
	printf("\n4.- Listado de atenciones por Veterinario y Fecha.");
	printf("\n\n");
	printf("\n5.- Cerrar la aplicacion");
	printf("\n\n");
	printf("\nIngrese una opcion: ");
	scanf("%d",&op);
	return op;
}
