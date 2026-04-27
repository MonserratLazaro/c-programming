#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Estructura para almacenar los datos del estudiante 
typedef struct {
    char nombre[50], nacimiento[50], carrera[50]; // Nombre, procedencia, carrera
    char notasA; // Promedio en sistema de letras
    int notas[4], materias[5]; // Notas por periodo, materias inscritas (en código numérico)
    int edad, ID, semestre, seccion; // Edad, número identificador, semestre y sección
    float promedio; // Promedio en sistema númerico
} Estudiante;

Estudiante estudiantes[25]; // Arreglo de estudiante, capacidad máxima de 25 estudiantes
int num_estudiantes = 0; // Número total de estudiantes

// Declaración de funciones principales
void agregarEstudiante();
void modificarEstudiante();
void buscarEstudiante();
void eliminarEstudiante();
void mostrarEstudiantes();
void mostrarEstadisticas();

// Declaración de funciones auxiliares
int verificarEstudiante(int, bool *);
void codigosMaterias(Estudiante *);
void calificacionesPromedio(Estudiante *);
void imprimirAtributos(Estudiante *);

// Función main (muestra el menú principal de opciones e invoca a las funciones correspondientes)
int main() {
    int opcion;
    
    do {
        // Imprimir menú
        printf("\n-- MENÚ DE OPCIONES --\n");
        printf("\n1. Agregar un estudiante\n");
        printf("2. Modificar/Actualizar un estudiante\n");
        printf("3. Buscar un estudiante (por ID)\n");
        printf("4. Eliminar un estudiante\n");
        printf("5. Mostrar estudiantes\n");
        printf("6. Mostrar estadísticas\n");
        printf("7. Salir\n");
        printf("\nElija una opción: ");
        scanf("%d", &opcion);

        // Llamar a la función seleccionada
        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                modificarEstudiante();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                eliminarEstudiante();
                break;
            case 5:
                mostrarEstudiantes();
                break;
            case 6:
                mostrarEstadisticas();
                break;
            case 7:
                printf("Saliste del menú.\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 7); // Repetir mientras el usuario no elija la opción 7 (salir)
    
    return 0;
} // Fin

// Verificar si el estudiante existe (usada en buscarEstudiante, modificarEstudiante y eliminarEstudiante)
int verificarEstudiante(int IDverificar, bool *encontrado) {
    *encontrado = false; // Inicializar como no encontrado

    for (int i = 0; i < num_estudiantes; i++) {
        if (IDverificar == estudiantes[i].ID) { // Si se encuentra al estudiante
            *encontrado = true;
            return i; // Retorna el índice del estudiante encontrado
        }
    }

    // Si no se encuentra al estudiante
    printf("No se encontró ningún estudiante con ID %d.\n", IDverificar);
    return -1; // Retorna -1 para indicar que no se encontró al estudiante (el indice no se usará)
} // Fin

// Ingresar códigos de las materias inscritas (usada en agregarEstudiante y modificarEstudiante)
void codigosMaterias(Estudiante *estudiante) {
    int codigo;
    bool repetido; // Control de códigos ingresados 

    for (int a = 0; a < 5; a++) { 
        do { 
            repetido = false; // Inicializar en false en  cada iteración
            printf("Materia %d: ", a + 1);
            scanf("%d", &codigo);

            for(int b = 0; b < 5; b++) { // Comprobar que las materias no se repitan
                if(estudiante->materias[b] == codigo) {
                    repetido = true; 
                    printf("La materia %d ya fue introducida. Ingrese otro código.\n", codigo);
                    break;
                }
            }
        } while(repetido); // Repetir mientras el código este duplicado (repetido = true)

        estudiante->materias[a] = codigo; // Asignar el código cuando no se repita
    }
} // Fin

// Ingresar notas y calcular el promedio como número y letra (usada en agregarEstudiante y modificarEstidiante)
void calificacionesPromedio(Estudiante *estudiante) {
    estudiante->promedio = 0; // Inicializar promedio
    printf("Ingrese la calificación general por periodo.\n");

    for (int a = 0; a < 4; a++) { // Recorrer el arreglo para ingresar 4 notas válidas (0 - 100)
        do {
            printf("Nota en el periodo %d (0 - 100): ", a + 1);
            scanf("%d", &estudiante->notas[a]);

            if (estudiante->notas[a] < 0 || estudiante->notas[a] > 100) { // Si la nota no se encuentra dentro del rango
                printf("La nota debe ser un número entre 0 y 100.\n");
            }
        } while (estudiante->notas[a] < 0 || estudiante->notas[a] > 100); // Repetir mientras la nota no se válida

        estudiante->promedio += estudiante->notas[a]; // Asignar la nota cuando sea válida
    }

    estudiante->promedio /= 4.0; // Calcular promedio

    // Convertir promedio a sistema de letras
    if (estudiante->promedio >= 86) {
        estudiante->notasA = 'A';
    } else if (estudiante->promedio >= 76) {
        estudiante->notasA = 'B';
    } else if (estudiante->promedio >= 60) {
        estudiante->notasA = 'C';
    } else {
        estudiante->notasA = 'D';
    }

    printf("El promedio del estudiante es: %.2f (%c).\n", estudiante->promedio, estudiante->notasA); 
} // Fin

// Imprimir la información de cada estudiante
void imprimirAtributos(Estudiante *estudiante) {
    printf("\nNombre: %s\n", estudiante->nombre);
    printf("ID: %d\n", estudiante->ID);
    printf("Edad: %d\n", estudiante->edad);
    printf("Lugar de nacimiento: %s\n", estudiante->nacimiento);
    printf("Carrera: %s\n", estudiante->carrera);
    printf("Semestre: %d\n", estudiante->semestre);
    printf("Sección: %d\n", estudiante->seccion);
    printf("Materias inscritas: %d, %d, %d, %d, %d\n", estudiante->materias[0], estudiante->materias[1], estudiante->materias[2], estudiante->materias[3], estudiante->materias[4]);
    printf("Calificaciones por periodos: 1.- %d, 2.- %d, 3.- %d, 4.- %d\n", estudiante->notas[0], estudiante->notas[1], estudiante->notas[2], estudiante->notas[3]);
    printf("Promedio: %.2f (%c)\n", estudiante->promedio, estudiante->notasA);
}

// Función para agregar estudiantes
void agregarEstudiante() {
    if (num_estudiantes >= 25) { // Verificar que halla espacio antes de pedir cualquier dato
        printf("Se ha alcanzado el límite máximo de estudiantes. No se pueden agregar más.\n");
        return;
    }

    Estudiante estudiante; // Crear una instancia "estudiante"
    bool control = true; // Control de ID
    int id = 0, si; // Control de ID, para responder pregunta
    
    // Solicitar el primer dato (ID)
    printf("Ingrese los datos del estudiante.\n");
    printf("ID: ");
    scanf("%d", &id);
    
    // Verificar si el ID ya existe en el sistema
    for(int z = 0; z < num_estudiantes; z++){
        if(estudiantes[z].ID == id) {
            printf("El estudiante con ID %d ya existe.\n", id);
            control = false; // ID repetido
            break;
        }
    }
    
    // Agregar al estudiante si el ID no está repetido
    if(control) {
        estudiante.ID = id; // Asignar el ID

        printf("Nombre: ");
        getchar(); // Limpiar el buffer
        fgets(estudiante.nombre, sizeof(estudiante.nombre), stdin);
        estudiante.nombre[strcspn(estudiante.nombre, "\n")] = '\0'; // Eliminar salto de línea

        printf("Edad: ");
        scanf("%d", &estudiante.edad);

        printf("Lugar de nacimiento: ");
        getchar();
        fgets(estudiante.nacimiento, sizeof(estudiante.nacimiento), stdin);
        estudiante.nacimiento[strcspn(estudiante.nacimiento, "\n")] = '\0';

        printf("Carrera: ");
        getchar();
        fgets(estudiante.carrera, sizeof(estudiante.carrera), stdin);
        estudiante.carrera[strcspn(estudiante.carrera, "\n")] = '\0';

        printf("Semestre: ");
        scanf("%d", &estudiante.semestre);

        printf("Sección: ");
        scanf("%d", &estudiante.seccion);

        printf("Ingrese los códigos numéricos de las materias inscritas.\n");
        codigosMaterias(&estudiante); // Invocar a la función para ingresar materias

        // Invocar a la función para ingresar notas y calcular promedio
        calificacionesPromedio(&estudiante);

        estudiantes[num_estudiantes] = estudiante; // Asigna la estructura al arreglo de estudiantes, usando num_estudiantes como índice
        num_estudiantes++; // Aumentar el número de estudiantes
        printf("\nSe ha creado un nuevo estudiante exitosamente.\n");
        printf("El número actual de estudiantes es: %d\n", num_estudiantes);
    }

    // Reiterar la función
    printf("\n¿Desea agregar un nuevo estudiante? (Sí: 1, No: presione cualquier otro número)\n");
    scanf("%d",&si);
    if (si == 1) {
        agregarEstudiante();
    }
} // Fin

// Función para modificar los datos de un estudiante
void modificarEstudiante() {
    if (num_estudiantes == 0) { // Verificar si hay estudiantes 
        printf("Aún no existen estudiantes.\n");
        return;
    }
    
    int IDBuscar, opcion, i, j;
    bool encontrado; // Para verificar si el estudiante existe en el sistema

    // Solicitar ID del estudiante a modificar
    printf("Ingrese el ID del estudiante: ");
    scanf("%d", &IDBuscar);
    i = verificarEstudiante(IDBuscar, &encontrado); // Usar la funcion verificarEstudiante para buscar coincidencia

    if(encontrado) { // Si se encuentra al estudiante (encontrado = true)

        do { // Mostrar menú de opciones
            printf("¿Qué desea modificar?\n");
            printf("1. Nombre\n");
            printf("2. Edad\n");
            printf("3. Lugar de nacimiento\n");
            printf("4. Carrera\n");                
            printf("5. Semestre\n");
            printf("6. Sección\n");
            printf("7. Materias inscritas\n");
            printf("8. Notas por periodo\n");;
            printf("9. ID\n");
            printf("10. Salir\n");
            scanf(" %d", &opcion);

            if (opcion < 1 || opcion > 10) { 
                printf("Opción no válida. Intente nuevamente.\n");
            }

        } while (opcion < 1 || opcion > 10); // Repetir mientras la opción no sea válida (diferente de 1-10)

        // Sentencia para modificar el dato solicitado
        switch (opcion) {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                getchar(); // Limpiar el buffer
                fgets(estudiantes[i].nombre, sizeof(estudiantes[i].nombre), stdin);
                estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = '\0'; // Eliminar salto de línea
                break;
            case 2:
                printf("Ingrese la nueva edad: ");
                scanf("%d", &estudiantes[i].edad);
                break;
            case 3:
                printf("Ingrese el nuevo lugar de nacimiento: ");
                getchar();
                fgets(estudiantes[i].nacimiento, sizeof(estudiantes[i].nacimiento), stdin);               
                estudiantes[i].nacimiento[strcspn(estudiantes[i].nacimiento, "\n")] = '\0';
                break;
            case 4:
                printf("Ingrese la nueva carrera: ");
                getchar();
                fgets(estudiantes[i].carrera, sizeof(estudiantes[i].carrera), stdin);
                estudiantes[i].carrera[strcspn(estudiantes[i].carrera, "\n")] = '\0';
                break;
            case 5:
                printf("Ingrese el nuevo emestre: ");
                scanf("%d", &estudiantes[i].semestre);
                break;
            case 6:
                printf("Ingrese la nueva sección: ");
                scanf("%d", &estudiantes[i].seccion);
                break;
            case 7:
                printf("Ingrese los nuevos códigos numéricos de las materias inscritas.\n");
                codigosMaterias(&estudiantes[i]); // Invocar a la función para ingresar las materias
                break;
            case 8:
                calificacionesPromedio(&estudiantes[i]); // Invocar a la función para ingresar notas y calcular promedio
                break;
            case 9:
                do { 
                    printf("Ingrese el nuevo ID: ");
                    scanf("%d", &IDBuscar);
                    // Verificar si el ID ya existe
                    for (j = 0; j < num_estudiantes; j++) {
                        if (IDBuscar == estudiantes[j].ID) { 
                            printf("El ID %d ya existe. Intente con otro identificador.\n", estudiantes[i].ID);
                            break;
                        } else {
                            estudiantes[i].ID = IDBuscar; // Asignar el ID si no está repetido
                        }
                    }
                } while (IDBuscar == estudiantes[j].ID); // Repetir mientras el usuario ingrese un ID que ya exista en el sistema
                break;
            case 10:
                printf("Saliste del menú de modificación.\n");
                break;
        }
        printf("\nDatos actualizados.\n");
    }
} // Fin

// Función para buscar a un estudiante por ID y mostrar sus datos
void buscarEstudiante() {
    if (num_estudiantes == 0) { // Verifica si hay estudiantes
        printf("Aún no existen estudiantes.\n");
        return;
    }
    
    int i, id; 
    bool encontrado; // Para verificar la existencia del estudiante

    // Solicitar ID
    printf("Ingrese el ID del estudiante: ");
    scanf("%d",&id);

    i = verificarEstudiante(id, &encontrado); // Usar la funcion verificarEstudiante para buscar coincidencia
    if(encontrado){ // Si se encuentra al estudiante (encontrado = true), se imprimen sus datos
        imprimirAtributos(&estudiantes[i]);
    }
} // Fin

// Función para eliminar a un estudiante
void eliminarEstudiante() {
    int IDBuscar, si, indice;
    bool encontrado; // Para verificar la existencia del estudiante

    if (num_estudiantes == 0) { // Verificar si hay estudiantes
        printf("Aún no existen estudiantes.\n");
    } else {
        // Solicitar ID
        printf("Ingrese el ID del estudiante: \n");
        scanf("%d",&IDBuscar);
        indice = verificarEstudiante(IDBuscar, &encontrado); // Usar la funcion verificarEstudiante para buscar coincidencia, return i o -1
        
        if(encontrado) {
            // Sobrescribir estudiante, todos los estudiantes se mueven un lugar hacía atrás en el arreglo
            for (int j = indice; j < num_estudiantes - 1; j++) { 
                estudiantes[j] = estudiantes[j + 1];
            }
                
            num_estudiantes--; // Decrementar el número de estudiantes
                
            printf("Estudiante eliminado. El número de estudiantes actual es: %d\n", num_estudiantes);

            // Reiterar
            printf("¿Quiere eliminar otro estudiante? (Sí: 1, No: presione cualquier otro número\n");
            scanf("%d",&si);
            if(si == 1) {
                eliminarEstudiante();
            }
        }
    }
} // Fin

// Función para mostrar la lista de estudiantes ordenada
void mostrarEstudiantes() {
    if (num_estudiantes == 0) { // Verifica si hay estudiantes
       printf("Aún no existen estudiantes.\n");
       return;
    }

    Estudiante copiaNombres[num_estudiantes], copiaID[num_estudiantes], copiaPromedio[num_estudiantes];
    Estudiante temp; // Variable temporal para el intercambio
    int menuMostrar, i, j;

    do {
        // Imprimir menú de opciones
        printf("\nSeleccione una categoría: \n");
        printf("1. Mostrar por nombre (a - z)\n");
        printf("2. Mostrar por ID\n");
        printf("3. Mostrar por promedio\n");
        printf("4. Salir\n");
        scanf("%d", &menuMostrar);

        switch (menuMostrar) {
            case 1: 
                // Copiar el arreglo para no editar el original
                for (i = 0; i < num_estudiantes; i++) {
                    copiaNombres[i] = estudiantes[i];
                }
                // Ordenar a los estudiantes por orden alfabético
                for (i = 0; i < num_estudiantes - 1; i++) {
                    for (j = 0; j < num_estudiantes - i - 1; j++) {
                        if (strcmp(copiaNombres[j].nombre, copiaNombres[j + 1].nombre) > 0) {
                            temp = copiaNombres[j];
                            copiaNombres[j] = copiaNombres[j + 1];
                            copiaNombres[j + 1] = temp;
                        }
                    }
                } // Imoprimir estudiantes
                for (i = 0; i < num_estudiantes; i++) {
                    printf("\n- Estudiante no.%d -\n", i + 1);
                    imprimirAtributos(&copiaNombres[i]);
                }
                break;
            case 2:
                // Copiar el arreglo para no editar el original
                for (i = 0; i < num_estudiantes; i++) {
                    copiaID[i] = estudiantes[i];
                }
                // Ordenar a los estudiantes por ID
                for (i = 0; i < num_estudiantes - 1; i++) {
                    for (j = 0; j < num_estudiantes - i - 1; j++) {
                        if (copiaID[j].ID > copiaID[j + 1].ID) {
                            temp = copiaID[j];
                            copiaID[j] = copiaID[j + 1];
                            copiaID[j + 1] = temp;
                        }
                    }
                } // Imprimir estudiantes
                for (i = 0; i < num_estudiantes; i++) {
                    printf("\n- Estudiante no.%d -\n", i + 1);
                    imprimirAtributos(&copiaID[i]);
                }
                break;
            case 3: 
                // Copiar el arreglo para no editar el original
                for (i = 0; i < num_estudiantes; i++) {
                    copiaPromedio[i] = estudiantes[i];
                }
                // Ordenar a los estudiantes por promedio
                for (i = 0; i < num_estudiantes - 1; i++) {
                    for (j = 0; j < num_estudiantes - i - 1; j++) {
                        if (copiaPromedio[j].promedio < copiaPromedio[j + 1].promedio) {
                            temp = copiaPromedio[j];
                            copiaPromedio[j] = copiaPromedio[j + 1];
                            copiaPromedio[j + 1] = temp;
                        }
                    }
                } // Imprimir estudiantes
                for (i = 0; i < num_estudiantes; i++) {
                    printf("\n- Estudiante no.%d -\n", i + 1);
                    imprimirAtributos(&copiaPromedio[i]);
                }
                break;
            case 4:
                printf("Saliste del menú de mostrar estudiantes.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (menuMostrar != 4);
} // Fin

/// Función para mostrar estadísticas
void mostrarEstadisticas() {
    if (num_estudiantes == 0) { // Verifica si hay estudiantes
        printf("Aún no existen estudiantes.\n");
        return;
    }

    int menuEstadisticas, aprobados = 0, reprobados = 0;
    float promedioGeneral = 0.0;

    do {
        // Imprimer menú de elección
        printf("\nSeleccione una Estadística: \n");
        printf("1. Mostrar número de estudiantes\n");
        printf("2. Mostrar promedio general\n");
        printf("3. Mostrar total de aprobados y reprobados\n");
        printf("4. Salir\n");
        scanf("%d", &menuEstadisticas);

        switch (menuEstadisticas) {
            case 1:
                // Mostrar el número actual de estudiantes
                printf("El número de estudiantes actual es: %d\n", num_estudiantes);
                break;

            case 2:
                // Calcular el promedio general
                promedioGeneral = 0.0; // Reiniciar la variable
                for (int i = 0; i < num_estudiantes; i++) {
                    promedioGeneral += estudiantes[i].promedio;
                }
                promedioGeneral /= num_estudiantes; // Dividir entre el número de estudiantes

                printf("El promedio general actual es: %.2f\n", promedioGeneral);
                break;

            case 3:
                // Calcular aprobados y reprobados
                for (int i = 0; i < num_estudiantes; i++) {
                    if (estudiantes[i].promedio >= 75.0) { // Considerar como aprobado si el promedio es mayor o igual 75
                        aprobados++;
                    } else {
                        reprobados++;
                    }
                }

                printf("Estudiantes aprobados: %d\n", aprobados);
                printf("Estudiantes reprobados: %d\n", reprobados);
                break;
            case 4:
                // Salir del menú
                printf("Saliendo del menú de estadísticas.\n");
                break;

            default:
                // Manejo de opciones no válidas
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (menuEstadisticas != 4); // Repetir hasta que el usuario elija salir
} // Fin