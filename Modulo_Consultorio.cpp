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
    int dni_duenio;
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
void cargar_registros(Usuarios reg_usuarios[50],Veterinario reg_vets[50],Mascota reg_mascotas[50],Turnos reg_turnos[50],int num_usuarios,int num_vets,int num_mascotas,int num_turnos);

main()
{
	Usuarios reg_usuarios[50];
    Veterinario reg_vets[50];
    Mascota reg_mascotas[50];
    Turnos reg_turnos[50];
    int num_usuarios = 0,num_vets = 0,num_mascotas = 0,num_turnos = 0;
    
    cargar_registros(reg_usuarios,reg_vets,reg_mascotas,reg_turnos,num_usuarios,num_vets,num_mascotas,num_turnos);
	
	end();
}

void cargar_registros(Usuarios reg_usuarios[50],Veterinario reg_vets[50],Mascota reg_mascotas[50],Turnos reg_turnos[50],int num_usuarios,int num_vets,int num_mascotas,int num_turnos)
{
    FILE *arch;
    int i = 0;
    
    //Archivo de usuarios:
    arch=fopen("Usuarios.dat","rb");
    
    if (arch==NULL)
    {
        printf("\nEl archivo no fue creado o se elimino, contacte con soporte.");
    }
    else
    {
        fread(&reg_usuarios[i],sizeof(Usuarios),1,arch);
        while (!feof(arch))
        {
        i++;
        fread(&reg_usuarios[i],sizeof(Usuarios),1,arch); 
        }
        num_usuarios = i;
        i = 0;
        fclose(arch);
    }
    
    //Archivo de veterinarios:
    arch=fopen("Veterinarios.dat","rb");

    if (arch==NULL)
    {
        printf("\nEl archivo no fue creado o se elimino, contacte con soporte.");
    }
    else
    {
        fread(&reg_vets[i],sizeof(Veterinario),1,arch);
        while (!feof(arch))
        {
        i++;
        fread(&reg_vets[i],sizeof(Veterinario),1,arch); 
        }
        num_vets = i;
        i = 0;
        fclose(arch);
    }
    
    //Archivo de mascotas:
    arch=fopen("Mascotas.dat","rb");

    if (arch==NULL)
    {
        printf("\nEl archivo no fue creado o se elimino, contacte con soporte.");
    }
    else
    {
        fread(&reg_mascotas[i],sizeof(Mascota),1,arch);
        while (!feof(arch))
        {
        i++;
        fread(&reg_mascotas[i],sizeof(Mascota),1,arch); 
        }
        num_mascotas = i;
        i = 0;
        fclose(arch);
    }
    
    //Archivo de turnos:
    arch=fopen("Turnos.dat","rb");

    if (arch==NULL)
    {
        printf("\nEl archivo no fue creado o se elimino, contacte con soporte.");
    }
    else
    {
        fread(&reg_turnos[i],sizeof(Turnos),1,arch);
        while (!feof(arch))
        {
        i++;
        fread(&reg_turnos[i],sizeof(Turnos),1,arch); 
        }
        num_turnos = i;
        i = 0;
        fclose(arch);
    }
}









void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}