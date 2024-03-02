#ifndef SUBMENUTIPODEPORTE_H_INCLUDED
#define SUBMENUTIPODEPORTE_H_INCLUDED

#include "clsTipoDeporte.h"
#include "ArchivoTipoDeporte.h"
#include "subMenuTipoDeporte.h"

void subMenuTipoDeporte();
void agregarRegistroTipoDeporte();
void listarTipoDeporteXID();
void listarTodosTipoDeportes();
void modificarNivelDificultad();
bool eliminarRegistroTipoDeporte();

void subMenuTipoDeporte(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU TIPOS DE DEPORTE"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1) AGREGAR TIPO"<<endl;
        cout<<"2) LISTAR TIPO POR ID" <<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:agregarRegistroTipoDeporte();
                break;
            case 2:listarTipoDeporteXID();
                break;
            case 3:listarTodosTipoDeportes();
                break;
            case 4: modificarNivelDificultad();
                break;
            case 5: eliminarRegistroTipoDeporte();
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

void agregarRegistroTipoDeporte(){
    /*
    FILE *p;
    p=fopen("TipodeDeporte.dat","wb");
    fclose(p);
    */
    TipoDeportes reg;
    ArchivoTipoDeportes archi("TipodeDeporte.dat");
    reg.Cargar();
    bool agregar=archi.agregarRegistro(reg);
    if(agregar==true){
        cout<<"REGISTRO AGREGADO.";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO."<<endl;
    }
}


void listarTipoDeporteXID(){
    int ID;
    cout<<"INGRESE EL ID DEL TIPO DE DEPORTE QUE DESEA BUSCAR: ";
    cin>>ID;

    ArchivoTipoDeportes archi("TipodeDeporte.dat");
    int pos=archi.buscarRegistro(ID);

    if(pos==-1){
        cout << "NO SE ENCONTRO UN DEPORTE CON ESE ID." << endl;
    }
    else{
        TipoDeportes reg=archi.leerRegistro(pos);
        reg.Mostrar();
    }
}


void listarTodosTipoDeportes(){
    ArchivoTipoDeportes archi("TipodeDeporte.dat");
    archi.listarRegistros();
}


void modificarNivelDificultad(){
    int ID;
    int nuevoNivelDificultad;
    cout<<"INGRESE EL ID DEL TIPO DE DEPORTE CUYO NIVEL DE DIF. DESEA MODIFICAR :";
    cin>>ID;
    ArchivoTipoDeportes archi("TipodeDeporte.dat");
    int pos=archi.buscarRegistro(ID);
    if(pos==-1){
        cout << "NO SE ENCONTRO UN TIPO DE DEPORTE CON ESE DNI."<<endl;
    }
    else{
        TipoDeportes reg=archi.leerRegistro(pos);
        cout<<"INGRESE EL NUEVO NIVEL DE DIFICULTAD: ";
        cin>>nuevoNivelDificultad;
        reg.setDificultad(nuevoNivelDificultad);
        if(archi.modificarRegistro(pos, reg)){
            cout<<"NIVEL DE DIFICULTAD MODIFICADO EXITOSAMENTE."<<endl;
        }
        else{
            cout<<"ERROR AL MODIFICAR EL NIVEL DE DIFICULTAD."<<endl;
        }
    }
}


bool eliminarRegistroTipoDeporte(){
    ArchivoTipoDeportes archi("TipodeDeporte.dat");
    int ID;
    int pos;
    cout<<"INGRESE EL ID A BORRAR: ";
    cin>>ID;

    pos=archi.buscarRegistro(ID);

    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO CON ESE CODIGO"<<endl;
        return false;
    }
    else{
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
    }
    TipoDeportes reg=archi.leerRegistro(pos);
        reg.Mostrar();
        reg.setEstado(false);
        bool quePaso=archi.modificarRegistro(pos,reg);
        if(quePaso==true){
            cout<<"REGISTRO BORRADO"<<endl;
        }
        else{
            cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
        }
    cout<<endl;
    return true;
}


#endif // SUBMENUTIPODEPORTE_H_INCLUDED
