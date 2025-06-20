#ifndef PVP_H
#define PVP_H

#include "pokemon_common.h"
#include <limits>

Pokemon seleccionarPokemon(vector<Pokemon>& pokemons) {
    cout << "\nSelecciona tu Pokemon:\n";
    for (size_t i = 0; i < pokemons.size(); ++i) {
        cout << i + 1 << ". " << pokemons[i].nombre << " (Vida: " << pokemons[i].vida << ")\n";
    }
    int eleccion;
    do {
        cout << "Opcion: ";
        cin >> eleccion;
        if (cin.fail() || eleccion < 1 || eleccion > (int)pokemons.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Intenta de nuevo.\n";
        } else {
            break;
        }
    } while (true);

    Pokemon elegido = pokemons[eleccion - 1];
    pokemons.erase(pokemons.begin() + eleccion - 1);
    return elegido;
}

void batallaPvP(vector<Pokemon> equipo1, vector<Pokemon> equipo2) {
    int idx1 = 0, idx2 = 0;
    while (idx1 < (int)equipo1.size() && idx2 < (int)equipo2.size()) {
        Pokemon& jugador = equipo1[idx1];
        Pokemon& rival = equipo2[idx2];

        cout << "\n[Jugador 1] Pokemon: " << jugador.nombre << " (Vida: " << jugador.vida << ")\n";
        cout << "[Jugador 2] Pokemon: " << rival.nombre << " (Vida: " << rival.vida << ")\n";

        cout << "\nJugador 1 - Ataques disponibles:\n";
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << jugador.ataques[i].nombre << " (Daño: " << jugador.ataques[i].danio
                 << ", PP: " << jugador.ataques[i].pp << ")\n";
        }

        int ataque;
        do {
            cout << "Jugador 1, selecciona ataque (1-4): ";
            cin >> ataque;
        } while (ataque < 1 || ataque > 4 || jugador.ataques[ataque - 1].pp <= 0);

        rival.vida -= jugador.ataques[ataque - 1].danio;
        jugador.ataques[ataque - 1].pp--;
        cout << jugador.nombre << " uso " << jugador.ataques[ataque - 1].nombre << "!\n";
        if (rival.vida <= 0) {
            cout << rival.nombre << " se ha debilitado!\n";
            idx2++;
            continue;
        }

        cout << "\nJugador 2 - Ataques disponibles:\n";
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << rival.ataques[i].nombre << " (Daño: " << rival.ataques[i].danio
                 << ", PP: " << rival.ataques[i].pp << ")\n";
        }

        do {
            cout << "Jugador 2, selecciona ataque (1-4): ";
            cin >> ataque;
        } while (ataque < 1 || ataque > 4 || rival.ataques[ataque - 1].pp <= 0);

        jugador.vida -= rival.ataques[ataque - 1].danio;
        rival.ataques[ataque - 1].pp--;
        cout << rival.nombre << " uso " << rival.ataques[ataque - 1].nombre << "!\n";
        if (jugador.vida <= 0) {
            cout << jugador.nombre << " se ha debilitado!\n";
            idx1++;
        }
    }

    if (idx1 >= (int)equipo1.size()) {
        cout << "\nJugador 2 ha ganado la batalla!\n";
    } else {
        cout << "\nJugador 1 ha ganado la batalla!\n";
    }
}

#endif
