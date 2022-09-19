#include <bits/stdc++.h>
using namespace std;

class Fabric {
  public:
    string color;
    int durability;
    int uid;
};

int main() {
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n;
        cin >> n;
        vector<Fabric> fabrics;
        for(int i=0;i<n;i++) {
            int color,durability,uid;
            cin >>color >> durability >> uid ;
            
            // creating a new fabric.
            Fabric fabric;
            fabric.color = color;
            fabric.durability = durability;
            fabric.uid = uid;
            
            // adding to list of farics.
            fabrics.push_back(fabric);
        }

        vector<Fabric> adasList = fabrics;
        sort(adasList.begin(), adasList.end(), [](Fabric a, Fabric b)
         {
             if (a.color == b.color) {
               return a.uid < b.uid;
             }
             return a.color < b.color;
        });
        vector<Fabric> charlesList = fabrics;
        sort(charlesList.begin(), charlesList.end(), [](Fabric a, Fabric b)
         {
             if (a.durability == b.durability) {
               return a.uid < b.uid;
             }
             return a.durability < b.durability;
        });
        int ans = 0;
        for(int i=0;i<n;i++) {
            Fabric a = adasList[i];
            Fabric b = charlesList[i];
            if(a.color == b.color && a.durability == b.durability && a.uid == b.uid) {
                ans++;
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}