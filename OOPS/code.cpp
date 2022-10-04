#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(int input1, int input2[])
{
  
    // Increment input2ay elements by 1
    for (int i = 0; i < input1; i++) {
        input2[i] += 1;
    }
  
    // result vector
    vector<int> res;
  
    // count variable for count of
    // largest element
    int count = 0;
  
    for (int i = 0; i < input1; i++) {
  
        // Calculate index value
        int index = abs(input2[i]) > input1 ? abs(input2[i]) / (input1 + 1)
                                    : abs(input2[i]);
  
        // Check if index equals largest element value
        if (index == input1) {
            count++;
            continue;
        }
  
        // Get element value at index
        int val = input2[index];
  
        // Check if element value is negative, positive
        // or greater than input1
        if (val < 0) {
            res.push_back(index - 1);
            input2[index] = abs(input2[index]) * (input1 + 1);
        }
        else if (val > input1)
            continue;
        else
            input2[index] = -input2[index];
    }
  
    // If largest element occurs more than once
    if (count > 1)
        res.push_back(input1 - 1);
  
    if (res.size() == 0)
        res.push_back(-1);
    else
        sort(res.begin(), res.end());
  
    return res;
}

int main() {
  int arr[] = {3, 3, 4, 4, 5};
  for (auto it : duplicates(5, arr))
  {
    cout << it << endl;
  }
}
