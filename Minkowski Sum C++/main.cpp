#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Print 2D vectors coordinate values
void print2DVector(vector<vector<int> > vec)
{
     // Sorting the vector for grading purpose
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
                cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

// ***TODO: Check for duplicate coordinates inside a 2D vector and delete them*** //
vector<vector<int> > delete_duplicate(vector<vector<int> > C)
{
    // Sort the C vector
    sort(C.begin(),C.end());
    // Initialize the vector that will be returned containing the non duplicated values
    vector<vector<int>> Cn;
    for (int i = 0; i < C.size(); i++){
        if (C[i] != C[i+1]){
            Cn.push_back(C[i]);
        }
    }
    
    return Cn;
}    

// ***TODO: Compute the Minkowski Sum of two vectors***//
vector<vector<int> > minkowski_sum(vector<vector<int> > A, vector<vector<int> > B)
{
    vector<vector<int>>  C;
    for (int i = 0; i < B.size(); i++){
        for ( int j = 0; j < A.size();j++){
             //Compute the current sum
            vector<int> Ci = { A[j][0] + B[i][0], A[j][1] + B[i][1] };
             // Push it back into a common vector
            C.push_back(Ci);
        }
    }
    
    C = delete_duplicate(C);
    return C;
}

int main()
{
    // ***TODO: Define the coordinates of triangle A and B using 2D vectors*** //
    vector<vector<int>> A(3,vector<int>(2));
    A = {{0,-1},{1,0},{0,1}};
    vector<vector<int>> B(3,vector<int>(2));
    B={{1,-1},{0,0},{1,1}};

    
    // Compute the minkowski sum of triangle A and B
    vector<vector<int> > C;
    C = minkowski_sum(A, B);

    // Print the resulting vector
    print2DVector(C);

    return 0;
}