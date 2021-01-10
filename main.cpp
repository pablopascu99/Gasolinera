#include <iostream>
#include <fstream>
using namespace std;
string prov, mun, local, gasol;
void menu();
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
    int precioGasoleoA;
    int precioGasoleoPremium;
    int precioGasoleoB;
    string rotulo;

    ifstream fin("../Dataset.tsv");//Declaramos fin como variable de entrada

    try{ // Declaro inicio del bloque que pudiese generar alguna excepcion
        while(!fin.eof()){
            //Definimos el orden en el que se seguirá la estructura
            fin>>provincia>>municipio>>localidad>>codigoPostal>>direccion>>margen>>longitud>>latitud>>precio95E5>>precio95E10>>precio95E5Premium>>precio98E5>>precio98E10>>precioGasoleoA>>precioGasoleoPremium>>precioGasoleoB>>rotulo;
            cout<<provincia<<endl;
            menu();
            if(prov!=provincia){
                menu();
            }
            if(mun!=municipio){
                menu();
            }
            if(local!=localidad){
                menu();
            }
            if(gasol!="95E5" || gasol!="95E10" || gasol!="95E5Premium" || gasol!="98E5" || gasol!="98E10" || gasol!="GasoleoA" || gasol!="GasoleoPremium" || gasol!="GasoleoB"){
                menu();
            }
        }
    }
    //Cerramos archivo .tsv
    catch(...){//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
        fin.close();
    }
}
void menu(){
    cout << "-------------------------------------------------" << endl;
    cout << "      Bienvenido al buscador de gasolineras" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " - Introduzca la provincia: " << endl;
    cin >> prov;
    cout << "\n";
    cout << " - Introduzca la municipio: " << endl;
    cin >> mun;
    cout << "\n";
    cout << " - Introduzca la localidad: " << endl;
    cin >> local;
    cout << "\n";
    cout << " - Introduzca el tipo de gasolina: " << endl;
    cin >> gasol;
    cout << "\n";
}
