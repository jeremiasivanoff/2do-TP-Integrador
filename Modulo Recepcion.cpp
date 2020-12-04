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
void regmascota(FILE *mascot1,Mascota mcota);
main()
{
	setlocale(LC_ALL,"spanish");
	FILE *mascot;
	FILE *turno;
	Mascota mcota;
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
				regmascota(mascot,mcota);
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
			default:
				system("cls");
				printf("\nNo ingreso una opcion valida, intente nuevamente.");
				printf("\n\n");
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

void regmascota(FILE *mascot1,Mascota mcota)
{
	int i;
	mascot1=fopen("Mascotas.dat","ab");
	
	printf("\nIngrese el nombre de la mascota: ");
	_flushall();
	gets(mcota.ApeyNom);
	printf("\nIngrese el domicilio de la mascota: ");
	gets(mcota.domicilio);
	printf("\nIngrese el DNI del duenio: ");
	scanf("%d",&mcota.dni_duenio);
	printf("\nIngrese la localidad: ");
	_flushall();
	gets(mcota.localidad);
	printf("\nIngrese la fecha de nacimiento de la mascota.");
	printf("\nIngrese el dia: ");
	scanf("%d",&mcota.fecha_nacimiento.dia);
	printf("\nIngrese el mes: ");
	scanf("%d",&mcota.fecha_nacimiento.mes);
	printf("\nIngrese el anio: ");
	scanf("%d",&mcota.fecha_nacimiento.anio);
	printf("\Ingrese el peso de la mascota en KG: ");
	scanf("%d",&mcota.peso);
	printf("\nIngrese el telefono del duenio: ");
	_flushall();
	gets(mcota.telefono);
	
	fwrite(&mcota,sizeof(Mascota),1,mascot1);
	fclose(mascot1);
}
