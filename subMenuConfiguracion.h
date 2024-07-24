#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void subMenuConfiguracion();
void copiaSeguridadDeportes();
void copiaSeguridadJugadores();
void restaurarArchivoJugadores();
void restaurarArchivoDeportes();
bool establecerDatosdeInicio();

void subMenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"4) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"5) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
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
            case 5: establecerDatosdeInicio();
                    cout<<"DATOS DE INICIO ESTABLECIDOS CORRECTAMENTE"<<endl;
                break;
            case 0: cout<<"Volviendo al menu principal..."<<endl;
                return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
}

void copiaSeguridadDeportes(){
    ArchivoDeporte archiDepo("Deportes.dat");
    ArchivoDeporte bkpDepo("Deportes.bkp");
    Deporte depo;
    /// aca limpio el archivo para que no repitan los mismos datos.
    /// osea los sobreescribimos.
    bkpDepo.limpiarArchivo();

    int cantidadDepo=archiDepo.contarRegistros();
    for(int i=0;i<cantidadDepo;i++){
        depo=archiDepo.leerRegistro(i);
        bkpDepo.agregarRegistro(depo);
    }
}

void copiaSeguridadJugadores(){
    ArchivoJugador archiJug("Jugadores.dat");
    ArchivoJugador bkpJug("Jugadores.bkp");
    Jugador jug;
    /// aca limpio el archivo para que no repitan los mismos datos.
    /// osea los sobreescribimos.
    bkpJug.limpiarArchivo();

    int cantidadJug=archiJug.contarRegistros();
    for(int i=0;i<cantidadJug;i++){
        jug=archiJug.leerRegistro(i);
        bkpJug.agregarRegistro(jug);
    }
}

void restaurarArchivoDeportes(){
    ArchivoDeporte archiDepo("Deportes.dat");
    ArchivoDeporte bkpDepo("Deportes.bkp");
    Deporte depo;
    /// aca al reves, limpio el .dat para llenarlo con el bkp
    archiDepo.limpiarArchivo();

    int cantidadDepo=archiDepo.contarRegistros();
    for(int i=0;i<cantidadDepo;i++){
        depo=archiDepo.leerRegistro(i);
        bkpDepo.agregarRegistro(depo);
    }
}

void restaurarArchivoJugadores(){
    ArchivoJugador archiJug("Jugadores.dat");
    ArchivoJugador bkpJug("Jugadores.bkp");
    Jugador jug;
    /// aca al reves, limpio el .dat para llenarlo con el bkp
    archiJug.limpiarArchivo();

    int cantidadJug=archiJug.contarRegistros();
    for(int i=0;i<cantidadJug;i++){
        jug=archiJug.leerRegistro(i);
        bkpJug.agregarRegistro(jug);
    }
}

bool establecerDatosdeInicio(){
    Deporte deportes;
    Jugador jugador;
    Equipo equipos;
    TipoDeportes tipoDepo;
    FILE *pdeportes, *pdfadeportes;
    FILE *pjugador, *pdfajugador;
    FILE *pequipos, *pdfaequipos;
    FILE *ptipoDepo, *pdfatipoDepo;
   ///1. abrir los archivos que se necesitan
    pdfadeportes=fopen("Deportes.dfa","rb");
    if(pdfadeportes==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Deportes.dfa"<<endl;
        return false;
    }
    pdeportes=fopen("Deportes.dat","wb");
    if(pdeportes==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Deportes.dat"<<endl;
        fclose(pdfadeportes);
        return false;
    }
    pdfajugador=fopen("Jugadores.dfa","rb");
    if(pdfajugador==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Jugadores.dfa"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        return false;
    }
    pjugador=fopen("Jugadores.dat","wb");
    if(pjugador==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Jugadores.dat"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        fclose(pdfajugador);
        return false;
    }
    pdfaequipos=fopen("Equipos.dfa","rb");
    if(pdfaequipos==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Equipos.dfa"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        fclose(pdfajugador);
        fclose(pjugador);
        return false;
    }
    pequipos=fopen("Equipos.dat","wb");
    if(pequipos==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO Equipos.dat"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        fclose(pdfajugador);
        fclose(pjugador);
        fclose(pdfaequipos);
        return false;
    }
    pdfatipoDepo=fopen("TipodeDeporte.dfa","rb");
    if(pdfatipoDepo==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO TipodeDeporte.dfa"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        fclose(pdfajugador);
        fclose(pjugador);
        fclose(pdfaequipos);
        fclose(pequipos);
        return false;
    }
    ptipoDepo=fopen("TipodeDeporte.dat","wb");
    if(ptipoDepo==NULL){
        cout<<"ERROR-2: NO SE PUDO ABRIR EL ARCHIVO TipodeDeporte.dfa"<<endl;
        fclose(pdfadeportes);
        fclose(pdeportes);
        fclose(pdfajugador);
        fclose(pjugador);
        fclose(pdfaequipos);
        fclose(pequipos);
        fclose(pdfatipoDepo);
        return false;
    }

    ///2. traer del disco a la memoria
    while(fread(&deportes,sizeof(Deporte),1,pdfadeportes)==1){
        fwrite(&deportes,sizeof(Deporte),1,pdeportes);
    }
     while(fread(&jugador,sizeof(Jugador),1,pdfajugador)==1){
        fwrite(&jugador,sizeof(Jugador),1,pjugador);
    }
    while(fread(&equipos,sizeof(Equipo),1,pdfaequipos)==1){
        fwrite(&equipos,sizeof(Equipo),1,pequipos);
    }
    while(fread(&tipoDepo,sizeof(TipoDeportes),1,pdfatipoDepo)==1){
        fwrite(&tipoDepo,sizeof(TipoDeportes),1,ptipoDepo);
    }
    ///3. cerrar los archivos
    fclose(pdeportes);
    fclose(pdfadeportes);
    fclose(pjugador);
    fclose(pdfajugador);
    fclose(pequipos);
    fclose(pdfaequipos);
    fclose(ptipoDepo);
    fclose(pdfatipoDepo);
    return true;
}

#endif // SUBMENUCONFIGURACION_H_INCLUDED
