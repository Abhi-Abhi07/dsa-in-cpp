#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    // int parent[12]={-1,0,1,1,0,4,4,3,3,7,7,10};
    // int level = 7;
    // vector<vector<int>>m(level,vector<int>(12,-1));

    // Iterative way
    // for(int i=1; i<7; i++){
    //     for(int j=0; j<12; j++){
    //         if(i==1){
    //             m[i][j] = parent[j];
    //         }else{
    //             int first_parent = parent[j];
    //             if(first_parent == -1) continue;
    //             m[i][j] = m[i-1][first_parent];
    //         }
    //     }
    // }



    // Binary Lifting
    int parent[12]={-1,0,1,1,0,4,4,3,3,7,7,10};
    
    // 2^3 is 8, which is enough for 12 nodes (max height < 12)
    int n = 12;
    int max_log = 4; 
    vector<vector<int>> m(max_log, vector<int>(12, -1));

    // Initialize 2^0 jumps (direct parents)
    for(int j=0; j<12; j++) {
        m[0][j] = parent[j];
    }
    for(int i=1; i<max_log; i++){
        for(int j=0; j<12; j++){
            int intermidiate_parent = m[i-1][j];
            if(intermidiate_parent != -1){
                m[i][j] = m[i-1][intermidiate_parent];
            }else{
                m[i][j] = -1;
            }
        }
    }

    // Printing the table
    cout<<endl<<endl;
    for(int i=0; i < max_log; i++){
        cout << "2^" << i << " jump (size " << (1<<i) << "): ";
        for(int j=0; j<12; j++){
            if(m[i][j] >= 0 && m[i][j] < 10) cout << " "; // Formatting
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}