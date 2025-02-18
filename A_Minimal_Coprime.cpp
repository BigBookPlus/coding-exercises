#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        if(x == 1 &&y==1) {
            cout << "1" << endl;
        }
        else{
            cout<<y-x<<endl;
        }
    }
    return 0;
}