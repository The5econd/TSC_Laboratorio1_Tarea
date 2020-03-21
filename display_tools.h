//
// Created by dese2 on 3/20/2020.
//
#ifndef TAREA1_DISPLAY_TOOLS_H
#define TAREA1_DISPLAY_TOOLS_H
#endif //TAREA1_DISPLAY_TOOLS_H

using namespace std;
void showMatrix(Matrix k){
    for (int i = 0; i < k.at(0).size() ; i++) {
        cout << "[\t";
        for (int j = 0; j < k.size() ; j++) {
            cout << k.at(i).at(j) << "\t";
        }
        cout << "]\n";
    }
}