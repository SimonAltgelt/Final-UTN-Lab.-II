#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED




void subMenuConfiguracion();
void copiaSeguridadDeportes();
void copiaSeguridadJugadores();
void restaurarArchivoJugadores();
void restaurarArchivoDeportes();


void subMenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"4) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"5) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: copiaSeguridadJugadores();
                break;
            case 2: copiaSeguridadDeportes();
                break;
            case 3: restaurarArchivoJugadores();
                break;
            case 4: restaurarArchivoDeportes();
                break;
            case 5:
                break;
            case 0:return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
}


void copiaSeguridadDeportes() {

    ArchivoDeporte archivoDeportes("Deportes.dat");


    const char *nombreCopia = "Deportes.bak";
    if (archivoDeportes.copiaSeguridad(nombreCopia)) {
        cout << "Copia de seguridad del archivo de deportes completada." << endl;

        // Mostrar el contenido del archivo copiado
        cout << "Contenido del archivo copiado:" << endl;


        ArchivoDeporte archivoCopia("Deportes.bak");
        archivoCopia.listarRegistros();
    } else {
        cout << "Error al realizar la copia de seguridad del archivo de deportes." << endl;
    }
}


void copiaSeguridadJugadores() {

    ArchivoJugador archivoJugador("Jugadores.dat");


    const char *nombreCopia = "Jugadores.bak";
    if (archivoJugador.copiaSeguridad(nombreCopia)) {
        cout << "Copia de seguridad del archivo de Jugadores completada." << endl;


        cout << "Contenido del archivo copiado:" << endl;
        cout << "PASO A LISTAR EL CONTENIDO DEL ARCHIVO COPIADO:" << endl;


        ArchivoJugador archivoCopia("Jugadores.bak");
        archivoCopia.listarRegistros();
    } else {
        cout << "Error al realizar la copia de seguridad del archivo de jugadores." << endl;
    }
}

void restaurarArchivoJugadores() {
    const char *nombreOriginal = "Jugadores.dat";
    const char *nombreCopia = "Jugadores.bak";


    remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "Restauracion del archivo de jugadores completada." << endl;
    } else {
        cout << "Error al restaurar el archivo de jugadores." << endl;
    }
}

void restaurarArchivoDeportes() {
    const char *nombreOriginal = "Deportes.dat";
    const char *nombreCopia = "Deportes.bak";


    remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "Restauracion del archivo de deportes completada." << endl;
    } else {
        cout << "Error al restaurar el archivo de deportes." << endl;
    }
}


#endif // SUBMENUCONFIGURACION_H_INCLUDED
