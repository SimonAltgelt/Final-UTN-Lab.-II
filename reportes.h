#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void reportes();

//1 LISTAR la cant. de jugadores de cada uno de los claustros inscriptos este año
void listarJugadoresPorClaustro();

//2 GENERAR archivo con los deportes que tengan un nivel de dificultad 2
// cada registro debe tener ID, nombre y tipo del deporte.
void archivoDeportesConDificultadDos();

//3 INFORMAR el mes de este año con MAYOR cantidad de jugadores inscriptos
void mesConMayorCantidadInscriptos();

//4 INFORMAR el mes de este año con MENOR cantidad de jugadores inscriptos
void mesConMenorCantidadInscriptos();

void reportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES "<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1) LISTAR CANT JUGADORES X CLAUSTRO ESTE ANIO"<<endl;
        cout<<"2) GENERAR ARCHIVO CON DEPORTES QUE TENGAN NIVEL DE DIF. 2" <<endl;
        cout<<"3) INFORMAR EL MES DE ESTE ANIO CON MAYOR CANT INSCRIPTOS"<<endl;
        cout<<"4) INFORMAR EL MES DE ESTE ANIO CON MENOR CANT INSCRIPTOS"<<endl;
        cout<<"5) INFORMAR EL/LOS DEPORTES SIN INSCRIP. ESTE ANIO"<<endl;
        cout<<"6) GENERAR ARCHIVO CON JUGADORES QUE PARTICIPEN EN EQUIPOS DE NIVEL INCIAL"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: listarJugadoresPorClaustro();
                break;
            case 2: archivoDeportesConDificultadDos();
                break;
            case 3: mesConMayorCantidadInscriptos();
                break;
            case 4: mesConMenorCantidadInscriptos();
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:cout<<"Volviendo al menu principal..."<<endl;
                return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
}

/// 1 ///
void listarJugadoresPorClaustro(){
    ArchivoJugador archiJugador("Jugadores.dat");
    int cantJugador = archiJugador.contarRegistros();
    Jugador jug;

    int vClaustro[4]={0};
    int cantClaustros=4;

    for(int i=0; i<cantJugador; i++){
        jug=archiJugador.leerRegistro(i);
        if(jug.getfechaInscripcion().getAnio()==2022 && jug.getEstado()==true){
            //no va a guardar ninguno porque no hay ninguno en 2024
            vClaustro[jug.getClaustro()-1]++;
        }
    }
    cout<<"LA CANTIDAD DE JUGADORES INSCRIPTOS POR CLAUSTRO ES:"<<endl;
    for(int i=0;i<cantClaustros;i++){
        cout<<"CLAUSTRO "<<i+1<<": "<<vClaustro[i]<<endl;
    }
}

/// 2 ///
class puntoDos{
 private:
    int ID;
    char nombre[30];
    int tipo;
 public:
    void setID(int d){ID=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(int t){tipo=t;}
};

class ArchivoDificultadDos{
 private:
    char nombre[30];
 public:
bool escribirRegistro(puntoDos reg){
    FILE *p;
    p=fopen("PuntoDos.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}
};

void archivoDeportesConDificultadDos(){
    ArchivoDeporte archiDeportes("Deportes.dat");
    int cantDeportes=archiDeportes.contarRegistros();

    ArchivoTipoDeportes archiTipoDeportes("TipodeDeporte.dat");
    int cantTipoDeporte=archiTipoDeportes.contarRegistros();

    Deporte depo;
    TipoDeportes tipo;
    puntoDos p2;
    ArchivoDificultadDos archiResultado;

    for(int i=0; i<cantDeportes; i++){
        depo=archiDeportes.leerRegistro(i);
        for(int j=0;j<cantTipoDeporte;j++){
            tipo=archiTipoDeportes.leerRegistro(j);

            if(depo.getTipo()==tipo.getID() && tipo.getDificultad()==2 && depo.getEstado()==true){
                p2.setID(depo.getID());
                p2.setNombre(depo.getNombre());
                p2.setTipo(depo.getTipo());
                archiResultado.escribirRegistro(p2);
            }
        }
    }
}

/// 3 ///
void mesConMayorCantidadInscriptos(){
    const int meses=12;
    int vMeses[meses]={0};

    ArchivoJugador archiJug("Jugadores.dat");
    int cantJug=archiJug.contarRegistros();
    Jugador jug;

    for(int i=0;i<cantJug;i++){
        jug=archiJug.leerRegistro(i);

        if(jug.getfechaInscripcion().getAnio()==2021 && jug.getEstado()==true){
            vMeses[jug.getfechaInscripcion().getMes()-1]++;
        }
    }

    for (int i = 0; i < meses; i++) {
        cout << "Inscripciones para el mes " << i + 1 << ": " << vMeses[i] << endl;
    }

    //encontar el mes con mas inscriptos
    int maximo=vMeses[0];
    int mesMayorInscripcion=1;
    for(int i=0;i<meses;i++){
        if(vMeses[i]>0 && vMeses[i]>maximo){
            maximo=vMeses[i];
            mesMayorInscripcion=i+1;
        }
    }
    cout<<"El mes de este anio con mayor inscripciones fue: "<<mesMayorInscripcion<<endl;
}

/// 4 ///
void mesConMenorCantidadInscriptos(){
    const int meses=12;
    int vMeses[meses]={0};

    ArchivoJugador archiJug("Jugadores.dat");
    int cantJug=archiJug.contarRegistros();
    Jugador jug;

    for(int i=0;i<cantJug;i++){
        jug=archiJug.leerRegistro(i);

        if(jug.getfechaInscripcion().getAnio()==2021 && jug.getEstado()==true){
            vMeses[jug.getfechaInscripcion().getMes()-1]++;
        }
    }

    for (int i = 0; i < meses; i++) {
        cout << "Inscripciones para el mes " << i + 1 << ": " << vMeses[i] << endl;
    }

    //encontar el mes con menos inscriptos diferente a 0 (no lo pide pero yo lo hice asi, distinto a 0).
    int minimo=9999999;
    int mesMenorInscripcion=1;
    for(int i=0;i<meses;i++){
        if(vMeses[i]>0 && vMeses[i]<minimo){
            minimo=vMeses[i];
            mesMenorInscripcion=i+1;
        }
    }
    cout<<"El mes de este anio con menor inscripciones fue: "<<mesMenorInscripcion<<endl;
}



#endif // REPORTES_H_INCLUDED
