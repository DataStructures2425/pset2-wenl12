#include "stack.h"
using namespace std;

// Takes in an integer num and reverses it using a Stack data structure.
// reverseInt(6883) should return 3886
// reverseInt(0) should return 0
// reverseInt(-2938947) should return -7498392

vector<Stack<int>> stacks;

int reverseInt(int num)
{
    // Your code here
    bool isNegative = 0;
    int newNum = 0;
    if (num < 0){
        isNegative = 1;
        num = abs(num);
    }
    
    //flipping num first time- num is reversed
    int placeholder = num;
    int flipNum = 0;
    int rem = 0;
    while (placeholder != 0){
        flipNum *= 10;
        rem = placeholder % 10;
        flipNum += rem;
        placeholder /= 10;
    }
    flipNum *= 10;
    rem = placeholder % 10;
    flipNum += rem;
    num = flipNum;
    
    if (num > 0){
        //flips it again while putting it in stack- num is in orginal order 
        int remainder = num % 10;
        Stack<int> s;
        num /= 10;
        while (num != 0){
            remainder = num % 10;
            s.push(remainder);
            num /= 10;
        }

        //flips it again while taking nums out- num is reversed again
        while (!s.isEmpty()){
            newNum *= 10;
            newNum += s.pop();
        }
        if (isNegative){
            newNum = 0 - newNum;
        }
    }
    return newNum;
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int> >& matrix)
{   
    // Your code here
    Stack<int> celebrities;
    for (int i = 0; i < n; i++){
        celebrities.push(i);
    }
    while (celebrities.top->down != nullptr){
        int a = celebrities.pop();
        int b = celebrities.pop();
        if (matrix[a][b] == 1){
            celebrities.push(b);
        } else{
            celebrities.push(a);
        }
    }
    bool isCelebrity = true;
    for (int i = 1; i < n; i++){
        if (matrix[i][celebrities.peek()] != 1 || matrix[celebrities.peek()][i] != 0){
            isCelebrity = false;
        }
    }
    if (isCelebrity){
        return celebrities.peek();
    }
    return -1;
}


// Moves a disk from stack a to stack b if possible, otherwise
// moves disk from stack b to stack a.
void moveDisk(int a, int b)
{
    
    char stacka;
    char stackb;
    if (a == 0) stacka = 'S';
    if (a == 1) stacka = 'A';
    if (a == 2) stacka = 'D';
    if (b == 0) stackb = 'S';
    if (b == 1) stackb = 'A';
    if (b == 2) stackb = 'D';
    
    if (stacks[a].isEmpty()&& stacks[b].isEmpty()){
        cout << "no blocks to move";
        return;
    }
    
    int temp = 0;
    if (stacks[b].isEmpty() == 1 || stacks[a].peek() < stacks[b].peek()){
        temp = stacks[a].pop();
        stacks[b].push(temp);
        cout << "Move disk " << temp << " to stack " << stacka << " to stack " << stackb << endl;
    } else if (stacks[b].isEmpty() == 1 || stacks[b].peek() < stacks[a].peek()){
        temp = stacks[b].pop();
        stacks[a].push(temp);
        cout << "Move disk " << temp << " to stack " << stacka << " to stack " << stackb << endl;
    }
}
 
// Simulates the tower of Hanoi puzzle for n disks and solves it 
// using the moveDisk() fuunction. No iteration allowed!
void towerOfHanoi(int n)
{
    for (int j = 0; j <=2; j++){
        Stack<int> temp;
        stacks.push_back(temp);
    }
    for (int i = n - 1; i >= 0; i--){
        stacks[0].push(i);
    }
    
    int lastMovedStack;
    int currentStack = 0;
    if (n % 2 == 0){
        //MOVE RIGHT
        //hi
        while(!(stacks[0].isEmpty() && stacks[1].isEmpty() && !stacks[2].isEmpty())){
            //cout<<currentStack<<endl;
            //move top of current stack to 1 stack on right if works
            //if it doesnt work, go to next stack
            if (currentStack > 2){
                //cout<<"fine"<<endl;
                currentStack = 0;
            }
            if (stacks[currentStack].isEmpty() || lastMovedStack == currentStack){
                currentStack++;
                continue;
            }
            //cout << "a" << endl;
            //cout<<currentStack<<endl;
            int moveTo = (currentStack+1)%3;
            if (stacks[moveTo].isEmpty() || stacks[moveTo].peek() > stacks[currentStack].peek()){
                //cout << "p" << endl;
                moveDisk(currentStack, moveTo);
                lastMovedStack = moveTo;
            } else if (stacks[(currentStack+2)%3].isEmpty() || stacks[(currentStack+2)%3].peek() > stacks[currentStack].peek()){
                //cout << "l" << endl;
                lastMovedStack = (currentStack+2)%3;
                moveDisk(currentStack, (currentStack+2)%3);
            }
            //cout<<"ok"<<endl;
            currentStack++;
            //cout<<currentStack<<endl;
        }
    } else {
        //cout << "b" << endl;
        //MOVE LEFT
        
        while(!(stacks[0].isEmpty() && stacks[1].isEmpty() && !stacks[2].isEmpty())){
            //cout<<currentStack<<endl;
            //move top of current stack to 1 stack on right if works
            //if it doesnt work, go to next stack
            if (currentStack < 0){
                //cout<<"fine"<<endl;
                currentStack = 2;
            }
            if (stacks[currentStack].isEmpty() || lastMovedStack == currentStack){
                currentStack--;
                continue;
            }
            //cout << "a" << endl;
            //cout<<currentStack<<endl;
            int moveTo = (currentStack+2)%3;
            if (stacks[moveTo].isEmpty() || stacks[moveTo].peek() > stacks[currentStack].peek()){
                //cout << "p" << endl;
                moveDisk(currentStack, moveTo);
                lastMovedStack = moveTo;
            } else if (stacks[(currentStack+1)%3].isEmpty() || stacks[(currentStack+1)%3].peek() > stacks[currentStack].peek()){
                //cout << "l" << endl;
                lastMovedStack = (currentStack+1)%3;
                moveDisk(currentStack, (currentStack+1)%3);
            }
            //cout<<"ok"<<endl;
            currentStack--;
            //cout<<currentStack<<endl;
        }
    }
}