#include <iostream>

using namespace std;

int menuPvP(){

    int PvPmenu;
    
    do
{
    cout<<"NOW WE'RE GOING TO SEE THE FIGHT, Player 1 vs Player 2 \n";
    cout<<"What do you want to do? \n";
    cout<<"1. Fight \n";
    cout<<"2. Backpack \n";
    cout<<"3. Pokemon \n";
    cout<<"4. Go away \n";
    cin>>PvPmenu;
} while (PvPmenu!=4);
cout<<"You left the fight \n";
}
