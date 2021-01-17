#include <iostream>
#include <fstream>
using namespace std;

//Estructura que almacena en memoria dinámica el contenido de cada una de las líneas del CSV
struct nodo{
    string provincia;
    string municipio;
    string localidad;
    int codigoPostal;
    string direccion;
    string margen;
    float longitud;
    float latitud;
    float precio95E5;
    float precio95E10;
    float precio95E5Premium;
    float precio98E5;
    float precio98E10;
    float precioGasoleoA;
    float precioGasoleoPremium;
    float precioGasoleoB;
    float precioGasoleoC;
    float precioBioetanol;
    float bioalcohol;
    float precioBiodiesel;
    float estermetilico;
    float precioGasesLicuados;
    float precioGasNaturalComprimido;
    float precioGasNaturalLicuado;
    float precioHidrogeno;
    string rotulo;
    string tipoVenta;
    string rem;
    string horario;
    string tipoServicio;

    nodo *next;
};

//Función para crear la lista con los datos del archivo
void crearLista(nodo *&lista);
void crearLista(nodo *&lista){
    //Indicamos al programa la dirección del archivo que tiene que leer
    ifstream read("../hoja_modificada_UK.tsv");
    try{
        //Mientras el archivo no esté vacío
        while(!read.eof()){
            nodo *actual= new nodo();
            //Creamos un nodo para indicar al programa los datos que se van a encontrar en el archivo y su orden respectivo
            read >>actual->provincia>>actual->municipio>> actual->localidad>> actual->codigoPostal>> actual->direccion>> actual->margen>> actual->longitud>> actual->latitud>> actual->precio95E5>>
                 actual->precio95E10>> actual->precio95E5Premium>> actual->precio98E5>> actual->precio98E10>> actual->precioGasoleoA>> actual->precioGasoleoPremium>>
                 actual->precioGasoleoB>> actual->precioGasoleoC>> actual->precioBioetanol>> actual->bioalcohol>> actual->precioBiodiesel>> actual->estermetilico>>
                 actual->precioGasesLicuados>> actual->precioGasNaturalComprimido>> actual->precioGasNaturalLicuado>> actual->precioHidrogeno>> actual->rotulo>>
                 actual->tipoVenta>> actual->rem>> actual->horario>> actual->tipoServicio;
            //Una vez leído el fichero añadimos el nodo a la lista
            if (lista==NULL){
                lista = actual;
                actual->next = NULL;
            }else{
                actual->next = lista;
                lista = actual;
            }
        }
        //Si el archivo no se puede leer, salta la excepción
    }catch(...){
        read.close();
        cout<<"El archivo no se ha podido leer."<<endl;
    }
}








//Función para comparar las gasolineras y sacar las 5 más baratas
void gasolinera(nodo *list, string provincia, string municipio, string localidad, int tipo);
void gasolinera(nodo *list, string provincia, string municipio, string localidad, int tipo){
    //Creamos punteros y variables necesarias e inicializamos las necesarias
    nodo *comprobar = list;
    nodo *header1 = list;
    nodo *peque1;
    nodo *peque2;
    nodo *peque3;
    nodo *peque4;
    nodo *peque5;
    float barato = 10000000;
    float gasolinaActual;
    float precioFinal = 0;
    int contprovincia = 0;
    int contmunicipio = 0;
    int contlocalidad = 0;

    //Recorremos la lista y cada valor que introduzca el usuario y coincida con alguno de la lista, aumentará el contador
    do{
        if(comprobar->provincia == provincia){
            contprovincia++;
        }
        if(comprobar->municipio == municipio){
            contmunicipio++;
        }
        if(comprobar->localidad == localidad){
            contlocalidad++;
        }
        comprobar = comprobar->next;
    }while(comprobar != NULL);

    //Si todos los contadores son distintos de 0, el programa habrá encontrado la localización introducida por el usuario
    if(contprovincia != 0 && contmunicipio != 0 && contlocalidad != 0) {
        cout<<"Buscando gasolineras localizacion indicada..."<<endl;
        //Si algunos de los contadores es 0 significa que no todos los datos están en el fichero y volvemos al menú principal
    }else if(contprovincia == 0 || contmunicipio == 0 || contlocalidad == 0 || tipo > 9){
        cout<<"Estos datos no se encuentran, asegurese de que estan correctamente escritos (Mayusculas)"<<endl;
        return;
    }

    //Buscamos la primera gasolinera más barata
    //Actualizamos el valor de las variables necesarias
    header1 = list;
    do{
        //Recorremos la lista, y cuando coincidan los datos inicializaremos la variable gasolinaActual con su precio correspondiente
        if((header1->provincia)==provincia && (header1->municipio)==municipio && (header1->localidad)==localidad){
            if(tipo == 1) { gasolinaActual = header1->precio95E5;
            }if(tipo == 2) { gasolinaActual = header1->precio95E10;
            }if(tipo == 3) { gasolinaActual = header1->precio95E5Premium;
            }if(tipo == 4) { gasolinaActual = header1->precio98E5;
            }if(tipo == 5) { gasolinaActual = header1->precio98E10;
            }if(tipo == 6) { gasolinaActual = header1->precioGasoleoA;
            }if(tipo == 7) { gasolinaActual = header1->precioGasoleoPremium;
            }if(tipo == 8) { gasolinaActual = header1->precioGasoleoB;
            }

            //Cuando el valor de gasolinaActual sea menor o igual que el valor de barato y este valor sea distinto de 0,
            //El puntero peque creado anteriormente apuntará a esa posición
            if (gasolinaActual<= barato && gasolinaActual!=0) {
               peque1=header1;
                //Actualizamos las variables precioFinal y barato con los valores correspondientes
                if(tipo == 1) { precioFinal = peque1->precio95E5; barato = peque1->precio95E5;
                } if(tipo == 2){ precioFinal = peque1->precio95E10; barato = peque1->precio95E10;
                } if(tipo == 3){ precioFinal = peque1->precio95E5Premium; barato = peque1->precio95E5Premium;
                } if(tipo == 4){ precioFinal = peque1->precio98E5; barato = peque1->precio98E5;
                } if(tipo == 5){ precioFinal = peque1->precio98E10; barato = peque1->precio98E10;
                } if(tipo == 6){ precioFinal = peque1->precioGasoleoA; barato = peque1->precioGasoleoA;
                } if(tipo == 7){ precioFinal = peque1->precioGasoleoPremium; barato = peque1->precioGasoleoPremium;
                } if(tipo == 8){ precioFinal = peque1->precioGasoleoB; barato = peque1->precioGasoleoB;
                }
            }
        }
        header1 = header1->next;
    }while(header1!=NULL);
//Si el valor precioFinal es igual a 0, mostramos el mensaje correspondiente y volvemos al menú principal
    if(precioFinal == 0){
        cout<<" "<<endl;
        cout<<"Ninguna gasolinera tiene este tipo de gasolina."<<endl;
        cout<<" "<<endl;
        return;
    }
    //Mostramos los datos de la gasolinera más barata
    cout<<"Gasolineras mas baratas: "<<endl;
    cout<<"1/    Calle: "<< peque1->direccion<<"   Precio: "<<precioFinal<<"   Codigo Postal: "<< peque1->codigoPostal<<"    Margen: "<<peque1->margen<<"    Rotulo: "<<peque1->rotulo<<endl;
    cout<<" "<<endl;
    //Si se cumple esta condición, mostramos el mensaje correspondiente y volvemos al menú principal
    if(contlocalidad == 1){
        cout<<"En "<<localidad<<" solo existe una gasolinera."<<endl;
        cout<<" "<<endl;
        return;
    }

    //Buscamos la segunda gasolinera más barata
    //Actualizamos el valor de las variables necesarias
    barato = 10000000;
    precioFinal = 0;
    header1 = list;
    do{
        //Recorremos la lista y cuando coincidan los datos inicializaremos la variable gasolinaActual con su precio correspondiente
        if((header1->provincia)==provincia && (header1->municipio)==municipio && (header1->localidad)==localidad) {
            if (tipo == 1) { gasolinaActual = header1->precio95E5;
            }if(tipo == 2) { gasolinaActual = header1->precio95E10;
            }if(tipo == 3) { gasolinaActual = header1->precio95E5Premium;
            }if(tipo == 4) { gasolinaActual = header1->precio98E5;
            }if(tipo == 5) { gasolinaActual = header1->precio98E10;
            }if(tipo == 6) { gasolinaActual = header1->precioGasoleoA;
            }if(tipo == 7) { gasolinaActual = header1->precioGasoleoPremium;
            }if(tipo == 8) { gasolinaActual = header1->precioGasoleoB;
            }
            //Cuando el valor de gasolinaActual sea menor o igual que el valor de barato y este valor sea distinto de 0,
            //el puntero peque creado anteriormente apuntará a esa posición
            //Comparando que no sea igual a la anterior más barata
            if (gasolinaActual<= barato && gasolinaActual!=0 && header1!=peque1) {
                peque2=header1;
                //Actualizamos las variables precioFinal y barato con los valores correspondientes
                if(tipo == 1) { precioFinal = peque2->precio95E5; barato = peque2->precio95E5;
                }if(tipo == 2){ precioFinal = peque2->precio95E10; barato = peque2->precio95E10;
                } if(tipo == 3){ precioFinal = peque2->precio95E5Premium; barato = peque2->precio95E5Premium;
                } if(tipo == 4){ precioFinal = peque2->precio98E5; barato = peque2->precio98E5;
                } if(tipo == 5){ precioFinal = peque2->precio98E10; barato = peque2->precio98E10;
                } if(tipo == 6){ precioFinal = peque2->precioGasoleoA; barato = peque2->precioGasoleoA;
                } if(tipo == 7){ precioFinal = peque2->precioGasoleoPremium; barato = peque2->precioGasoleoPremium;
                } if(tipo == 8){ precioFinal = peque2->precioGasoleoB; barato = peque2->precioGasoleoB;
                }
            }
        }
        header1 = header1->next;
    }while(header1!=NULL);
//Si el valor precioFinal es igual a 0, mostramos el mensaje correspondiente y volvemos al menú principal
    if(precioFinal == 0){
        cout<<" "<<endl;
        cout<<"Esta localidad solo tiene este tipo de gasolina una vez."<<endl;
        cout<<" "<<endl;
        return;

    }
    //Mostramos los datos de la segunda gasolinera más barata
    cout<<"2/    Calle: "<< peque2->direccion<<"   Precio: "<<precioFinal<<"   Codigo Postal: "<< peque2->codigoPostal<<"    Margen: "<<peque2->margen<<"    Rotulo: "<<peque2->rotulo<<endl;
    cout<<" "<<endl;
    //Si se cumple esta condición, mostramos el mensaje correspondiente y volvemos al menú principal

    if(contlocalidad == 2){
        cout<<"En "<<localidad<<" solo existen dos gasolineras."<<endl;
        cout<<" "<<endl;

        return;
    }

    //Buscamos la tercera gasolinera más barata
    //Actualizamos el valor de las variables necesarias

    barato = 10000000;
    precioFinal = 0;
    header1 = list;
    do{
        //Recorremos la lista y cuando coincidan los datos inicializaremos la variable gasolinaActual con su precio correspondiente
        if((header1->provincia)==provincia && (header1->municipio)==municipio && (header1->localidad)==localidad){
            if(tipo == 1) { gasolinaActual = header1->precio95E5;
            }if(tipo == 2) { gasolinaActual = header1->precio95E10;
            }if(tipo == 3) { gasolinaActual = header1->precio95E5Premium;
            }if(tipo == 4) { gasolinaActual = header1->precio98E5;
            }if(tipo == 5) { gasolinaActual = header1->precio98E10;
            }if(tipo == 6) { gasolinaActual = header1->precioGasoleoA;
            }if(tipo == 7) { gasolinaActual = header1->precioGasoleoPremium;
            }if(tipo == 8) { gasolinaActual = header1->precioGasoleoB;
            }
            //Cuando el valor de gasolinaActual sea menor o igual que el valor de barato y este valor sea distinto de 0,
            //El puntero peque creado anteriormente apuntará a esa posición
            //Comparando que no sea igual a las anteriores más baratas
            if (gasolinaActual<= barato && gasolinaActual!=0 && header1!=peque1 && header1!=peque2) {
                peque3=header1;

                //Actualizamos las variables precioFinal y barato con los valores correspondientes
                if(tipo == 1) { precioFinal = peque3->precio95E5; barato = peque3->precio95E5;
                } if(tipo == 2){ precioFinal = peque3->precio95E10; barato = peque3->precio95E10;
                } if(tipo == 3){ precioFinal = peque3->precio95E5Premium; barato = peque3->precio95E5Premium;
                } if(tipo == 4){ precioFinal = peque3->precio98E5; barato = peque3->precio98E5;
                } if(tipo == 5){ precioFinal = peque3->precio98E10; barato = peque3->precio98E10;
                } if(tipo == 6){ precioFinal = peque3->precioGasoleoA; barato = peque3->precioGasoleoA;
                } if(tipo == 7){ precioFinal = peque3->precioGasoleoPremium; barato = peque3->precioGasoleoPremium;
                } if(tipo == 8){ precioFinal = peque3->precioGasoleoB; barato = peque3->precioGasoleoB;
                }
            }
        }
        header1 = header1->next;
    }while(header1!=NULL);
//Si el valor precioFinal es igual a 0, mostramos el mensaje correspondiente y volvemos al menú principal
    if(precioFinal == 0){
        cout<<" "<<endl;
        cout<<"Esta localidad solo tiene este tipo de gasolina dos veces."<<endl;
        cout<<" "<<endl;
        return;
    }

    //Mostramos los datos de la tercera gasolinera más barata
    cout<<"3/    Calle: "<< peque3->direccion<<"   Precio: "<<precioFinal<<"   Codigo Postal: "<< peque3->codigoPostal<<"    Margen: "<<peque3->margen<<"    Rotulo: "<<peque3->rotulo<<endl;
    cout<<" "<<endl;
    //Si se cumple esta condición, mostramos el mensaje correspondiente y volvemos al menú principal

    if(contlocalidad == 3){
        cout<<"En "<<localidad<<" solo existen tres gasolineras."<<endl;
        cout<<" "<<endl;
        return;
    }

    //Buscamos la cuarta gasolinera más barata
    //Actualizamos el valor de las variables necesarias

    barato = 10000000;
    precioFinal = 0;
    header1 = list;
    do{
        //Recorremos la lista y cuando coincidan los datos inicializaremos la variable gasolinaActual con su precio correspondiente
        if((header1->provincia)==provincia && (header1->municipio)==municipio && (header1->localidad)==localidad){
            if(tipo == 1) { gasolinaActual = header1->precio95E5;
            }if(tipo == 2) { gasolinaActual = header1->precio95E10;
            }if(tipo == 3) { gasolinaActual = header1->precio95E5Premium;
            }if(tipo == 4) { gasolinaActual = header1->precio98E5;
            }if(tipo == 5) { gasolinaActual = header1->precio98E10;
            }if(tipo == 6) { gasolinaActual = header1->precioGasoleoA;
            }if(tipo == 7) { gasolinaActual = header1->precioGasoleoPremium;
            }if(tipo == 8) { gasolinaActual = header1->precioGasoleoB;
            }
            //Cuando el valor de gasolinaActual sea menor o igual que el valor de barato y este valor sea distinto de 0,
            //el puntero peque creado anteriormente apuntará a esa posición
            //Comparando que no sea igual a las anteriores más baratas
            if (gasolinaActual<= barato && gasolinaActual!=0 && header1!=peque1 && header1!=peque2 && header1!=peque3) {
                peque4=header1;
                //Actualizamos las variables precioFinal y barato con los valores correspondientes

                if(tipo == 1) { precioFinal = peque4->precio95E5; barato = peque4->precio95E5;
                } if(tipo == 2){ precioFinal = peque4->precio95E10; barato = peque4->precio95E10;
                } if(tipo == 3){ precioFinal = peque4->precio95E5Premium; barato = peque4->precio95E5Premium;
                } if(tipo == 4){ precioFinal = peque4->precio98E5; barato = peque4->precio98E5;
                } if(tipo == 5){ precioFinal = peque4->precio98E10; barato = peque4->precio98E10;
                } if(tipo == 6){ precioFinal = peque4->precioGasoleoA; barato = peque4->precioGasoleoA;
                } if(tipo == 7){ precioFinal = peque4->precioGasoleoPremium; barato = peque4->precioGasoleoPremium;
                } if(tipo == 8){ precioFinal = peque4->precioGasoleoB; barato = peque4->precioGasoleoB;
                }
            }
        }
        header1 = header1->next;
    }while(header1!=NULL);
//Si el valor precioFinal es igual a 0, mostramos el mensaje correspondiente y volvemos al menú principal
    if(precioFinal == 0){
        cout<<" "<<endl;
        cout<<"Esta localidad solo tiene este tipo de gasolina tres veces."<<endl;
        cout<<" "<<endl;
        return;
    }
    //Mostramos los datos de la cuarta gasolinera más barata

    cout<<"4/    Calle: "<< peque4->direccion<<"   Precio: "<<precioFinal<<"   Codigo Postal: "<< peque4->codigoPostal<<"    Margen: "<<peque4->margen<<"    Rotulo: "<<peque4->rotulo<<endl;
    cout<<" "<<endl;
    //Si se cumple esta condición, mostramos el mensaje correspondiente y volvemos al menú principal

    if(contlocalidad == 4){
        cout<<"En "<<localidad<<" solo existen cuatro gasolineras."<<endl;
        cout<<" "<<endl;
        return;
    }


    //Buscamos la quinta gasolinera más barata
    //Actualizamos el valor de las variables necesarias
    barato = 10000000;
    precioFinal = 0;
    header1 = list;
    do{
        //Recorremos la lista y cuando coincidan los datos inicializaremos la variable gasolinaActual con su precio correspondiente
        if((header1->provincia)==provincia && (header1->municipio)==municipio && (header1->localidad)==localidad){
            if(tipo == 1) { gasolinaActual = header1->precio95E5;
            }if(tipo == 2) { gasolinaActual = header1->precio95E10;
            }if(tipo == 3) { gasolinaActual = header1->precio95E5Premium;
            }if(tipo == 4) { gasolinaActual = header1->precio98E5;
            }if(tipo == 5) { gasolinaActual = header1->precio98E10;
            }if(tipo == 6) { gasolinaActual = header1->precioGasoleoA;
            }if(tipo == 7) { gasolinaActual = header1->precioGasoleoPremium;
            }if(tipo == 8) { gasolinaActual = header1->precioGasoleoB;
            }
            //Cuando el valor de gasolinaActual sea menor o igual que el valor de barato y este valor sea distinto de 0,
            //el puntero peque creado anteriormente apuntará a esa posición
            //Comparando que no sea igual a las anteriores más baratas
            if (gasolinaActual<= barato && gasolinaActual!=0 && header1!=peque1 && header1!=peque2 && header1!=peque3 && header1!=peque4) {
                peque5=header1;

                //Actualizamos las variables precioFinal y barato con los valores correspondientes
                if(tipo == 1) { precioFinal = peque5->precio95E5; barato = peque5->precio95E5;
                } if(tipo == 2){ precioFinal = peque5->precio95E10; barato = peque5->precio95E10;
                } if(tipo == 3){ precioFinal = peque5->precio95E5Premium; barato = peque5->precio95E5Premium;
                } if(tipo == 4){ precioFinal = peque5->precio98E5; barato = peque5->precio98E5;
                } if(tipo == 5){ precioFinal = peque5->precio98E10; barato = peque5->precio98E10;
                } if(tipo == 6){ precioFinal = peque5->precioGasoleoA; barato = peque5->precioGasoleoA;
                } if(tipo == 7){ precioFinal = peque5->precioGasoleoPremium; barato = peque5->precioGasoleoPremium;
                } if(tipo == 8){ precioFinal = peque5->precioGasoleoB; barato = peque5->precioGasoleoB;
                }
            }
        }
        header1 = header1->next;
    }while(header1!=NULL);
//Si el valor precioFinal es igual a 0, mostramos el mensaje correspondiente y volvemos al menú principal
    if(precioFinal == 0){
        cout<<" "<<endl;
        cout<<"Esta localidad solo tiene este tipo de gasolina cuatro veces."<<endl;
        cout<<" "<<endl;
        return;
    }
    //Mostramos los datos de la quinta gasolinera más barata

    cout<<"5/    Calle: "<< peque5->direccion<<"   Precio: "<<precioFinal<<"   Codigo Postal: "<< peque5->codigoPostal<<"    Margen: "<<peque5->margen<<"    Rotulo: "<<peque5->rotulo<<endl;
    cout<<" "<<endl;

    //Si se cumple esta condición, mostramos el mensaje correspondiente y volvemos al menú principal
    if(contlocalidad == 5){
        cout<<"En "<<localidad<<" solo existen cinco gasolineras."<<endl;
        cout<<" "<<endl;
        return;
    }

}

int main() {
    //Creamos una lista vacía
    nodo *header = NULL;
//Llamamos a la función crear lista y le pasamos la lista header
    crearLista(header);
//creamos las variables necesarias
    string provinciaPedida, municipioPedido, localidadPedida;
    int tipoGasolina, repetir;

    //Menu
    cout<<"  ACTIVIDAD GRUPAL PROGRAMACION CON ESTRUCUTRAS LINEALES  "<<endl;
    cout<<" La actividad consiste en realizar una busqueda de las 5 "<<endl;
    cout<<" gasolineras con los precios mas baratos en un tipo de "<<endl;
    cout<<" combustible de una localizacion indicada por el usuario."<<endl;
    cout<<" "<<endl;
    cout<<" Los participantes que han realizado este proyecto son: "<<endl;
    cout<<"     Pablo Pascual"<<endl;
    cout<<"     Miguel Ramos"<<endl;
    cout<<"     Victor Perez"<<endl;
    cout<<"     Nicolas Perez"<<endl;
    cout<<"     Maria Sol Torres"<<endl;
    cout<<"     Adilem Dobras"<<endl;
    cout<<"     Diego Martin"<<endl;
    cout<<" "<<endl;
    cout << "-------------------------------------------------" << endl;
    cout << "      Bienvenido al buscador de gasolineras" << endl;
    cout << "-------------------------------------------------" << endl;
    do{
        cout<<"Ingrese la provincia: "<<endl;
        cin>>provinciaPedida;
        cout<<"Ingrese el municipio: "<<endl;
        cin>>municipioPedido;
        cout<<"Ingrese la localidad: "<<endl;
        cin>>localidadPedida;
        cout<<"Que tipo gasolina necesita?"<<endl;
        cout<<" Tipos gasolina:  "<<endl;
        cout<<" 1/ Gasolina 95 E5"<<endl;
        cout<<" 2/ Gasolina 95 E10"<<endl;
        cout<<" 3/ Gasolina 95 E5 Premium"<<endl;
        cout<<" 4/ Gasolina 98 E5"<<endl;
        cout<<" 5/ Gasolina 98 E10"<<endl;
        cout<<" 6/ Gasoleo A"<<endl;
        cout<<" 7/ Gasoleo Premium"<<endl;
        cout<<" 8/ Gasoleo B"<<endl;
        cin>>tipoGasolina;
//Con los datos introducidos por el usuario llamamos a la función gasolinera
        gasolinera(header,provinciaPedida,municipioPedido,localidadPedida,tipoGasolina);

        cout<<"Quiere buscar otro tipo de gasolina en una ubicacion diferente? (si=1 / no=0)"<<endl;
        cin>>repetir;
        //Si el usuario pulsa 1, se vuelve a ejecutar el menú
    }while(repetir == 1);
    //Si el usuario pulsa 0 se para la ejecución del programa
    if(repetir == 0){
        cout<<"Hasta la proxima"<<endl;
    }

}