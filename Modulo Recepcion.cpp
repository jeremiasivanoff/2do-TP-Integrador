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

struct Usuario
{
	char usuario[10];
	char contra[33];
	char ApeNom[60];
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
	char telefono[25];
};

struct Turnos
{
	int matricula_vet;
	fecha fecha_turno;
	int dni_duenio;
	char detalles_atencion[380];
 	int mostrado; //cambié a variable int
};

int menuprincipal();
void iniciosesion(FILE *usuario1,Usuario user,bool &verificacion);
void regmascota(FILE *mascot1,Mascota mcota,bool &verificacion);
void regturnos(FILE *turno1,Turnos tur,FILE *vet1,Veterinario veter,bool &verificacion);
void listaten(FILE *turno1,Turnos tur,FILE *vet1,Veterinario veter,bool &verificacion);

main()
{
	setlocale(LC_ALL,"spanish");
	FILE *mascot;
	FILE *turno;
	FILE *vet;
	FILE *usuario;
	Mascota mcota;
	Turnos tur;
	Veterinario veter;
	Usuario user;
	bool verificacion=false;
	
	int op;
	
	do
	{
		op=menuprincipal();
		switch(op)
		{
			case 1:
				system("cls");
				iniciosesion(usuario,user,verificacion);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				regmascota(mascot,mcota,verificacion);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				regturnos(turno,tur,vet,veter,verificacion);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				listaten(turno,tur,vet,veter,verificacion);
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

void iniciosesion(FILE *usuario1,Usuario user,bool &verificacion)
{
	char ingusuario[10];
	char ingcontra[33];
	int vusuario=0;
	int vcontra=0;
	usuario1=fopen("Usuarios.dat","rb");
	
	printf("\nIngrese el nombre de usuario: ");
	_flushall();
	gets(ingusuario);
	printf("\nIngrese la contrasenia: ");
	_flushall();
	gets(ingcontra);
	
	fread(&user,sizeof(Usuario),1,usuario1);
	while(!feof(usuario1) and vcontra==0 and vusuario==0)
	{
		if((strcmp(ingusuario,user.usuario)!=0) or (strcmp(ingcontra,user.contra)!=0)) //Cambio a uso de función strcmp()
		{
			fread(&user,sizeof(Usuario),1,usuario1);
		}
		else
		{
			vcontra=1;
			vusuario=1;
		}
	}
	
	if(vcontra==0 or vusuario==0)
	{
		printf("\nLos datos ingresados son incorrectos");
	}
	else
	{
		printf("\nInicio de sesion correcto.");
		verificacion=true;
	}
	
	fclose(usuario1);
}

void regmascota(FILE *mascot1,Mascota mcota,bool &verificacion)
{
	if(verificacion==false)
	{
		printf("\nNo inicio sesion,volviendo al menu....");
	}
	else
	{
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
		printf("\nIngrese el peso de la mascota en KG: ");
		scanf("%f",&mcota.peso); // Cambié %d por %f
		printf("\nIngrese el telefono del duenio: ");
		_flushall();
		gets(mcota.telefono);
		
		fwrite(&mcota,sizeof(Mascota),1,mascot1);
		fclose(mascot1);
	}
	
}

void regturnos(FILE *turno1,Turnos tur,FILE *vet1,Veterinario veter,bool &verificacion)
{
	int b=0;
	int buscar;
	
	if(verificacion==false)
	{
		printf("\nNo inicio sesion,volviendo al menu....");
	}
	else
	{
		vet1=fopen("Veterinarios.dat","rb");
		
		if(vet1==NULL)
		{
			system("cls");
			printf("\nERROR,No se encontro el archivo veterinarios.Contacte con el soporte");
			exit(1);
		}
		
		printf("Ingrese la matricula del veterinario: ");
		scanf("%d",&buscar);
		fread(&veter,sizeof(Veterinario),1,vet1);
		while(!feof(vet1))
		{
			if(buscar==veter.matricula_vet)
			{
				b=1;
				
				break;
			}
			else
			{
				fread(&veter,sizeof(Veterinario),1,vet1);
			}
		}

		fclose(vet1);

		if(b==0)
		{
			printf("\nMatricula de veterinario no encontrada.");
		}
		else
		{
			turno1=fopen("Turnos.dat","ab");

			tur.matricula_vet=veter.matricula_vet;
			printf("Ingrese el DNI del duenio: ");
			scanf("%d",&tur.dni_duenio);
			printf("\nIngrese la fecha del turno.");
			printf("\nIngrese el dia: ");
			scanf("%d",&tur.fecha_turno.dia);
			printf("\nIngrese el mes: ");
			scanf("%d",&tur.fecha_turno.mes);
			printf("\nIngrese el anio: ");
			scanf("%d",&tur.fecha_turno.anio);
			strcpy(tur.detalles_atencion,"vacio");
			tur.mostrado=0; //cambie a = 0
			printf("\n======Turno registrado======.");
			fwrite(&tur,sizeof(Turnos),1,turno1);

			fclose(turno1);
		}
	}
	
	
}

void listaten(FILE *turno1,Turnos tur,FILE *vet1,Veterinario veter,bool &verificacion)
{
	if(verificacion==false)
	{
		printf("\nNo inicio sesion,volviendo al menu....");
	}
	else
	{
		turno1=fopen("Turnos.dat","rb");
		vet1=fopen("Veterinarios.dat","rb");
		
		if(turno1==NULL or vet1==NULL)
		{
			printf("\nError al intentar abrir los archivos, contacte con el operador del sistema...");
			printf("\n\n");
			system("pause");
			exit(1);
		}
		
		fread(&tur,sizeof(Turnos),1,turno1);
	    fread(&veter,sizeof(Veterinario),1,vet1);
		
		printf("\nListado de atenciones");
		printf("\nVeterinario");
		printf("\t\tFecha del turno");
		printf("\n===========================================");
		
		while(!feof(turno1))
		{
			printf("\n\n");
			if(tur.matricula_vet==veter.matricula_vet)
			{
				printf("%s",veter.ApeyNom);
				printf("\t\t%d/%d/%d",tur.fecha_turno.dia,tur.fecha_turno.mes,tur.fecha_turno.anio);
			}
			fread(&tur,sizeof(Turnos),1,turno1);
	    	fread(&veter,sizeof(Veterinario),1,vet1);		
		}
		fclose(turno1);
		fclose(vet1);
	}
}
