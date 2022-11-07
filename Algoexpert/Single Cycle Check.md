# Single Cycle Check

You're given an array of integers where each integer represents a jump of its value in the array. For
instance, the integer 2 represents a jump of two indices forward in the array; the integer -3
represents a jump of three indices backward in the array.

If a jump spills past the array's bounds, it wraps over to the other side. For instance, ajump of -1
at index © brings us to the last index in the array. Similarly, ajump of 1 at the last index in the
array brings us to index 0.



```cpp
using namespace std;

int nextIndex(int i , vector<int> array) {
  int n = array.size();
  int nextIndex = (i + array[i]) % n;
  if(nextIndex >= 0) {
    return nextIndex;
  } else {
    return n + nextIndex;
  }
}

bool hasSingleCycle(vector<int> array) {
  // Write your code here.
  int n = array.size();
  int noOfVisitedElements = 0;
  int currentIndex = 0;
  while(noOfVisitedElements < n) {
    if(noOfVisitedElements > 0 && currentIndex == 0) {
      return false;
    }
    noOfVisitedElements++;
    currentIndex = nextIndex(currentIndex , array);
  }
  return currentIndex == 0;
}
```
