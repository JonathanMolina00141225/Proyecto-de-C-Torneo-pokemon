#include <iostream>
#include <fstream>
#include "pokemon_common.h"
#include "pvp.h"
#include "pve.h"

using namespace std;

void PvPmatch(){
    ifstream archivo("pvp.txt");

    if (archivo.is_open())
    {
        cout << endl;
        string linea;
        while (getline(archivo, linea))  // ← CORREGIDO: lectura correcta
        {
            cout << linea << endl;
        }
        archivo.close();
        cout << "..." << endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}

void PvEmatch(){
    ifstream archivo("pve2.txt");

    if (archivo.is_open())
    {
        cout << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
        cout << "..." << endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}

// Declaración simple para evitar error de compilación
void Matchrecords() {
    cout << "\n[Historial de partidas próximamente disponible.]\n";
}

int main(){
    int menu;

    // Cargar pokémons para ambos modos desde el archivo común
    vector<Pokemon> pokemonsParaPvp = leerPokemons("Pokemon_formato_para_juego.txt");
    vector<Pokemon> pokemonsParaPve = leerPokemons("Pokemon_formato_para_juego.txt");

    do {
        cout << "\nWelcome to pokemon world's" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1. PvP match" << endl;
        cout << "2. PvE match" << endl;
        cout << "3. Match records" << endl;
        cout << "4. Exit game" << endl;
        cin >> menu;

        switch (menu){
            case 1:
                PvPmatch();
                cout << "\nPvP - Jugador 1 selecciona su equipo:\n";

                if (pokemonsParaPvp.size() < 4) {
                    cout << "No hay suficientes Pokémon para PvP.\n";
                    break;
                }

                {
                    Pokemon p1 = seleccionarPokemon(pokemonsParaPvp);
                    Pokemon p2 = seleccionarPokemon(pokemonsParaPvp);
                    Pokemon r1 = seleccionarPokemon(pokemonsParaPvp);
                    Pokemon r2 = seleccionarPokemon(pokemonsParaPvp);
                    vector<Pokemon> equipo1 = {p1, r1};
                    vector<Pokemon> equipo2 = {p2, r2};
                    batallaPvP(equipo1, equipo2);
                }
                break;

            case 2:
                PvEmatch();
                batallaPvE(pokemonsParaPve, pokemonsParaPve);
                break;

            case 3:
                Matchrecords();
                break;

            case 4:
                cout << "Closing game" << endl;
                break;

            default:
                cout << "Please select a valid option" << endl;
                break;
        }

    } while(menu != 4);

    return 0;
}
