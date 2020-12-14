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

struct Atenciones
{
	int matricula_vet;
	int cant_atenciones;
};


void registrarvet(FILE *vet1, veterinario vet);
void registrarusuario(FILE *usuario1, usuario user);
void atenciones(FILE *tur1, Turnos tur);
int menuprincipal();
void ranking();

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
			ranking();
			system("pause");
			break;
			case 5:
			system("CLS");
			printf("\nFin del Programa\n");
			system("pause");
			exit(1);
			break;
			default:
			printf("Error eligio una opcion no existente\n");
			system("pause");
			
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
	int i,v=0,bandera=0,mayus=0,num=0,nume=0,va=0;
	int espacio=0,conse=0,cons=0;
	char ant;
	char nom[11];
	system("CLS");
	
	usuario user_aux;
	
	printf("\tIngrese los datos del usuario");
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(user.usuario);

	usuario1=fopen("Usuarios.dat","rb");
	if(usuario1!=NULL)
	{
		fread(&user_aux,sizeof(usuario),1,usuario1);
		while(!feof(usuario1))
		{
			if(strcmp(user.usuario,user_aux.usuario)==0)
			{
				va=1;
			}
			fread(&user_aux,sizeof(usuario),1,usuario1);
		}
			
	}
	fclose(usuario1);

	if(va==1)
	{
		printf("\nEl Usuario ingresado ya existe, por favor ingrese otro");
	}
	


	usuario1=fopen("Usuarios.dat","ab");	
	
	if(strlen(user.usuario)>=6 and strlen(user.usuario)<=10 and va!=1)
	{
		if(user.usuario[0]>=97 and user.usuario[0]<=122)
		{
			
			for(i=0;i<=user.usuario[i];i++)
			{	
				if(user.usuario[i]>=65 and user.usuario[i]<=90)
				{
					mayus++;
				}
				
				if(user.usuario[i]>=48 and user.usuario[i]<=57)
				{
					num=num+1;
				}
			}
				
			if(mayus>=2)
			{
				if(num<=3)
				{
					printf("\nUsuario valido");
					bandera=1;
				}
				else
				{
					printf("\nEl usuario no puede tener mas de 3 digitos");
					printf("\nUsuario invalido");
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
				if((user.contra[i]>=65 and user.contra[i]<=90) or (user.contra[i]>=97 and user.contra[i]<=122))
				{
					if(user.contra[i]+1==user.contra[i+1])
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
		fwrite(&user,sizeof(usuario),1,usuario1);
	}

	fclose(usuario1);
}

void atenciones(FILE *tur1, Turnos tur)
{
	int mes,b=0;
	tur1=fopen("Turnos.dat","rb");
	printf("\nIngrese el mes para mostrar las atenciones: ");
	scanf("%d",&mes);
	fread(&tur,sizeof(Turnos),1,tur1);
	while(!feof(tur1))
	{
		if((mes==tur.fecha_turno.mes) and (tur.mostrado==1))
		{
		b=1;
		printf("\nMatricula: %d",tur.matricula_vet);
		printf("\nFecha\n");
		printf("\nDia: %d",tur.fecha_turno.dia);
		printf("\nMes: %d",tur.fecha_turno.mes);
		printf("\nAnio: %d",tur.fecha_turno.anio);
		printf("\nDNI del duenio: %d",tur.dni_duenio);
		printf("\nDetalles de atencion: %s\n",tur.detalles_atencion);
		printf("===========================================\n");
		}
		fread(&tur,sizeof(Turnos),1,tur1);
	}
	fclose(tur1);
	if(b==0)
	{
		printf("\nNo hay turnos para el mes ingresado\n");
	}

	
}
	
void ranking()
{
	FILE *arch;
    
	veterinario reg_vets[50];
	Turnos reg_turnos[50];
	Atenciones reg_atenciones[50],aux;

	bool band = true,stop;
    int i = 0,num_vets = 0,num_turnos = 0,contador = 0;

    //Archivo de veterinarios:
    arch=fopen("Veterinarios.dat","rb");

    if (arch==NULL)
    {
        printf("\nEl archivo 'Veterinarios.dat' no fue creado o se elimino, contacte con soporte.");
		band = false;
    }
    else
    {
        fread(&reg_vets[i],sizeof(veterinario),1,arch);
        while (!feof(arch))
        {
            i++;
            fread(&reg_vets[i],sizeof(veterinario),1,arch);
        }
        num_vets = i;
        i = 0;
        fclose(arch);
    }

	//Archivo de turnos:
    arch=fopen("Turnos.dat","rb");

    if (arch==NULL)
    {
        printf("\nEl archivo 'Turnos.dat' no fue creado o se elimino, contacte con soporte.");
		band = false;
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

	if (band)
	{
		//Obtiene la cantidad de turnos por veterinario:
		for (i = 0; i < num_vets; i++)
		{
			contador = 0;

			for (int k = 0; k < num_turnos; k++)
			{
				if ((reg_vets[i].matricula_vet == reg_turnos[k].matricula_vet) and (reg_turnos[k].mostrado == 1))
				{
					contador++;
				}
			}
			
			reg_atenciones[i].matricula_vet = reg_vets[i].matricula_vet;
			reg_atenciones[i].cant_atenciones = contador;
		}
		
		//Ordena el ranking de mayor a menor:
		do
		{
			stop=false;
			
			for (i = 0 ; i < num_vets-1 ; i++)
			{
				if(reg_atenciones[i].cant_atenciones < reg_atenciones[i+1].cant_atenciones)
				{
					aux=reg_atenciones[i];
					reg_atenciones[i]=reg_atenciones[i+1];
					reg_atenciones[i+1]=aux;
					stop=true;
				}
			}
		}
		while (stop);

		//Muestra el ranking de veterinarios:
		for (i = 0; i < num_vets; i++)
		{
			printf("\nPuesto %d:",i+1);
			printf("\nMatricula: %d",reg_atenciones[i].matricula_vet);
			printf("\nCantidad de atenciones: %d",reg_atenciones[i].cant_atenciones);
			printf("\n--------------------------------");
		}
		
	}
	
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



