#include <vector>
#include <algorithm>

using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  // Write your code here.

  sort(redShirtSpeeds.begin(),redShirtSpeeds.end());
  sort(blueShirtSpeeds.begin(),blueShirtSpeeds.end());
  int n = blueShirtSpeeds.size();
  if(fastest) {
    // will return max possible speed.
    int maxPossSpeed = 0;
    int mid = (0 + n-1) / 2;
    for(int i=mid+1;i<n;i++) {
      maxPossSpeed += redShirtSpeeds[i] + blueShirtSpeeds[i];
    }

    return maxPossSpeed + max(redShirtSpeeds[mid] , blueShirtSpeeds[mid]);
  } else {
    // will return min possible speed
    int minPossSpeed = 0;

    for(int i=0;i<n;i++) {
      minPossSpeed += max(redShirtSpeeds[i] , blueShirtSpeeds[i]);
    }
    
    return minPossSpeed;
  }
}


int main(int argc, char const *argv[])
{
  
  return 0;
}
