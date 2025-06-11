#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

     ifstream archivoLectura("dialogos.txt"); 
    string linea; 

    if (archivoLectura.is_open()) { // 
        cout << "Contenido del archivo:\n"; 
        while (getline(archivoLectura, linea)) { 
            cout << linea << endl; 
        }
        archivoLectura.close(); 
    } else {
        cout << "No se pudo abrir el archivo para leer.\n"; 
    }





    return 0;
}
    
