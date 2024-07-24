#ifndef CLSEQUIPOS_H_INCLUDED
#define CLSEQUIPOS_H_INCLUDED

int contarRegistrosEquipos();
void cargarCadena(char *nombre, int tam);

class Equipo{
 private:
    int ID;
    char nombre[30];
    int nivel;
    bool estado;
 public:
  Equipo(int _ID=0, const char* _nombre="NADA", int _nivel=0){
        ID= _ID;
        strcpy(nombre, _nombre);
        nivel=_nivel;
        estado=true;
    }

    //sets().
    void setID(int d){ID=d;}
    void setNombre(const char *n){strcpy(nombre,n);}

    bool setNivel(int n){
        if((n>=1) && (n<=3)) {{nivel=n;} return true;}
        else {return false;}
    }
    void setEstado(bool e){estado=e;}

    //gets().
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

    void Cargar(){
        int contador=contarRegistrosEquipos();
        if(contador == -1){
            contador = 0;
        }
        ID=++contador;
        cout<<"ID: "<<ID<<endl;
        cout<<"INGRESE EL NOMBRE: ";
        cargarCadena(nombre, 30);
        cout<<"INGRESE EL NIVEL (OPCION DEL 1 AL 3): ";
        cin>>nivel;
        while(setNivel(nivel)==false){
            cout<<"  INGRESE CORRECTAMENTE EL NIVEL."<<endl;
            cout<<" NIVEL (OPCION DEL 1 AL 3): ";
            cin>>nivel;
        }
        estado=true;
    }

    void Mostrar(){
        if(estado==true){
            cout<<"ID: ";
            cout<<ID<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"NIVEL (OPCION DEL 1 AL 8): ";
            cout<<nivel<<endl;
            estado=true;
            cout<<endl;
        }
    }
};

int contarRegistrosEquipos(){
    FILE *p;
    p=fopen("Equipos.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    int tam=ftell(p);
    int numRegistros=tam/sizeof(Equipo);

    // Reiniciar el contador basándose en la posición de los registros
    fseek(p,0,SEEK_SET);
    for(int i=0;i<numRegistros;i++) {
        Equipo reg;
        fread(&reg, sizeof(Equipo), 1, p);
        reg.setID(i+1);  // Asignar IDs consecutivos
        fseek(p,i * sizeof(Equipo),SEEK_SET);
        fwrite(&reg,sizeof(Equipo),1,p);
    }
    fclose(p);
return numRegistros;
}

#endif // CLSEQUIPOS_H_INCLUDED
