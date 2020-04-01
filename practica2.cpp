#include <vector>
#include <iostream>
#include "stdlib.h"
#include "math.h"
#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

void readCoordinates(ifstream &file, int n, item* item_list){
    float e; float r;
    for(int i=0; i<n; i++){
      file >> e >> r;
      item_list[i].setIntFloat(e,r);
    }
}

void readMesh(mesh m,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<m.getNode(i).getX()<<endl;
    }
    
}


int main() {
    char filename[10];
    string line;
    mesh m;
    ifstream file;
    float k,Q;
    int n_nodes,n_elements,n_neu,n_rich;
    
    do{
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        file.open(filename);
    }while(!file);
    file >> k >> Q;
    file >> n_nodes >> n_elements >> n_rich >> n_neu;
    
    file >> line;
    

    m.setParameters(k, Q);
    m.setSizes(n_nodes, n_elements, n_rich, n_neu);
    m.createData();

    readCoordinates(file,n_nodes,m.getNodes());

    file.close();
    readMesh(m,n_nodes);


    return 0;
}