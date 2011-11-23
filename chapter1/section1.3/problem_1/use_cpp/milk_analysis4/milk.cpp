#include <iostream>
#include <fstream>

#define MAXP 1000

using namespace std;

int main() {
    ifstream in("milk.in");
    ofstream out("milk.out");
    
    int N, M;
    int P[MAXP+1];
    
    in >> N >> M;
    for (int i = 0; i <= MAXP; i++) P[i]=0;
    for (int i = 0; i < M; i++) {
        int price, amt;
        in >> price >> amt;
        
         // we can add amounts that cost the same price
        // since x gallons costing c cents and
        //          y gollons costing c cents
        // is the same as
        //      x+y gallons costing c cents
        P[price] += amt;
    }
    
    // greedy choice: take as much of the item that
    // has the least price per gallon
    int res = 0;
    for (int p = 0; p<=MAXP && N>0; p++) {
        if (P[p]>0) {
            res+=p*(N<P[p]?N:P[p]);
            N-=P[p];
        }
    }
    out << res << endl;
    
    in.close();
    out.close();
    
    return 0;
}
