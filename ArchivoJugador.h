#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED

#include "clsJugador.h"

class ArchivoJugador{
 private:
    char nombre[30];
 public:
    ArchivoJugador(const char *nombreArchivo){strcpy(nombre, nombreArchivo);}
    const char *getNombre() {return nombre;}
    bool listarRegistros();
    bool agregarRegistro(Jugador);
    int buscarRegistro(int DNI);
    bool buscarRegistroBool(int ID);
    Jugador leerRegistro(int pos);
    bool modificarRegistro(int pos, Jugador reg);
    int contarRegistros();
    bool copiaSeguridad(const char *nombreCopia);
    int cantidadAlumnosPorEquipo(int idEquipo);
};


bool ArchivoJugador::listarRegistros(){
    Jugador reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
return true;
}


bool ArchivoJugador::agregarRegistro(Jugador reg){
    FILE *p=fopen(nombre,"ab");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
return escribio;
}


int ArchivoJugador::buscarRegistro(int DNI){
    Jugador reg;
    FILE *p=fopen(nombre,"rb"); // aca va el ROOT.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.getDNI()==(DNI)){
            fclose(p);
            return cont ;
        }
         cont++ ;
    }
    fclose(p);
return -1;
}


bool ArchivoJugador::buscarRegistroBool(int ID){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.getEstado()==true){
            if(reg.getID()==(ID)){
                fclose(p);
                return true;
            }
        }
    }
    fclose(p);
return false;
}

Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador reg;
    reg.setEstado(false);
    FILE *p=fopen(nombre,"rb"); // aca va el ROOT.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Jugador)*pos,0);
    fread(&reg, sizeof reg, 1,p);
    fclose(p);
    return reg;

    reg.setEstado(false);

return reg;
}


bool ArchivoJugador::modificarRegistro(int pos, Jugador reg){
    FILE *p=fopen(nombre,"rb+"); // Agrega al modo lo que le falta.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Jugador)*pos,0);
    bool escribio=fwrite(&reg, sizeof reg, 1,p);
    fclose(p);

return escribio;
}

int ArchivoJugador::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);

return tam/sizeof(Jugador);
}


bool ArchivoJugador::copiaSeguridad(const char *nombreCopia) {
    FILE *origen = fopen(nombre, "rb");
    FILE *destino = fopen(nombreCopia, "wb");

    if (origen == NULL || destino == NULL) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << std::endl;
        return false;
    }

    Jugador reg;
    while (fread(&reg, sizeof reg, 1, origen) == 1) {
        if (fwrite(&reg, sizeof reg, 1, destino) != 1) {
            cout << "ERROR AL ESCRIBIR EN EL ARCHIVO DE COPIA" << std::endl;
            fclose(origen);
            fclose(destino);
            return false;
        }
    }

    fclose(origen);
    fclose(destino);

    return true;
}

int ArchivoJugador::cantidadAlumnosPorEquipo(int idEquipo) {
    int contador=0;
    Jugador reg;

    for(int i=0;i<contarRegistros();i++){
        reg=leerRegistro(i);

        if(reg.getEquipo()==idEquipo && reg.getClaustro()==2){
            contador++;
        }
    }
return contador;
}



#endif // ARCHIVOJUGADOR_H_INCLUDED
