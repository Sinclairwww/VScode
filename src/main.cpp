#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:
    void backtrace ( vector< vector< int > >& graph, vector< vector< int > >& res, vector< int >& path, int start, int dest ) {
        if ( start == dest ) {
            res.push_back ( path );
            return;
        }
        for ( int i = 0; i < graph[ start ].size (); i++ ) {
            path.push_back ( graph[ start ][ i ] );
            backtrace ( graph, res, path, graph[ start ][ i ], dest );
            path.pop_back ();
        }
    }
    vector< vector< int > > allPathsSourceTarget ( vector< vector< int > >& graph ) {
        vector< vector< int > > res;
        vector< int >           path;
        int                     start = 0, dest = graph.size () - 1;
        path.push_back ( 0 );
        backtrace ( graph, res, path, start, dest );
        return res;
    }
};
int main () {
    int row, col, i, j;
    cin >> row;
    vector< vector< int > > graph;
    for ( i = 0; i < row; i++ ) {
        cin >> col;
        vector< int > tmp ( col );
        for ( j = 0; j < col; j++ )
            cin >> tmp[ j ];
        graph.push_back ( tmp );
    }
    Solution                s;
    vector< vector< int > > res = s.allPathsSourceTarget ( graph );
    for ( i = 0; i < res.size (); i++ ) {
        for ( j = 0; j < res[ i ].size (); j++ )
            cout << res[ i ][ j ] << ' ';
        cout << endl;
    }
    return 0;
}
