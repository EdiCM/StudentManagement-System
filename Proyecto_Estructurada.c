#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
void grafica();
void cargando();
void registrar();
void mostrar();
void buscar();
void borrar();
void salir();


int ocupados=0;


struct agenda // nombre de la estructura
{ // inicio de la estructura
    struct alumno{
        char nombre[40], domicilio[30], fracc[30], cp[6], ciudad[25];
        char telefono[20], e_m[20], notas[20], curp[15], edad[10]}alum;
    struct materia{
        char calendario[10], procedencia[40], turno[15], hobbie[50], escuela[20];
        char codigo[12], semestre[5], promedio[8], carrera[30], egreso[10]}mate;
}ag[10]; //Alias



int main(){
system("COLOR 80");//FUNCIÓN COLOR FONDO GRIS Y LETRAS NEGRAS
int contraUser, contrasena=123, contadorContra=1,opcionmenu=0;
setlocale(LC_ALL, "spanish"); //Para que se acepten acentos y la ñ en el programa tanto en salida como en entrada
SetConsoleCP(1252);
SetConsoleOutputCP(1252);
//decoración de inicio (pantalla grafica que es funcion, la de cargando sistema)

cargando();
printf("\n\n\n\n\n\t\t\t\t\tIngrese la clave de acceso: "); scanf("%i",&contraUser);
while(contraUser!=contrasena && contadorContra<=3){ //Entra aqui porque el usuario puso mal la contraseña la primera vez
    fflush(stdin);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t######################################################");
    printf("\n\n\t\t\t\t\t\t  Contraseña incorrecta, este es tu intento número %i",contadorContra);
    printf("\n\n\t\t\t\t\t\t######################################################");
    sleep(2);
    cargando();
    printf("\n\n\n\n\n\t\t\t\t\tIngrese la clave de acceso: "); scanf("%i",&contraUser);
    contadorContra++;
    if(contadorContra>3 && contraUser!=contrasena){
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t¡LO SENTIMOS :c!\n\n\n\t\t\tHas superado el número de intentos. Inténtalo en otro momento\n\n\n");
        exit(0);}} //Se ingreso mal la contraseña en el tercer y ultimo intento y muestra este mensaje
cargando();
grafica();

do{ //Se entra aquí si la contraseña fue correcta ya sea desde el inicio o en alguno de los intentos.
    cargando();
    fflush(stdin);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\t\t\t\t\t\t             MENÚ DE OPCIONES             ");
    printf("\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\n\t\t\t\t\t1.- REGISTRAR\n\t\t\t\t\t2.- MOSTRAR\n\t\t\t\t\t3.- BUSCAR\n\t\t\t\t\t4.- BORRAR\n\t\t\t\t\t5.- SALIR");
    printf("\n\n\n\t\t\t\t\t\t Elige una opción: ");scanf("%i",&opcionmenu);
    printf("\n\n\n\t\t\t\t\t\t      *****************************");
    printf("\n\t\t\t\t\t\t\t Has elegido la opción %i.\n",opcionmenu);sleep(1);
    switch(opcionmenu){
        case 1:{
            registrar();
            break;}
        case 2:{
            mostrar();
            break;}
        case 3:{
            buscar();
            break;}
        case 4:{
            borrar();
            break;}
        case 5:{
            salir();
            break;}
        default:{

        }
    }
}while(opcionmenu!=5);
return 0;}



void registrar(){//Función registrar para capturar a nuevos alumnos
    int registrados=0,band=1;
    system("cls");
    if(ocupados<10){ //Primero ve si quedan espacios o ya llego al límite del vector
        do{
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
        printf("\n\t\t\t\t\t\t             1.- REGISTRAR             ");
        printf("\n\t\t\t\t\t----------------------------------------------------------");
        printf("\n\n\t\t\t\t\t\t A cuántas personas quieres registrar?: ");scanf("%i",&registrados); //Se elige cuantas personas en esa ocasión vamos a meter al programa
        if(registrados<=(10-ocupados)){ //Si los que queremos registrar aun tienen espacio disponible en el tamaño del vector entran aquí
            for(int i=0;i<registrados;i++){
                printf("\n\t\t\t\t\t\t\t     REGISTRO [%i] ",i+1);
                printf("\n\n\t\t\t\t\t\t\t    ~_~_ALUMNOS_~_~ "); //Se guarda cada posición hasta terminar con el número de alumnos que elegimos guardar
                fflush(stdin);printf("\n\n\t\t\t\t NOMBRE: ");gets(ag[ocupados].alum.nombre); //Se pone entre los corchetes la variable ocupados porque va a aumentar de 1 en 1 cada vez que entre un nuevo alumno hasta que su límite sea 10
                fflush(stdin);printf("\n\t\t\t\t DOMICILIO: ");gets(ag[ocupados].alum.domicilio);//DATOS DEL ALUMNO
                fflush(stdin);printf("\n\t\t\t\t COLONIA: ");gets(ag[ocupados].alum.fracc);
                fflush(stdin);printf("\n\t\t\t\t CÓDIGO POSTAL: ");gets(ag[ocupados].alum.cp);
                fflush(stdin);printf("\n\t\t\t\t CIUDAD: ");gets(ag[ocupados].alum.ciudad);
                fflush(stdin);printf("\n\t\t\t\t TELÉFONO: ");gets(ag[ocupados].alum.telefono);
                fflush(stdin);printf("\n\t\t\t\t E_MAIL: ");gets(ag[ocupados].alum.e_m);
                fflush(stdin);printf("\n\t\t\t\t NOTAS: ");gets(ag[ocupados].alum.notas);
                fflush(stdin);printf("\n\t\t\t\t CURP: ");gets(ag[ocupados].alum.curp);
                fflush(stdin);printf("\n\t\t\t\t EDAD: ");gets(ag[ocupados].alum.edad);
                fflush(stdin);printf("\n\n\t\t\t\t\t\t\t    ~_~_MATERIA_~_~");//DATOS DE LA MATERIA
                fflush(stdin);printf("\n\n\t\t\t\t CALENDARIO: ");gets(ag[ocupados].mate.calendario);
                fflush(stdin);printf("\n\t\t\t\t ESCUELA DE PROCEDENCIA: ");gets(ag[ocupados].mate.procedencia);
                fflush(stdin);printf("\n\t\t\t\t TURNO: ");gets(ag[ocupados].mate.turno);
                fflush(stdin);printf("\n\t\t\t\t HOBBIE: ");gets(ag[ocupados].mate.hobbie);
                fflush(stdin);printf("\n\t\t\t\t ESCUELA: ");gets(ag[ocupados].mate.escuela);
                fflush(stdin);printf("\n\t\t\t\t CÓDIGO: ");gets(ag[ocupados].mate.codigo);
                fflush(stdin);printf("\n\t\t\t\t SEMESTRE: ");gets(ag[ocupados].mate.semestre);
                fflush(stdin);printf("\n\t\t\t\t PROMEDIO: ");gets(ag[ocupados].mate.promedio);
                fflush(stdin);printf("\n\t\t\t\t CARRERA: ");gets(ag[ocupados].mate.carrera);
                fflush(stdin);printf("\n\t\t\t\t EGRESO: ");gets(ag[ocupados].mate.egreso);
                fflush(stdin);ocupados++;band=0;system("cls");}}//aumenta la variable ocupados cada vez que se cicla el for, la bandera cambia a un 0 para que deje de entrar en el do...while ya que si no no va a volver al menú principal
            else{
                system("cls");
                printf("\n\n\n\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\t\t\t\tNO HAY ESPACIO ACTUALMENTE, TE QUEDAN %i POSICIONES",10-ocupados);
                printf("\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                sleep(2);//Si elegimos registrar a más personas de las que nos quedan en espacios entonces nos sale este mensaje para decirnos cuántas posiciones máximo exactas nos quedan por llenar
                }
        }while(band==1);
                }
    else{//Si llego al límite de registros debemos eliminar algunos o ya no podremos capturar a más alumnos
        system("cls");
        printf("\n\n\n\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\n\t\t\tNO HAY ESPACIO DISPONIBLE...");
        printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        sleep(2);}}



void mostrar(){//Función de mostrar todos los registros completos
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\t\t\t\t\t\t             2.- MOSTRAR             ");
    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
    sleep(1);
    if(ocupados>0){//Se revisa si se han llenado datos de captura anteriormente, si es mayor a 0 es porque si hay datos que mostrar
    for(int i=0;i<ocupados;i++){//For para ciclar y mostrar uno por uno los registros completos que se tengan hasta el momento
        printf("\n\n\t\t\t\t\t\t\t     ALUMNO [%i] ",i+1);
        printf("\n\n\t\t\t\t==========================================================================");
        printf("\n\t\t\t\t\t DATOS PERSONALES");
        Sleep(100);printf("\t |\t\tDATOS ACADÉMICOS");//DATOS DE LA MATERIA
        printf("\n\t\t\t\t==========================================================================");
        Sleep(100);printf("\n\t\t\t\t -NOMBRE: ");puts(ag[i].alum.nombre);//Usamos la función puts y ponemos entre los corchetes la i porque va a mostrarlos en orden segun los registramos desde el primero hasta el último
        Sleep(100);printf("\t\t\t\t\t\t\t\t   -CALENDARIO: ");puts(ag[i].mate.calendario);//no podriamos poner en los corchetes el ocupados porque no metemos datos, sino que solo los leemos. No modificaremos ocupados solo mostraremos
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -DOMICILIO: ");puts(ag[i].alum.domicilio);//Usamos un sleep corto para darle más presentación cuando se muestre en pantalla
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -ESCUELA DE PROCEDENCIA: ");puts(ag[i].mate.procedencia);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -COLONIA: ");puts(ag[i].alum.fracc);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -TURNO: ");puts(ag[i].mate.turno);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -CÓDIGO POSTAL: ");puts(ag[i].alum.cp);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -HOBBIE: ");puts(ag[i].mate.hobbie);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -CIUDAD: ");puts(ag[i].alum.ciudad);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -ESCUELA: ");puts(ag[i].mate.escuela);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -TELÉFONO: ");puts(ag[i].alum.telefono);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -CÓDIGO: ");puts(ag[i].mate.codigo);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -E_MAIL: ");puts(ag[i].alum.e_m);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -SEMESTRE: ");puts(ag[i].mate.semestre);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -NOTAS: ");puts(ag[i].alum.notas);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -PROMEDIO: ");puts(ag[i].mate.promedio);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -CURP: ");puts(ag[i].alum.curp);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -CARRERA: ");puts(ag[i].mate.carrera);
        printf("\t\t\t\t|------------------------------------------------------------------------|");
        Sleep(100);printf("\n\t\t\t\t -EDAD: ");puts(ag[i].alum.edad);
        Sleep(100);printf("\t\t\t\t\t\t\t\t  -EGRESO: ");puts(ag[i].mate.egreso);
        printf("\t\t\t\t==========================================================================");
        printf("\n\n\t\t\t\t   Presiona cualquier tecla para continuar con el siguiente registro.");//Para pasar al siguiente registro (ya que se limpiara pantalla) usamos la función getch para que el cliente elija en qué momento proseguir mostrando los datos
        getch();
        system("cls");
    }}
    else{//Si no hay datos guardados nos mostrara que no hemos registrado a nadie y nos regresara después del getch al menú principal para hacerlo.
        printf("\n\n\n\t\t\t\t\t\t    ¡NO HAS REGISTRADO A NINGÚN ALUMNO!\n\n\t\t\t\t\t\t    CAPTURA DATOS Y REGRESA MÁS TARDE.");
        sleep(1);
        printf("\n\n\n\n\t\t\t\t    Presiona cualquier tecla para continuar con el siguiente registro.");
        getch();
    }
}


void buscar(){//Función de buscar ya sea un campo o un registro completo usando el código y el nombre
    int aquien=0,opcionbuscar=0,opcioncampo=0;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\t\t\t\t\t\t              3.- BUSCAR             ");
    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
    sleep(1);
    if(ocupados>0){
        fflush(stdin);
        printf("\n\n\t\t\t\t\t\t\t Tu registro actual es: \n");
        for(int i=0;i<ocupados;i++){
            printf("\n\t\t\t\t\t[%i]. ",i+1);
            puts(ag[i].alum.nombre);}
        printf("\n\n\t\t\t\t\tIngresa el número del registro sobre el que deseas buscar: ");scanf("%i",&aquien);
        if(aquien>ocupados){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\t#############################################");
            printf("\n\n\t\t\t\tNO EXISTE ESE REGISTRO");
            printf("\n\n\t\t\t#############################################");
            sleep(2);
        }
        else{
            printf("\n\n\n\t\t\t\t\t\t\tElegiste el registro número %i",aquien);
            printf("\n\n\t\t\t\tPresiona 1 para imprimir todo el registro o 2 para imprimir un campo solamente: ");scanf("%i",&opcionbuscar);
            switch(opcionbuscar){
                case 1:{
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                    printf("\n\t\t\t\t\t\t           BÚSQUEDA POR REGISTRO             ");
                    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
                    sleep(1);
                    printf("\n\n\t\t\t\t\t\t\t        ALUMNO [%i] ",aquien);
                    printf("\n\n\t\t\t\t==========================================================================");
                    printf("\n\t\t\t\t\t DATOS PERSONALES");
                    Sleep(100);printf("\t |\t\tDATOS ACADÉMICOS");
                    printf("\n\t\t\t\t==========================================================================");
                    Sleep(100);printf("\n\t\t\t\t -NOMBRE: ");puts(ag[aquien-1].alum.nombre);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t-CALENDARIO: ");puts(ag[aquien-1].mate.calendario);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -DOMICILIO: ");puts(ag[aquien-1].alum.domicilio);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -ESCUELA DE PROCEDENCIA: ");puts(ag[aquien-1].mate.procedencia);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -COLONIA: ");puts(ag[aquien-1].alum.fracc);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -TURNO: ");puts(ag[aquien-1].mate.turno);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -CÓDIGO POSTAL: ");puts(ag[aquien-1].alum.cp);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -HOBBIE: ");puts(ag[aquien-1].mate.hobbie);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -CIUDAD: ");puts(ag[aquien-1].alum.ciudad);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -ESCUELA: ");puts(ag[aquien-1].mate.escuela);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -TELÉFONO: ");puts(ag[aquien-1].alum.telefono);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -CÓDIGO: ");puts(ag[aquien-1].mate.codigo);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -E_MAIL: ");puts(ag[aquien-1].alum.e_m);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -SEMESTRE: ");puts(ag[aquien-1].mate.semestre);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -NOTAS: ");puts(ag[aquien-1].alum.notas);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -PROMEDIO: ");puts(ag[aquien-1].mate.promedio);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -CURP: ");puts(ag[aquien-1].alum.curp);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -CARRERA: ");puts(ag[aquien-1].mate.carrera);
                    printf("\t\t\t\t|------------------------------------------------------------------------|");
                    Sleep(100);printf("\n\t\t\t\t -EDAD: ");puts(ag[aquien-1].alum.edad);
                    Sleep(100);printf("\t\t\t\t\t\t\t\t  -EGRESO: ");puts(ag[aquien-1].mate.egreso);
                    printf("\n\t\t\t\t==========================================================================");
                    printf("\n\n\t\t\t\t   Presiona cualquier tecla para continuar con el siguiente registro.");
                    getch();
                    break;}
                case 2:{
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                    printf("\n\t\t\t\t\t\t             BÚSQUEDA POR CAMPO             ");
                    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
                    sleep(1);
                    printf("\n\n\t\t\t\t\t\t    CAMPOS DISPONIBLES:");
                    printf("\n\n\t\t\t\t\t1.-NOMBRE\n\t\t\t\t\t2.-DOMICILIO\n\t\t\t\t\t3.-COLONIA\n\t\t\t\t\t4.-CÓDIGO POSTAL\n\t\t\t\t\t5.-CIUDAD");
                    printf("\n\t\t\t\t\t6.-TELÉFONO\n\t\t\t\t\t7.-E_MAIL\n\t\t\t\t\t8.-NOTAS\n\t\t\t\t\t9.-CURP\n\t\t\t\t\t10.-EDAD");
                    printf("\n\t\t\t\t\t11.-CALENDARIO\n\t\t\t\t\t12.-ESCUELA DE PROCEDENCIA\n\t\t\t\t\t13.-TURNO\n\t\t\t\t\t14.-HOBBIE\n\t\t\t\t\t15.-ESCUELA");
                    printf("\n\t\t\t\t\t16.-CÓDIGO\n\t\t\t\t\t17.-SEMESTRE\n\t\t\t\t\t18.-PROMEDIO\n\t\t\t\t\t19.-CARRERA\n\t\t\t\t\t20.-EGRESO");
                    printf("\n\n\t\t\t\tIngresa el número del campo sobre el que deseas buscar: ");scanf("%i",&opcioncampo);
                    switch(opcioncampo){
                        case 1:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             1.- NOMBRE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl nombre del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.nombre);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 2:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             2.- DOMICILIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl domicilio del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.domicilio);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 3:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             3.- COLONIA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa colonia del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.fracc);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 4:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             4.- CÓDIGO POSTAL             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl código postal del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.cp);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 5:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             5.- CIUDAD             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa ciudad del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.ciudad);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 6:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             6.- TELÉFONO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl teléfono del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.telefono);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 7:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             7.- E_MAIL             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl e_mail del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.e_m);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 8:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             8.- NOTAS             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLas notas del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.notas);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 9:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             9.- CURP             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa curp del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.curp);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 10:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             10.- EDAD             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa edad del registro número %i es: ",aquien);
                            puts(ag[aquien-1].alum.edad);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 11:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             11.- CALENDARIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl calendario del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.calendario);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 12:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             12.- ESCUELA DE PROCEDENCIA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa escuela de procedencia del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.procedencia);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 13:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             13.- TURNO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl turno del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.turno);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 14:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             14.- HOBBIE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl hobbie del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.hobbie);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 15:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             15.- ESCUELA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa escuela del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.escuela);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 16:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             16.- CÓDIGO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl código del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.codigo);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 17:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             17.- SEMESTRE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl semestre del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.semestre);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 18:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             18.- PROMEDIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl promedio del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.promedio);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 19:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             19.- CARRERA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tLa carrera del registro número %i es: ",aquien);
                            puts(ag[aquien-1].mate.carrera);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        case 20:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             20.- EGRESO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tEl egreso del registro número %i será en: ",aquien);
                            puts(ag[aquien-1].mate.egreso);
                            printf("\n\t\t\t\t\t\t=========================================");
                            break;
                        }
                        default:{printf("\n\n\t\t\t\t\t ESE NÚMERO DE CAMPO NO EXISTE. INGRESA UNO VÁLIDO");}
                    }
                break;}

                default: printf("\n\n\t\t\t\t\t ESA OPCIÓN NO EXISTE. INGRESA UNA VÁLIDA");
            }}getch();}
        else{//Si no hay datos guardados nos mostrara que no hemos registrado a nadie y nos regresara después del getch al menú principal para hacerlo.
        printf("\n\n\n\t\t\t\t\t\t    ¡NO HAS REGISTRADO A NINGÚN ALUMNO!\n\n\t\t\t\t\t\t    CAPTURA DATOS Y REGRESA MÁS TARDE.");
        sleep(1);
        printf("\n\n\n\n\t\t\t\t    Presiona cualquier tecla para continuar con el siguiente registro.");
        getch();}}


void borrar(){
    int eliminado=0,nomasuno=0,nomasdos=0,opcioncampoo=0;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\t\t\t\t\t\t              4.- BORRAR             ");
    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
    sleep(1);
    if(ocupados==0){
        printf("\n\n\n\t\t\t\t\t\t    ¡NO HAS REGISTRADO A NINGÚN ALUMNO!\n\n\t\t\t\t\t\t    CAPTURA DATOS Y REGRESA MÁS TARDE.");
        sleep(1);
        printf("\n\n\n\n\t\t\t\t    Presiona cualquier tecla para continuar con el siguiente registro.");
        getch();
    }
    else{
        fflush(stdin);

        printf("\n\n\n\t\t\t\t\t\t\t----OPCIONES DE BORRADO----");
        printf("\n\n\n\t\t\t\t\t1.- BORRAR TODOS LOS REGISTROS\n\n\t\t\t\t\t2.- BORRAR UN REGISTRO\n\n\t\t\t\t\t3.- BORRAR POR CAMPO");
        printf("\n\n\n\t\t\t\t\tDigite el número de la operación que desea realizar: ");fflush(stdin);scanf("%i",&eliminado);
        switch(eliminado){
            case 1:{
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                printf("\n\t\t\t\t\t\t       1.- TODOS LOS REGISTROS             ");
                printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
                sleep(1);
                ocupados=0;
                printf("\n\n\t\t    SE HAN BORRADO TODOS LOS REGISTROS. CAPTURA ALUMNOS NUEVAMENTE PARA SEGUIR UTILIZANDO EL PROGRAMA");
                sleep(1);
                printf("\n\n\n\n\t\t\t\t\t      Presiona cualquier tecla para continuar.");
                getch();
                break;}
            case 2:{
                printf("\n\n\t\t\t\t\t\t\t Tu registro actual es: \n");
            for(int i=0;i<ocupados;i++){
                    printf("\n\t\t\t\t\t[%i]. ",i+1);
                    puts(ag[i].alum.nombre);}
                printf("\n\n\t\t\t\t\tDigite el número del registro que desea eliminar: ");scanf("%i",&nomasuno);
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                printf("\n\t\t\t\t\t\t             1.- UN REGISTRO             ");
                printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
                sleep(3);
                ag[nomasuno-1].alum.nombre[0]=0;ag[nomasuno-1].alum.domicilio[0]=0;ag[nomasuno-1].alum.fracc[0]=0;ag[nomasuno-1].alum.cp[0]=0;ag[nomasuno-1].alum.ciudad[0]=0;
                ag[nomasuno-1].alum.telefono[0]=0;ag[nomasuno-1].alum.e_m[0]=0;ag[nomasuno-1].alum.notas[0]=0;ag[nomasuno-1].alum.curp[0]=0;ag[nomasuno-1].alum.edad[0]=0;
                ag[nomasuno-1].mate.calendario[0]=0;ag[nomasuno-1].mate.procedencia[0]=0;ag[nomasuno-1].mate.turno[0]=0;ag[nomasuno-1].mate.hobbie[0]=0;ag[nomasuno-1].mate.escuela[0]=0;
                ag[nomasuno-1].mate.codigo[0]=0;ag[nomasuno-1].mate.semestre[0]=0;ag[nomasuno-1].mate.promedio[0]=0;ag[nomasuno-1].mate.carrera[0]=0;ag[nomasuno-1].mate.egreso[0]=0;
                printf("\n\n\t\t\t\t\t\t   SE HA BORRADO EL REGISTRO NÚMERO %i",nomasuno);
                ocupados=ocupados-1;
                for(int i=nomasuno-1;i<ocupados;i++){
                    ag[i]=ag[i+1];
                }
                sleep(1);
                printf("\n\n\n\n\t\t\t\t\t      Presiona cualquier tecla para continuar.");
                getch();
                break;}
            case 3:{
                system("cls");
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                    printf("\n\t\t\t\t\t\t             BÚSQUEDA POR CAMPO             ");
                    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
                    sleep(1);
                    printf("\n\n\t\t\t\t\t\t    CAMPOS DISPONIBLES:");
                    printf("\n\n\t\t\t\t\t1.-NOMBRE\n\t\t\t\t\t2.-DOMICILIO\n\t\t\t\t\t3.-COLONIA\n\t\t\t\t\t4.-CÓDIGO POSTAL\n\t\t\t\t\t5.-CIUDAD");
                    printf("\n\t\t\t\t\t6.-TELÉFONO\n\t\t\t\t\t7.-E_MAIL\n\t\t\t\t\t8.-NOTAS\n\t\t\t\t\t9.-CURP\n\t\t\t\t\t10.-EDAD");
                    printf("\n\t\t\t\t\t11.-CALENDARIO\n\t\t\t\t\t12.-ESCUELA DE PROCEDENCIA\n\t\t\t\t\t13.-TURNO\n\t\t\t\t\t14.-HOBBIE\n\t\t\t\t\t15.-ESCUELA");
                    printf("\n\t\t\t\t\t16.-CÓDIGO\n\t\t\t\t\t17.-SEMESTRE\n\t\t\t\t\t18.-PROMEDIO\n\t\t\t\t\t19.-CARRERA\n\t\t\t\t\t20.-EGRESO");
                    printf("\n\n\t\t\t\tIngresa el número del campo sobre el que deseas buscar: ");scanf("%i",&opcioncampoo);
                    printf("\n\n\t\t\t\t\t\t\t Tu registro actual es: \n");
                    for(int i=0;i<ocupados;i++){
                        printf("\n\t\t\t\t\t[%i]. ",i+1);
                        puts(ag[i].alum.nombre);}
                    printf("\n\n\t\t\t\t\tDigite el número del registro que desea eliminar: ");scanf("%i",&nomasdos);
                    system("cls");
                    switch(opcioncampoo){
                        case 1:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             1.- NOMBRE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el nombre del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.nombre[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 2:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             2.- DOMICILIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el domicilio del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.domicilio[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 3:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             3.- COLONIA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la colonia del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.fracc[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 4:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             4.- CÓDIGO POSTAL             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el código postal del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.cp[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 5:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             5.- CIUDAD             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la ciudad del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.ciudad[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 6:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             6.- TELÉFONO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el teléfono del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.telefono[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 7:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             7.- E_MAIL             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el e_mail del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.e_m[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 8:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             8.- NOTAS             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borrarron las notas del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.notas[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 9:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             9.- CURP             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la curp del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.curp[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 10:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             10.- EDAD             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la edad del registro número %i",nomasdos);
                            ag[nomasdos-1].alum.edad[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 11:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             11.- CALENDARIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el calendario del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.calendario[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 12:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             12.- ESCUELA DE PROCEDENCIA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la escuela de procedencia del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.procedencia[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 13:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             13.- TURNO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el turno del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.turno[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 14:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             14.- HOBBIE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el hobbie del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.hobbie[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 15:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             15.- ESCUELA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la escuela del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.escuela[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 16:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             16.- CÓDIGO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el código del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.codigo[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 17:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             17.- SEMESTRE             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el semestre del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.semestre[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 18:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             18.- PROMEDIO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el promedio del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.promedio[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 19:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             19.- CARRERA             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró la carrera del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.carrera[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        case 20:{
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
                            printf("\n\t\t\t\t\t\t             20.- EGRESO             ");
                            printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");sleep(1);
                            printf("\n\n\t\t\t\t\t\t=========================================");
                            printf("\n\n\t\t\t\t\t\tSe borró el egreso del registro número %i",nomasdos);
                            ag[nomasdos-1].mate.egreso[0]=0;
                            printf("\n\t\t\t\t\t\t=========================================");
                            getch();
                            break;
                        }
                        default:{printf("\n\n\t\t\t\t\t ESE NÚMERO DE CAMPO NO EXISTE. INGRESA UNO VÁLIDO");}
                    }
                break;}
            }}

    }




void salir(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------");
    printf("\n\t\t\t\t\t\t              5.- SALIR             ");
    printf("\n\t\t\t\t\t----------------------------------------------------------\n\n\n");
    sleep(1);
    printf("\n\n\t\t\t\t\t\t ¡Muchas gracias por usar el programa!\n\n\t\t\t\t\t\tPresiona cualquier tecla para continuar.\n\n\n\n\n");
    getch();
}


void grafica(){
    system("cls");
    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t|      1111¶1                                                           1111¶1                              |\n");
    printf("\t\t|     ¶¶¶¶¶¶¶¶1                                                        ¶¶¶¶¶¶¶¶1                            |\n");
    printf("\t\t|    ¶1¶1¶¶¶¶¶                                                        ¶1¶1¶¶¶¶¶                             |\n");
    printf("\t\t|    ¶¶1 ¶¶¶¶¶¶1         ¶¶¶1 1¶¶1                                   ¶¶1 ¶¶¶¶¶¶1         ¶¶¶1 1¶¶1          |\n");
    printf("\t\t|    1¶¶1 ¶1 1¶¶¶1      ¶1  1¶¶¶¶¶1¶¶                                1¶¶1 ¶1 1¶¶¶1      ¶1  1¶¶¶¶¶1¶¶       |\n");
    printf("\t\t|    ¶1¶1 ¶    ¶¶¶      ¶1    ¶¶¶¶¶11¶                               ¶1¶1 ¶    ¶¶¶      ¶1    ¶¶¶¶¶11¶      |\n");
    printf("\t\t|    ¶  ¶¶1   ¶1¶¶     1¶¶¶     ¶¶¶¶¶¶                               ¶  ¶¶1   ¶1¶¶     1¶¶¶     ¶¶¶¶¶¶      |\n");
    printf("\t\t|   1¶  1¶1   1¶¶¶    1¶1 ¶¶      1¶¶¶¶¶                            1¶  1¶1   1¶¶¶    1¶1 ¶¶      1¶¶¶¶¶    |\n");
    printf("\t\t|   ¶¶   ¶¶    ¶¶1  1¶¶¶   1¶11¶¶¶11¶¶¶¶¶1                          ¶¶   ¶¶    ¶¶1  1¶¶¶   1¶11¶¶¶11¶¶¶¶¶1  |\n");
    printf("\t\t|    ¶¶  1¶    ¶¶  ¶¶1¶     1¶1     1¶¶¶¶¶1                          ¶¶  1¶    ¶¶  ¶¶1¶     1¶1     1¶¶¶¶¶1 |\n");
    printf("\t\t|     ¶¶1 ¶¶ 1¶¶1 ¶¶ ¶       ¶¶     1¶¶¶¶¶¶                           ¶¶1 ¶¶ 1¶¶1 ¶¶ ¶       ¶¶     1¶¶¶¶¶¶ |\n");
    printf("\t\t|      1¶¶¶¶¶¶¶¶  ¶           ¶     ¶  ¶¶¶¶1                           1¶¶¶¶¶¶¶¶  ¶           ¶     ¶  ¶¶¶¶1|\n");
    printf("\t\t|    1¶¶1  ¶¶¶¶¶¶ ¶1          ¶  1¶¶  1¶¶¶¶1                         1¶¶1  ¶¶¶¶¶¶ ¶1          ¶  1¶¶  1¶¶¶¶1|\n");
    printf("\t\t|    ¶     1¶¶¶1   ¶        1¶¶¶¶¶¶¶1¶¶¶¶¶¶                          ¶     1¶¶¶1   ¶        1¶¶¶¶¶¶¶1¶¶¶¶¶¶ |\n");
    printf("\t\t|      1¶¶¶¶¶¶¶¶1 1¶¶¶1    ¶     ¶¶¶¶¶¶¶¶¶                             1¶¶¶¶¶¶¶¶1 1¶¶¶1    ¶     ¶¶¶¶¶¶¶¶¶  |\n");
    printf("\t\t|    1¶¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶11¶¶11 ¶¶¶ -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- ¶11¶¶¶¶11¶¶11 ¶¶¶¶¶¶¶¶¶1     |\n");
    printf("\t\t|   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶¶¶¶¶¶1  ||                                         ||¶¶   ¶¶¶¶¶¶¶¶¶1        ¶¶1   |\n");
    printf("\t\t|1¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶¶¶¶¶¶¶1||        __   __   __         _   __      ||¶¶¶   ¶¶¶¶¶¶¶¶¶¶1        1¶¶ |\n");
    printf("\t\t| ¶¶¶¶¶¶¶1¶1¶¶¶¶¶¶¶¶  ¶¶¶¶¶1    ¶¶||       |__| /  _ |__ |-_  | | | |__|     ||¶¶¶  ¶¶¶¶¶1    ¶¶1        1¶ |\n");
    printf("\t\t|   1¶¶¶¶¶111¶¶11¶¶¶1 ¶¶¶¶1 1¶¶¶11||       |  | -__/ |__ |  -_| |_/ |  |     ||¶¶¶1 ¶¶¶¶1 1¶¶¶11¶¶¶  1¶¶¶1  |\n");
    printf("\t\t|      ¶¶¶¶¶¶¶¶¶¶¶¶¶¶ 1¶  ¶¶¶¶¶¶¶¶||                                         ||¶¶¶¶ 1¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶1      |\n");
    printf("\t\t|       ¶¶¶¶¶¶11¶¶¶¶1 ¶1 ¶¶¶¶¶¶¶¶¶||       __                     __   __    ||¶¶¶1 ¶1 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1¶¶1  |\n");
    printf("\t\t|  ¶¶1   ¶¶¶¶¶¶¶¶¶¶¶ ¶¶ 1¶¶¶¶1¶¶¶¶||      |__||   |  ||-_-||-_  ||  | |__    ||¶¶¶ ¶¶ 1¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶1¶¶ |\n");
    printf("\t\t|  1¶¶¶¶1¶¶¶¶¶¶¶¶¶¶1¶¶  1¶¶¶¶¶¶¶¶¶||      |  ||__ |__||   ||  -_||__|  __|   ||¶¶1¶¶  1¶¶¶¶¶¶¶¶¶11¶¶¶¶¶¶¶1  |\n");
    printf("\t\t|   ¶¶¶¶¶¶¶¶¶11¶¶¶¶¶1 1¶¶¶¶¶¶¶¶¶1¶||                                         ||¶¶¶1 1¶¶¶¶¶¶¶¶¶1¶¶¶¶¶¶¶¶¶1   |\n");
    printf("\t\t|   ¶¶¶¶¶¶¶¶¶¶1  1¶¶11     ¶¶¶¶¶¶¶||_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _||1¶¶11     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶     |\n");
    printf("\t\t|  1¶¶¶¶1¶¶¶¶¶¶1 1¶¶        ¶¶¶¶¶¶¶- - - - - - - - - - - - - - - - - - - - - - 1¶¶        ¶¶¶¶¶¶¶¶¶¶¶¶      |\n");
    printf("\t\t|  1¶¶¶¶11¶¶¶¶¶1 ¶¶   1¶¶¶¶¶¶¶¶¶¶¶¶¶¶1                             1¶¶¶¶11¶¶¶¶¶1 ¶¶   1¶¶¶¶¶¶¶¶¶¶¶¶¶¶1      |\n");
    printf("\t\t|  1¶¶¶¶¶¶ ¶¶¶¶11¶ 1¶¶¶¶¶¶¶¶¶¶¶¶¶                                  1¶¶¶¶¶¶ ¶¶¶¶11¶ 1¶¶¶¶¶¶¶¶¶¶¶¶¶           |\n");
    printf("\t\t|   ¶¶¶¶¶¶¶¶¶¶11¶1¶¶¶¶¶¶¶¶¶1¶¶¶¶¶¶1                                 ¶¶¶¶¶¶¶¶¶¶11¶1¶¶¶¶¶¶¶¶¶1¶¶¶¶¶¶1         |\n");
    printf("\t\t|   1¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶1¶1111¶¶¶¶¶¶1                               1¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶1¶1111¶¶¶¶¶¶1       |\n");
    printf("\t\t|      ¶¶¶1 ¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1¶¶¶                                 ¶¶¶1 ¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1¶¶¶      |\n");
    printf("\t\t|           ¶¶¶     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1                                        ¶¶¶     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1        |\n");
    printf("\t\t|          ¶¶¶       1¶¶¶¶¶¶¶¶¶¶1                                          ¶¶¶       1¶¶¶¶¶¶¶¶¶¶1           |\n");
    printf("\t\t|         1¶¶                                                             1¶¶                               |\n");
    printf("\t\t|         ¶1                                                               ¶1                               |\n");
    printf("\t\t|        ¶¶                                                               ¶¶                                |\n");
    printf("\t\t|       ¶¶                                                               ¶¶                                 |\n");
    printf("\t\t|      ¶¶                                                               ¶¶                                  |\n");
    printf("\t\t|      ¶¶                                                               ¶¶                                  |\n");
    printf("\t\t|     ¶¶                                                               ¶¶                                   |\n");
    printf("\t\t|    1¶1                                                              1¶1                                   |\n");
    printf("\t\t|    ¶¶                                                               ¶¶                                    |\n");
    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t     NOMBRE: EDITH CABRAL MEDINA   CÓDIGO: 219553698  VERSIÓN 2.0  NO. DE LISTA: 4  ESCUELA: UDG-CUCEI\n");
    printf("\t\t  PROGRAMACIÓN ESTRUCTURADA  PROYECTO FINAL: AGENDA DE ALUMNOS  HORARIO: L-M-V 13 A 14:55 hrs  SECCIÓN D02");
    sleep(5);
}


void cargando(){
    for(int i=0;i<5;i++){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        printf("\n\n\n\t\t\t\t\t\t\t\t CARGANDO SISTEMA...");
        printf("\n\n\n\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        Sleep(250);}}
