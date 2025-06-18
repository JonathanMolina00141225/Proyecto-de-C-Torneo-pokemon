#include <iostream>
#include <fstream>

using namespace std;

void PvPmatch(){
    ifstream archivo("pvp.txt");

    if (archivo.is_open())
    {
        cout<<endl;
        while (archivo >> e.PvP)
        {
            cout << e.PvP << endl;
        }
        archivo.close();
        cout<<"..."<< endl;

    }else
    {
        cout<<"Error al abrir el archivo"<< endl;
    }
}

void PvEmatch(){
    ifstream archivo("pve2.txt");

    if (archivo.is_open())
    {
        cout<<endl;
    }
    
}

int main(){
    int menu;

    do {

        cout << "Welcome to pokemon world's" <<endl;
        cout << "What do you want to do?" <<endl;
        cout << "1. PvP match" <<endl;
        cout << "2. PvE match" <<endl;
        cout << "3. Match records" <<endl;
        cout << "4. Exit game" <<endl;
        cin >> menu;

        switch (menu){
            case 1: 
            PvPmatch();
            break;
            case 2:
            PvEmatch();
            break;
            case 3:
            Matchrecords();
            break;
            default:
            cout << "Please select a valid option" <<endl;
            break;
        }

    } while(menu != 4);
    cout << "Closing game" <<endl;

    return 0;
}