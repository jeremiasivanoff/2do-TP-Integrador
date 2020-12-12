#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct veterinario
{
	char ApeNom[60];
	int matricula_vet;
	int dni;
	char telefono[25];
};

struct usuario
{
	char usuario[10];
	char contra[33];
	char ApeNom[60];
};

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct Turnos
{
	int matricula_vet;
	fecha fecha_turno;
	int dni_duenio;
	char detalles_atencion[380];
	bool mostrado;
};

void registrarvet(FILE *vet1, veterinario vet);
void registrarusuario(FILE *usuario1, usuario user);
void atenciones(FILE *tur1, Turnos tur);
int menuprincipal();
main()
{
	setlocale(LC_ALL,"spanish");
	veterinario vet;
	Turnos tur;
	usuario user;
	int op;
	FILE *usuario;
	FILE *vete;
	FILE *Tur;
	do
	{
		op=menuprincipal();
		switch(op)
		{
			case 1:
			registrarvet(vete,vet);
			printf("\n");
			system("pause");
			break;
			case 2:
			registrarusuario(usuario,user);
			system("pause");
			break;
			case 3:
			atenciones(Tur,tur);
			system("pause");
			break;
			case 4:
			system("pause");
			break;
			case 5:
			system("CLS");
			printf("\nFin del Programa\n");
			system("pause");
			exit(1);
			break;
			
		}
	}while(op!=5);

}

void registrarvet(FILE *vet1, veterinario vet)
{
	system("CLS");
	vet1=fopen("Veterinarios.dat","ab");
	printf("\tIngrese los datos del veterinario ");
	printf("\nIngrese el nombre del veterinario: ");
	_flushall();
	gets(vet.ApeNom);
	printf("\nIngrese su matricula: ");
	scanf("%d",&vet.matricula_vet);
	printf("\nIngrese su dni: ");
	scanf("%d",&vet.dni);
	printf("\nIngrese su numero de telefono: ");
	_flushall();
	gets(vet.telefono);
	fwrite(&vet,sizeof(veterinario),1,vet1);
	fclose(vet1);
}

void registrarusuario(FILE *usuario1, usuario user)
{
	int i,v=0,bandera=0,mayus=0,num=0,nume=0;
	int espacio=0,conse=0,cons=0;
	char ant;
	system("CLS");
	usuario1=fopen("Usuarios.dat","ab");
	printf("\tIngrese los datos del usuario");
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(user.usuario);
	if(strlen(user.usuario)>=6 and strlen(user.usuario)<=10)
		{
			if(user.usuario[0]>=97 and user.usuario[0]<=122)
			{
				printf("\nLa primera letra es minuscula.");
				for(i=0;i<=user.usuario[i];i++)
				{	
					if(user.usuario[i]>=65 and user.usuario[i]<=90)
					{
						mayus++;
					
							if(user.usuario[i]>=48 and user.usuario[i]<=57)
							{
								num=num+1;
							}
					}
				}
					
			if(mayus>=2)
			{
				printf("\nEl usuario contiene al menos 2 letras mayusculas.\n");
					if(num<=3)
					{
						printf("\nEl Usuario contiene menos 3 digitos");
						printf("\nUsuario valido");
						bandera=1;
						fwrite(&user,sizeof(usuario),1,usuario1);
					}
					else
						{
							printf("\nEl usuario no puede tener mas de 3 digitos");
						}
						}
						else
						{
							printf("\nNo posee la cantidad minima de mayusculas deben ser al menos 2");
							printf("\nUsuario invalido");
						}	
			}
			else
			{
				printf("\nLa primera letra del usuario debe ser minuscula.");
				printf("\nUsuario invalido");
			}
		}
		else
		{
			printf("\nLa cantidad de caracteres debe ser de 6 a 10");
			printf("\nUsuario invalido\n");
		}
				

		
		if(bandera==1)
		{
			printf("\nIngrese la contrasenia: ");
			_flushall();
			gets(user.contra);
			if(strlen(user.contra)>=6 and strlen(user.contra)<=32)
			{
				for(i=0;i<=user.contra[i];i++)
				{
				if(user.contra[i]>=40 and user.contra[i]<=47 or user.contra[i]>=58 and user.contra[i]<=63 or user.contra[i]>=90 and user.contra[i]<=96 or user.contra[i]>=123 and user.contra[i]<=126 or user.contra[i]==239)
				{
					printf("\nLa contrasenia no puede contener signos de puntuacion o acentos");
				}
				else if(user.contra[i]==' ')
				{
					espacio=espacio+1;
					printf("\nLa contrasenia no debe tener espacios");
				}
				if(user.contra[i]>=48 and user.contra[i]<=57)
				{
					if(user.contra[i]+1==user.contra[i+1])
					{
						conse=conse+1;
					}
					
				}
				if(user.contra[i]>=65 and user.contra[i]<=90 or user.contra[i]>=97 and user.contra[i]<=122)
				{
					if(user.contra[i]<user.contra[i+1])
					{
						cons=cons+1;
					}
				}
			
				}
	
			if(espacio==0)
			{
				if(conse<3)
				{
					if(cons<1)
					{
						printf("\nContrasenia valida");
						bandera=2;
						fwrite(&user,sizeof(usuario),1,usuario1);
					}
					else
					{
						printf("\nLa contrasenia no puede tener dos letras seguidas");
					}
				}
				else
				printf("\nLa contrasenia no debe tener mas de 4 numeros consecutivos");
			}
		}
			else
			{
				printf("\nLa Contrasenia debe tener entre 6 y 32 caracteres");
			}
		}
	if(bandera==2)
	{
		printf("\nIngrese el Apellido y Nombre del usuario: ");
		_flushall();
		gets(user.ApeNom);
		//fwrite(&user.ApeNom,sizeof(usuario),1,usuario1);
		fwrite(&user,sizeof(usuario),1,usuario1);
	}

	fclose(usuario1);
}

void atenciones(FILE *tur1, Turnos tur)
{
	int mes;
	tur1=fopen("Turnos.dat","rb");
	printf("\nIngrese el mes para mostrar las atenciones: ");
	scanf("%d",&mes);
	fread(&tur,sizeof(Turnos),1,tur1);
	while(feof(tur1))
	{
		if(mes==tur.fecha_turno.mes)
		{
		printf("\nMatricula: %d",tur.matricula_vet);
		printf("\nFecha\n");
		printf("\nDia: %d",tur.fecha_turno.dia);
		printf("\nMes: %d",tur.fecha_turno.mes);
		printf("\nAnio: %d",tur.fecha_turno.anio);
		printf("\nDNI del duenio: %d",tur.dni_duenio);
		}
		fread(&tur,sizeof(Turnos),1,tur1);
	}
	fclose(tur1);

	
}
	
	

int menuprincipal()
{
	int opc=0;
	system("CLS");
	printf("\tModulo Administracion");
	printf("\n======================");
	printf("\n1.- Registrar Veterinario");
	printf("\n2.- Registrar Usuario Asistente");
	printf("\n3.- Atenciones por Veterinarios");
	printf("\n4.- Ranking de Veterinarios por atenciones");
	printf("\n5.- Cerrar Aplicacion");
	printf("\nSeleccione una opcion: ");
	scanf("%d",&opc);
	return opc;
}



