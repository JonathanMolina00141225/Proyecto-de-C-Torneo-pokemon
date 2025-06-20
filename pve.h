#ifndef PVE_H
#define PVE_H

#include "pokemon_common.h"
#include <cstdlib>
#include <ctime>
#include <limits>

Pokemon seleccionarPokemonUsuario(vector<Pokemon>& pokemons) {
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

Pokemon seleccionarPokemonRandom(const vector<Pokemon>& pokemons) {
    if (pokemons.empty()) return Pokemon{};
    int idx = rand() % pokemons.size();
    return pokemons[idx];
}

void batallaPvE(vector<Pokemon>& pokemonsUsuario, vector<Pokemon>& pokemonsEnemigos) {
    srand(static_cast<unsigned>(time(0)));

    cout << "¡Empieza el torneo PvE infinito!\n";

    while (true) {
        if (pokemonsUsuario.empty()) {
            cout << "No tienes más Pokémon para luchar. Fin del torneo.\n";
            break;
        }

        cout << "\nSelecciona un Pokémon para la batalla:\n";
        Pokemon usuario = seleccionarPokemonUsuario(pokemonsUsuario);
        Pokemon enemigo = seleccionarPokemonRandom(pokemonsEnemigos);

        cout << "Tu Pokémon: " << usuario.nombre << " vs Enemigo: " << enemigo.nombre << "\n";

        // Restaurar vida y pp de ambos Pokémon (puedes ajustar si guardas valores máximos)
        usuario.vivo = true;
        enemigo.vivo = true;

        // Batalla 1vs1
        while (usuario.vivo && enemigo.vivo) {
            // Turno usuario
            cout << "\nTu Pokémon: " << usuario.nombre << " (Vida: " << usuario.vida << ")\n";
            cout << "Enemigo: " << enemigo.nombre << " (Vida: " << enemigo.vida << ")\n";

            cout << "Ataques:\n";
            for (int i = 0; i < 4; ++i) {
                cout << i + 1 << ". " << usuario.ataques[i].nombre << " (Daño: " << usuario.ataques[i].danio
                     << ", PP: " << usuario.ataques[i].pp << ")\n";
            }
            int ataqueUsuario;
            do {
                cout << "Selecciona ataque (1-4): ";
                cin >> ataqueUsuario;
            } while (ataqueUsuario < 1 || ataqueUsuario > 4 || usuario.ataques[ataqueUsuario - 1].pp <= 0);

            enemigo.vida -= usuario.ataques[ataqueUsuario - 1].danio;
            usuario.ataques[ataqueUsuario - 1].pp--;
            cout << usuario.nombre << " uso " << usuario.ataques[ataqueUsuario - 1].nombre << "!\n";

            if (enemigo.vida <= 0) {
                cout << enemigo.nombre << " fue debilitado. ¡Ganaste esta batalla!\n";
                break;
            }

            // Turno enemigo aleatorio
            int ataqueEnemigo = rand() % 4;
            while (enemigo.ataques[ataqueEnemigo].pp <= 0) { // Busca ataque con pp disponible
                ataqueEnemigo = rand() % 4;
            }

            usuario.vida -= enemigo.ataques[ataqueEnemigo].danio;
            enemigo.ataques[ataqueEnemigo].pp--;
            cout << enemigo.nombre << " uso " << enemigo.ataques[ataqueEnemigo].nombre << "!\n";

            if (usuario.vida <= 0) {
                cout << usuario.nombre << " fue debilitado. Perdiste el torneo.\n";
                return; // Termina el torneo infinito
            }
        }

        cout << "¡Prepárate para la próxima batalla!\n";
    }
}

#endif
