#include <stdio.h>
void calcular_NotaMateria(float cal[5][3][3], int materia, int contAlumnos);
void calcularAlumnosAproRepro (float cal[5][3][3], int materia, int contAlumnos);
int main(int argc, char *argv[])
{

    float cal[5][3][3] = {0};
    char nombres[5][20];
    char asignaturas[3][20] = {"Matematicas",
                               "Fisica",
                               "Quimica"};
    int opc = 0, opc2 = 0;

    float promedios[5][3] = {0};

    int contAlumnos = 0;

    float promediosAsig[3] = {0};

    int alumno = 0;
    int materias = 0;

    do
    {
        printf("Seleccione una opcion\n");
        printf("1.Registrar alumno\n");
        printf("2.Registrar calificaciones\n");
        printf("3.Promedio por alumno\n");
        printf("4.Promedio por asignatura\n");
        printf("5.Calificacion mas alta y baja por estudiante\n");
        printf("6.Calificacion mas alta y baja por asignatura\n");
        printf("7.Estudiantes aprobados y reprobados por asginatura\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Ingrese el nombre del alumno %d\n", contAlumnos + 1);
            getchar();
            fgets(nombres[contAlumnos], 20, stdin);
            contAlumnos++;
            break;
        case 2:
        {
            int selA = 0;
            printf("Seleccione el alumno del que desee regitrar las calificaciones:\n");
            for (int i = 0; i < contAlumnos; i++)
            {
                printf("%d.%s", i, nombres[i]);
            }
            printf(">> ");
            scanf("%d", &selA);

            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese las notas de la materia: %s\n", asignaturas[i]);
                for (int j = 0; j < 3; j++)
                {
                    do {
                        printf("Nota %d: ", j + 1);
                        scanf("%f", &cal[selA][i][j]);
                    } while (cal[selA][i][j] < 0 || cal[selA][i][j] > 10);
                    
                    promedios[selA][i] += cal[selA][i][j];
                }
                promedios[selA][i] /= 3;
            }
            break;
        }
        case 3:
            printf("--------------Calificaciones----------------\n");
            printf("%s\t\t%s\t\t%s\t\tNombre\n", asignaturas[0], asignaturas[1], asignaturas[2]);

            for (int i = 0; i < contAlumnos; i++)
            {
                printf("%.2f\t\t%.2f\t\t%.2f\t\t%s", promedios[i][0],
                       promedios[i][1],
                       promedios[i][2],
                       nombres[i]);
            }
            break;
        case 4:
        {
            if (contAlumnos > 0)
            {
                float promediosAsig[3] = {0};
                printf("\n--------------Promedio por asignatura----------------\n");

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < contAlumnos; j++)
                    {
                        promediosAsig[i] += promedios[j][i];
                    }
                    promediosAsig[i] /= contAlumnos;
                    printf("Promedio de %s: %.2f\n", asignaturas[i], promediosAsig[i]);
                }
            }
            else
            {
                printf("\n¡Error! No hay alumnos registrados todavia.\n");
            }
            break;
        }
        case 5:
        {
            for (int alumno = 0; alumno < contAlumnos; alumno++)
            {
                float notaMax = cal[alumno][0][0];
                float notaMin = cal[alumno][0][0];

                for (int j = 0; j < 3; j++)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        if (cal[alumno][j][i] > notaMax)
                        {
                            notaMax = cal[alumno][j][i];
                        }
                        if (cal[alumno][j][i] < notaMin)
                        {
                            notaMin = cal[alumno][j][i];
                        }
                    }
                }
                printf("\nLa nota mas alta del alumno %s es: %.2f\n", nombres[alumno], notaMax);
                printf("\nLa nota mas baja del alumno %s es: %.2f\n", nombres[alumno], notaMin);
            }
            break;
        }
        case 6:
        {
            printf("ingrese la materia que desea ver la nota mas alta y minima: 1.mate\n2.fisica\n3.quimica");
            scanf(" %d", &materias);
            calcular_NotaMateria(cal, materias - 1, contAlumnos);

            break;
        }
        case 7:{
            printf("ingrese la materia que desea hacer el promedio: 1.mate\n2.fisica\n3.quimica");
            scanf(" %d", &materias);
            calcularAlumnosAproRepro(cal, materias - 1, contAlumnos);

            break;
        }
        default:
            break;
        }

        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d", &opc2);
    } while (opc2 == 1);

    return 0;
}

void calcularAlumnosAproRepro (float cal[5][3][3], int materia, int contAlumnos){

int aprobados=0;
int reprobados=0;
float suma=0;
float promedio=0;

for (int i = 0; i < contAlumnos; i++)

{
    suma=0;
    for (int j = 0; j < 3; j++)
    {
        
        suma+=cal[i][materia][j];
    }
    
   promedio=suma /3;
   
   if (promedio>=6)
   {
    aprobados++;
   }
   if (promedio<6)
   {
    reprobados++;
   }
   
}
    printf("\n--- Reporte de Asignatura ---");
    printf("\nEstudiantes Aprobados: %d", aprobados);
    printf("\nEstudiantes Reprobados: %d\n", reprobados);

}



void calcular_NotaMateria(float cal[5][3][3], int materia, int contAlumnos)
{

    float max = cal[0][materia][0];
    float min = cal[0][materia][0];

    for (int i = 0; i < contAlumnos; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((cal[i][materia][j]) > (max))
            {
                max = cal[i][materia][j];
            }
            if ((cal[i][materia][j]) < (min))
            {
                min = cal[i][materia][j];
            }
        }
    }
    printf("\n--- Estadisticas de %d ---\n", materia);
    printf("Nota mas alta: %.2f\n", max);
    printf("Nota mas baja: %.2f\n", min);
}
