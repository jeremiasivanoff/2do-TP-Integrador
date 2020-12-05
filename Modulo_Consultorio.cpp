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
    int matricula_vet;
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
    bool mostrado = false;
};

//Protipos de funciones:
void end();
void cargar_registros(Usuarios reg_usuarios[50],Veterinario reg_vets[50],Mascota reg_mascotas[50],Turnos reg_turnos[50],int &num_usuarios,int &num_vets,int &num_mascotas,int &num_turnos);
bool inicio_sesion(Usuarios reg_usuarios[50],Veterinario reg_vets[50],int num_usuarios,int num_vets,int &buscar_matricula);
void listado(Mascotas reg_mascotas[50],Turnos reg_turnos[50],int num_mascotas,int num_turnos,int buscar_matricula);

main()
{
	Usuarios reg_usuarios[50];
    Veterinario reg_vets[50];
    Mascota reg_mascotas[50];
    Turnos reg_turnos[50];

    int num_usuarios = 0,num_vets = 0,num_mascotas = 0,num_turnos = 0,buscar_matricula;
    int opcion;
    bool inicio = false;
    
    cargar_registros(reg_usuarios,reg_vets,reg_mascotas,reg_turnos,num_usuarios,num_vets,num_mascotas,num_turnos);
	
    do
    {
        system("cls");
        printf("\t\tModulo Consultorio Veterinario\n");
        printf("\t\t==============================\n");
        printf("\t1.- Iniciar Sesion.\n");
        printf("\t2.- Visulizar Lista de Espera de Turnos (Informe).\n");
        printf("\t3.- Registrar Evolucion de la Mascota.");
        printf("\n\n");
        printf("\t4.- Cerrar la aplicacion.");
        printf("\n\n");
        printf("\tIngrese una opcion: ");
        scanf("%d",&opcion);

        switch (opcion)
        {
            case 1:
                inicio = inicio_sesion(reg_usuarios,reg_vets,num_usuarios,num_vets,buscar_matricula);
                printf("\n\n");
                system("pause");
                break;
            
            case 2:
                if (inicio)
                {
                    listado(reg_mascotas,reg_turnos,buscar_matricula);
                }
                else
                {
                    printf("\nNo inicio sesion, volvera al menu.");
                }
                printf("\n\n");
                system("pause");
                break;
            
            case 3:
                if (inicio)
                {
                    
                }
                else
                {
                    printf("\nNo inicio sesion, volvera al menu.");
                }
                printf("\n\n");
                system("pause");
                break;

            case 4:
                printf("\n\tGracias por utilizar el programa.");
                printf("\n\n");
                system("pause");
                break;
            
            default:
                printf("\nIngreso una opcion incorrecta, volvera al menu.");
                printf("\n\n");
                system("pause");
                break;
        }
    } while (opcion != 4);
}

void cargar_registros(Usuarios reg_usuarios[50],Veterinario reg_vets[50],Mascota reg_mascotas[50],Turnos reg_turnos[50],int &num_usuarios,int &num_vets,int &num_mascotas,int &num_turnos)
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

bool inicio_sesion(Usuarios reg_usuarios[50],Veterinario reg_vets[50],int num_usuarios,int num_vets,int &buscar_matricula)
{
    char buscar_contra[10],buscar_ApeyNom[60];
    bool esta = false;
    
    printf("\t\nIngrese su numero de matricula: ");
    scanf("%d",&buscar_matricula);

    printf("\t\nIngrese su contraseña: ");
    _flushall();
    gets(buscar_contra);
    system("cls");

    for (int i = 0; i < num_vets; i++)
    {
        if (buscar_matricula == reg_vets[i].matricula_vet)
        {
            strcpy(buscar_ApeyNom,reg_vets[i].ApeyNom);
            esta = true;
            i = num_vets+1;
        }
    }
    
    if (esta)
    {
        esta = false;

        for (int i = 0; i < num_usuarios; i++)
        {
            if (strcmp(buscar_ApeyNom,reg_usuarios[i].ApeyNom) == 0)
            {
                if (strcmp(buscar_contra,reg_usuarios[i].contra) == 0)
                {
                    esta = true;
                    i = num_usuarios+1;
                }
            }
        }
        
        if (esta)
        {
            printf("\t\nInicio sesion con exito.");
            return true;
        }
        else
        {
            printf("\t\nEl numero de matricula, o contraseña, es incorrecta, volvera al menu.");
            return false;
        }
    }
    else
    {
        printf("\t\nEl numero de matricula, o contraseña, es incorrecta, volvera al menu.");
        return false;
    }
}

void listado(Mascotas reg_mascotas[50],Turnos reg_turnos[50],int num_mascotas,int num_turnos,int buscar_matricula)
{
    int buscar_dia,buscar_mes,buscar_anio;
    bool esta = false;

    printf("\nIngrese la fecha: ")
    printf("\nDia: ");
    scanf("%d",&buscar_dia);
    printf("\nMes: ");
    scanf("%d",&buscar_mes);
    printf("\nAnio: ");
    scanf("%d",&buscar_anio);

    for (int i = 0; i < num_turnos; i++)
    {
        if ((buscar_matricula == reg_turnos[i].matricula_vet) and (reg_turnos[i].mostrado == false))
        {
            if ((buscar_dia == reg_turnos[i].fecha_turno.dia) and (buscar_mes == reg_turnos[i].fecha_turno.mes) and (buscar_anio == reg_turnos[i].fecha_turno.anio))
            {
                esta = true;
                mostrar_datos_mascota(reg_mascotas,num_mascotas,reg_turnos[i].dni_duenio);
            }   
        }   
    }

    if (!esta)
    {
        printf("\nNo se encontraron turno para la fecha ingresada.");
    }
}

void mostrar_datos_mascota(Mascotas reg_mascotas[50],int num_mascotas,int buscar_dni_duenio)
{

}

