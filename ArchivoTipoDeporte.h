#ifndef ArchivoTipoDeporte_H_INCLUDED
#define ArchivoTipoDeporte_H_INCLUDED

#include "clsTipoDeporte.h"

class ArchivoTipoDeportes{
 private:
    char nombre[30];
 public:
    ArchivoTipoDeportes(const char *nombreArchivo){strcpy(nombre, nombreArchivo);}
    const char *getNombre() {return nombre;}
    bool listarRegistros();
    bool agregarRegistro(TipoDeportes);
    int buscarRegistro(int ID);
    bool buscarRegistroBool(int ID);
    TipoDeportes leerRegistro(int pos);
    bool modificarRegistro(int pos, TipoDeportes reg);
    int contarRegistros();
};


bool ArchivoTipoDeportes::listarRegistros(){
    TipoDeportes reg;
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


bool ArchivoTipoDeportes::agregarRegistro(TipoDeportes reg){
    FILE *p=fopen(nombre,"ab");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
return escribio;
}

int ArchivoTipoDeportes::buscarRegistro(int ID){
    TipoDeportes reg;
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


bool ArchivoTipoDeportes::buscarRegistroBool(int ID){
    TipoDeportes reg;
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


TipoDeportes ArchivoTipoDeportes::leerRegistro(int pos){
    TipoDeportes reg;
    reg.setEstado(false);
    FILE *p=fopen(nombre,"rb"); // aca va el ROOT.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(TipoDeportes)*pos,0);
    fread(&reg, sizeof reg, 1,p);
    fclose(p);
    return reg;

    reg.setEstado(false);

return reg;
}


bool ArchivoTipoDeportes::modificarRegistro(int pos, TipoDeportes reg){
    FILE *p=fopen(nombre,"rb+"); // Agrega al modo lo que le falta.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(TipoDeportes)*pos,0);
    bool escribio = fwrite(&reg, sizeof reg, 1,p);

    fclose(p);
return escribio;
}

int ArchivoTipoDeportes::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int tam=ftell(p);

    fclose(p);
return tam/sizeof(TipoDeportes);
}


#endif // ArchivoTipoDeportes_H_INCLUDED
