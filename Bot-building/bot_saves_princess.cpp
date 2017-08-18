#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int x,y,mx,my;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(grid[j][i] == 'p')
                x = i,y = j;
            if(grid[j][i] == 'm')
                mx = i,my = j;
        }
     }
    if(y > my ) {
        for(int i = 0;i < y-my;i++)
            cout<<"DOWN"<<endl;
    }
    else {
        for(int i = 0;i < my-y;i++) 
            cout<<"UP"<<endl;
    }
    if(x > mx ) {
        for(int i = 0;i < x-mx;i++)
            cout<<"RIGHT"<<endl;
    }
    else {
        for(int i = 0;i < mx-x;i++) 
            cout<<"LEFT"<<endl;
    }
    
    
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
