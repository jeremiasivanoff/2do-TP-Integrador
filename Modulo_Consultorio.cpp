#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>

//Estructuras:
struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct Usuarios
{
    char user[10];
    char contra[10];
    char ApeyNom[60];
};

struct Veterinario
{
    char ApeyNom[60];
    int matricula;
    int dni;
    char telefono[25];
};

struct Mascota
{
    char ApeyNom[60];
    char domicilio[60];
    int dni_dueño;
    char localidad[60];
    fecha fecha_nacimiento;
    float peso;
    char telefono[60];
};

struct Turnos
{
    int matricula_vet;
    fecha fecha_turno;
    int dni_duenio;
    char detalles_atencion[360];
};

//Protipos de funciones:
void end();

main()
{
	Usuarios reg_usuarios[50];

	
	end();
}



void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}