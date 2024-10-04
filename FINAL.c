#include <stdio.h>
#include <string.h>
 
#define NUM_EST 5          
#define NUM_ASG 3          
#define NOTA_APROBATORIA 6  
 
int main() {
   
    float cal[NUM_EST][NUM_ASG];                  
    float prom_Est[NUM_EST] = {0};                
    float prom_Asg[NUM_ASG] = {0};                
    int aprobadosPorAsignatura[NUM_ASG] = {0};    
    float calificacionAltaPorEstudiante[NUM_EST];
    float calificacionBajaPorEstudiante[NUM_EST];
    float calificacionAltaPorAsignatura[NUM_ASG];
    float calificacionBajaPorAsignatura[NUM_ASG];
 
    char nombresEstudiantes[NUM_EST][50];        
    char nombresAsignaturas[NUM_ASG][30] = {"Programación", "Electrónica", "Circuitos"};
 
   
    printf("Ingrese los nombres de los estudiantes:\n");//INGRESA NOMBRES
    for (int i = 0; i < NUM_EST; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf("%s", nombresEstudiantes[i]);
    }
 
    printf("\nIngrese las calificaciones de los estudiantes en las siguientes asignaturas:\n"); //INGRESA CALIFICACIONES
    for (int i = 0; i < NUM_EST; i++) {
        printf("\nCalificaciones de %s:\n", nombresEstudiantes[i]);
        for (int j = 0; j < NUM_ASG; j++) {
            do {
                printf("  %s: ", nombresAsignaturas[j]);
                scanf("%f", &cal[i][j]);
 
                if (cal[i][j] < 0 || cal[i][j] > 10) {
                    printf("Error: Calificación fuera de rango. Ingrese un valor entre 0 y 10.\n");
                }
            } while (cal[i][j] < 0 || cal[i][j] > 10);
        }
    }
 
    //CALCULA LA NOTA BAJA Y ALTA Y EL PROMEDIO
    for (int i = 0; i < NUM_EST; i++) {
        float suma = 0;
        calificacionAltaPorEstudiante[i] = cal[i][0];
        calificacionBajaPorEstudiante[i] = cal[i][0];
 
        for (int j = 0; j < NUM_ASG; j++) {
            suma += cal[i][j];
            if (cal[i][j] > calificacionAltaPorEstudiante[i]) {
                calificacionAltaPorEstudiante[i] = cal[i][j];
            }
            if (cal[i][j] < calificacionBajaPorEstudiante[i]) {
                calificacionBajaPorEstudiante[i] = cal[i][j];
            }
        }
        prom_Est[i] = suma / NUM_ASG;
    }
 
   
    for (int j = 0; j < NUM_ASG; j++) {
        float suma = 0;
        calificacionAltaPorAsignatura[j] = cal[0][j];
        calificacionBajaPorAsignatura[j] = cal[0][j];
 
        for (int i = 0; i < NUM_EST; i++) {
            suma += cal[i][j];
 
            if (cal[i][j] > calificacionAltaPorAsignatura[j]) {
                calificacionAltaPorAsignatura[j] = cal[i][j];
            }
            if (cal[i][j] < calificacionBajaPorAsignatura[j]) {
                calificacionBajaPorAsignatura[j] = cal[i][j];
            }
 
            if (cal[i][j] >= NOTA_APROBATORIA) {
                aprobadosPorAsignatura[j]++;
            }
        }
        prom_Asg[j] = suma / NUM_EST;
    }
 
//IMPRIME
    printf("\n--- Resultados ---\n");
    for (int i = 0; i < NUM_EST; i++) {
        printf("Promedio de %s: %.2f (Alta: %.2f, Baja: %.2f)\n",
               nombresEstudiantes[i], prom_Est[i], calificacionAltaPorEstudiante[i], calificacionBajaPorEstudiante[i]);
    }
 
    for (int j = 0; j < NUM_ASG; j++) {
        printf("Promedio de %s: %.2f (Alta: %.2f, Baja: %.2f)\n",
               nombresAsignaturas[j], prom_Asg[j], calificacionAltaPorAsignatura[j], calificacionBajaPorAsignatura[j]);
    }
 
    for (int j = 0; j < NUM_ASG; j++) {
        printf("Estudiantes aprobados en %s: %d\n", nombresAsignaturas[j], aprobadosPorAsignatura[j]);
    }
 
    return 0;
}