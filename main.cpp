/*
 * Descripción
 * John Carter está huyendo a caballo de los indios de Arizona. Adelante de él ve el horizonte lleno de cactus. Rápidamente se aprende sus posiciones y voltea a ver a los indios que lo persiguen. Como no puede ver por dónde irá, piensa en algunas posiciones en el horizonte a las cuales dirigir su caballo para escapar. Ayuda a John Carter a saber cuánto espacio tiene para pasar entre los cactus para cada posición que esté considerando.
 * Entrada
 * Un entero NN seguido de las posiciones C1,...,CNC1,...,CN de los cactus en el horizonte. Un entero MM seguido de las posiciones P1,...,PMP1,...,PM consideradas. Puedes suponer que 2<=N,M<=10,0002<=N,M<=10,000, que todas las posiciones están en el rango de −100,000−100,000 a 100,000100,000 y que min{CiCi} <=Pj<=<=Pj<= max{CiCi} para toda 1<=j<=M1<=j<=M.
 * Salida
 * MM enteros D1,...,DMD1,...,DM, donde DjDj es la distancia entre los dos cactus que pasará John Carter en la posición PjPj (o 00 si John Carter se estrellará con un cactus).
 * Ejemplo
 *  Entrada
 * 5
 * 3 1 4 5 9
 * 4
 * 2 7 1 8
 * Salida
 * 2 4 0 4
 */

/* 
 * File:   main.cpp
 * Author: Zelzin M. Márquez N.
 *
 * Created on 25 de junio de 2016, 10:21 PM
 */

#include <cstdlib>
#include <iostream>       // std::cin
#include <bitset>         // std::bitset

using namespace std;

/*  
 * 
 */
int main(int argc, char** argv) {
    //Número de cáctus
    int position, noCactus, space, noSpaces, moreSpace;
    cin >> noCactus;
    bitset<10000> cactusPositions;
    for(int i=0; i<noCactus; i++){
        cin >> position;
        cactusPositions.set(position-1);
    }
    cin >> noSpaces;
    //cout << "cactusPositions: " << cactusPositions << '\n';
    for(int i=0; i<noSpaces; i++){
        int left = 0, right = 0;
        cin >> space;
        moreSpace = space;
        if(cactusPositions[space-1])
            cout << 0;
        else{
            do{
                space--;
                right++;
//                cout << "space: " << space << '\n';
//                cout << "cactusPositions[space]: " << cactusPositions[space-1] << '\n';
//                cout << "left: " << left << '\n';
//                cout << "right: " << right << '\n';
            }while(!cactusPositions[space-1]);
            
            do{
                moreSpace++;
                left++;
//                cout << "moreSpace: " << moreSpace << '\n';
//                cout << "cactusPositions[space]: " << cactusPositions[moreSpace-1] << '\n';
//                cout << "left: " << left << '\n';
//                cout << "right: " << right << '\n';
            }while(!cactusPositions[moreSpace-1]);
            cout << left + right;
        }
//        cout << "left: " << left << '\n';
//        cout << "right: " << right << '\n';
    }
    //cout << "cactusPositions: " << cactusPositions << '\n';
    return 0;
}
