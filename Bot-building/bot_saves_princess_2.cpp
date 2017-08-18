#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
    //your logic here
     int x,y;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(grid[j][i] == 'p')
                x = i,y = j;
        }
     }
   if(r > y)
       cout<<"UP"<<endl;
   else if(r < y)
       cout<<"DOWN"<<endl;
   else if(c > x)
       cout<<"LEFT"<<endl;
    else if(c < x)
        cout<<"RIGHT"<<endl;
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
