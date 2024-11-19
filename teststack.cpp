#include "problems.h"
#include <vector>
using namespace std;


int main()
{
    // Test your code!
    int test = -2917403;
    cout << "before: " << test << endl;
    cout << "after: " << reverseInt(test) << endl;

    cout << "find celebrity: " << endl;
    vector<vector<int>> matrix = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    for (int k = 1; k < 5; k++){
        matrix[k][0] = 1;
    }

    cout << findCelebrity(5, matrix) << endl;

    cout << "tower of hanoi: " << endl;
    towerOfHanoi(2);
}