#ifndef ARCHIVOEQUIPOS_H_INCLUDED
#define ARCHIVOEQUIPOS_H_INCLUDED

#include "clsEquipos.h"

class ArchivoEquipos{
 private:
    char nombre[30];
 public:
    ArchivoEquipos(const char *nombreArchivo){strcpy(nombre, nombreArchivo);}
    const char *getNombre() {return nombre;}
    bool listarRegistros();
    bool agregarRegistro(Equipo);
    int buscarRegistro(int ID);
    bool buscarRegistroBool(int ID);
    Equipo leerRegistro(int pos);
    bool modificarRegistro(int pos, Equipo reg);
    int contarRegistros();
};


bool ArchivoEquipos::listarRegistros(){
    Equipo reg;
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


bool ArchivoEquipos::agregarRegistro(Equipo reg){
    FILE *p=fopen(nombre,"ab");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
return escribio;
}

int ArchivoEquipos::buscarRegistro(int ID){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.getID() == (ID)){
            fclose(p);
            return cont ;
        }
         cont++;
    }
    fclose(p);
return -1;
}


bool ArchivoEquipos::buscarRegistroBool(int ID){
    Equipo reg;
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


Equipo ArchivoEquipos::leerRegistro(int pos){
    Equipo reg;
    reg.setEstado(false);
    FILE *p=fopen(nombre,"rb"); // aca va el ROOT.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Equipo)*pos,0);
    fread(&reg, sizeof reg, 1,p);
    fclose(p);
    return reg;

    reg.setEstado(false);

return reg;
}


bool ArchivoEquipos::modificarRegistro(int pos, Equipo reg){
    FILE *p=fopen(nombre,"rb+"); // Agrega al modo lo que le falta.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Equipo)*pos,0);
    bool escribio = fwrite(&reg, sizeof reg, 1,p);

    fclose(p);
return escribio;
}

int ArchivoEquipos::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int tam=ftell(p);

    fclose(p);
return tam/sizeof(Equipo);
}

#endif // ARCHIVOEQUIPOS_H_INCLUDED
