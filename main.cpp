#include <iostream>
#include <fstream>
using namespace std;
int main() {
    string provincia;
    string municipio;
    string localidad;
    int codigoPostal;
    string direccion;
    string margen;
    int longitud;
    int latitud;
    int precio95E5;
    int precio95E10;
    int precio95E5Premium;
    int precio98E5;
    int precio98E10;
    int precioGaseleoA;
    int precioGasoleoPremium;
    int precioGasoleoB;
    string rotulo;

    ifstream fin("../Dataset.tsv");//Declaramos fin como variable de entrada

    try{ // Declaro inicio del bloque que pudiese generar alguna excepcion
        while(!fin.eof()){
            //Definimos el orden en el que se seguirá la estructura
            fin>>provincia>>municipio>>localidad>>codigoPostal>>direccion>>margen>>longitud>>latitud>>precio95E5>>precio95E10>>precio95E5Premium>>precio98E5>>precio98E10>>precioGaseleoA>>precioGasoleoPremium>>precioGasoleoB>>rotulo;
            cout<<provincia<<endl;
        }
    }
    //Cerramos archivo .tsv
    catch(...){//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
        fin.close();
    }
}
