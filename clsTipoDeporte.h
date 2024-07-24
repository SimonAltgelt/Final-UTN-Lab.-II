#ifndef CLSTIPODEPORTE_H_INCLUDED
#define CLSTIPODEPORTE_H_INCLUDED

int contarRegistrosTipoDeportes();
void cargarCadena(char *palabra, int tam);

class TipoDeportes{
 private:
    int ID;
    char nombre[30];
    int dificultad;
    bool estado;
 public:
  TipoDeportes(int _ID=0, const char* _nombre="NADA", int _dificultad=0){
        ID= _ID;
        strcpy(nombre, _nombre);
        dificultad=_dificultad;
        estado=true;
    }

    //sets().
    void setID(int d){ID=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    bool setDificultad(int t){
        if((t>=1) && (t<=8)) {{dificultad=t;} return true;}
        else {return false;}
    }
    void setEstado(bool e){estado=e;}

    //gets().
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getDificultad(){return dificultad;}
    bool getEstado(){return estado;}

    void Cargar(){
        int contador=contarRegistrosTipoDeportes();
        ID=++contador;
        cout<<"ID: "<<ID<<endl;
        cout<<"INGRESE EL NOMBRE: ";
        cargarCadena(nombre,30);
        cout<<"INGRESE EL NIVEL DE DIFICULTAD (OPCION DEL 1 AL 8): ";
        cin>>dificultad;
        while(setDificultad(dificultad)==false){
            cout<<"  INGRESE CORRECTAMENTE EL NIVEL DE DIFICULTAD."<<endl;
            cout<<" NIVEL DE DIFICULTAD(OPCION DEL 1 AL 8): ";
            cin>>dificultad;
        }
        estado=true;
    }

    void Mostrar(){
        if(estado==true){
            cout<<"ID: ";
            cout<<ID<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"NIVEL DE DIFICULTAD (OPCION DEL 1 AL 8): ";
            cout<<dificultad<<endl;
            estado=true;
            cout<<endl;
        }
    }
};

void cargarCadena(char *palabra, int tam){
    int i=0;
    fflush(stdin);
    for(i=0;i<tam;i++){
        palabra[i]=cin.get();
        if(palabra[i]=='\n') break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

int contarRegistrosTipoDeportes(){
    FILE *p;
    p=fopen("TipodeDeporte.dat","rb");
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

#endif // CLSTIPODEPORTE_H_INCLUDED
