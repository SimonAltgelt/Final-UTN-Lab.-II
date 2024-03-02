#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED

#include "clsEquipos.h"
#include "ArchivoEquipos.h"
#include "subMenuEquipos.h"

void subMenuEquipos();
void agregarEquipo();
void listarEquipoXID();
void listarTodosEquipos();
void modificarNombre();
bool eliminarRegistroEquipo();

void subMenuEquipos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU EQUIPOS "<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID" <<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:agregarEquipo();
                break;
            case 2:listarEquipoXID();
                break;
            case 3:listarTodosEquipos();
                break;
            case 4: modificarNombre();
                break;
            case 5: eliminarRegistroEquipo();
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


void agregarEquipo(){
    /*
    FILE *p;
    p=fopen("Equipos.dat","wb");
    fclose(p);
    */
    Equipo reg;
    ArchivoEquipos archi("Equipos.dat");
    reg.Cargar();
    bool agregar=archi.agregarRegistro(reg);
    if(agregar==true){
        cout<<"REGISTRO AGREGADO.";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO."<<endl;
    }
}



void listarEquipoXID(){
    int ID;
    cout<<"INGRESE EL ID DEL EQUIPO QUE DESEA BUSCAR: ";
    cin>>ID;
    ArchivoEquipos archi("Equipos.dat");
    int pos=archi.buscarRegistro(ID);

    if(pos==-1){
        cout << "NO SE ENCONTRO UN Equipo CON ESE ID." << endl;
    }
    else{
        Equipo reg = archi.leerRegistro(pos);
        reg.Mostrar();
    }
}


void listarTodosEquipos(){
    ArchivoEquipos archi("Equipos.dat");
    archi.listarRegistros();
}


void modificarNombre(){
    int ID;
    char nuevoNombre[30];
    cout<<"INGRESE EL ID DEL EQUIPO CUYO NOMBRE DESEA MODIFICAR :";
    cin>>ID;
    ArchivoEquipos archi("Equipos.dat");
    int pos=archi.buscarRegistro(ID);
    if(pos==-1){
        cout << "NO SE ENCONTRO UN EQUIPO CON ESE ID."<<endl;
    }
    else{
        Equipo reg=archi.leerRegistro(pos);
        cout<<"INGRESE EL NUEVO NOMBRE DEL EQUIPO: ";
        cin>>nuevoNombre;
        reg.setNombre(nuevoNombre);
        if(archi.modificarRegistro(pos, reg)){
            cout<<"NOMBRE DEL EQUIPO MODIFICADO EXITOSAMENTE."<<endl;
        }
        else{
            cout<<"ERROR AL MODIFICAR EL NOMBRE DEL EQUIPO."<<endl;
        }
    }
}


bool eliminarRegistroEquipo(){
    ArchivoEquipos archi("Equipos.dat");
    int ID;
    int pos;
    cout<<"INGRESE EL ID A BORRAR: ";
    cin>>ID;

    pos=archi.buscarRegistro(ID); //buscarRegistro(int ) devuelve la pos del registro en el archivo.

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
    Equipo reg=archi.leerRegistro(pos);
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



#endif // SUBMENUEQUIPOS_H_INCLUDED
