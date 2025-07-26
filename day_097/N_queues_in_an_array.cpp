// N Queue Using Array

// link - https://www.naukri.com/code360/problems/n-queue-using-array_1170053

/*
You will be given ‘N’ queries. You need to implement ‘N’ queues using an array according to those queries. Each query will belong to one of these two types:

1 ‘X’ N: Enqueue element ‘X’  into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2 N: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
Note:
Please note that Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= S <= 1000
1 <= Q <= 10^5
1 <= P <= 2
1 <= X <= 10^5

Time limit: 1 sec
Sample Input 1:
2 5 5
1 2 1
1 3 2
1 4 1
2 2
2 1
Sample Output 1:
True
True
True
3
2
Explanation of Sample Output 1:
For this input, we have the number of queues, 'N' = 2, size of the array, 'S' = 5, and number of queries, 'Q' = 5.

Operations performed on the queue are as follows:

push(2, 1): Push element ‘2’ into the 1st queue. This returns true.
push(3, 2): Push element ‘3’ into the 2nd queue. This returns true.
push(4, 1): Push element ‘4’ into the 1st queue. This returns true.
pop(2): Pop the top element from the 2nd queue. This returns 3.
pop(1): Pop the top element from the 1st queue. This returns 2.
Sample Input 2:
3 10 7
1 11 1
1 51 2
1 26 3
1 16 2
1 5 3
2 2
2 3
Sample Output 2:
True
True
True
True
True
51
26
Explanation for Sample Output 2:
For this input, we have the number of queues, 'N' = 3, size of the array, 'S' = 10, and number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(11, 1): Push element ‘11’ into the 1st queue. This returns true.
push(51, 2): Push element ‘51’ into the 2nd queue. This returns true.
push(26, 3): Push element ‘26’ into the 3rd queue. This returns true.
push(16, 2): Push element ‘16’ into the 2nd queue. This returns true.
push(5, 3): Push element ‘5’ into the 3rd queue. This returns true.
pop(2): Pop the top element from the 2nd queue. This returns 51.
pop(3): Pop the top element from the 1st queue. This returns 26.
*/

#include <bits/stdc++.h>
using namespace std;

class NQueue
{
    int s;
    int queues;
    int *arr;
    int *next;
    int *front;
    int *back;
    int free;

public:
    NQueue(int n, int s)
    {
        this->s = s;
        this->queues = n;
        arr = new int[s];
        next = new int[s];
        front = new int[n];
        back = new int[n];
        free = 0;

        for (int i = 0; i < s; i++)
            next[i] = i + 1;
        next[s - 1] = -1; // Mark end of free list

        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            back[i] = -1;
        }
    }

    bool enqueue(int x, int m)
    {
        if (free == -1)
            return false;
        int i = free;
        free = next[i];

        arr[i] = x;

        if (front[m - 1] == -1)
        {
            front[m - 1] = i; // First element index
        }
        else
        {
            next[back[m - 1]] = i; // Link old back to new element
        }

        next[i] = -1;
        back[m - 1] = i;
        return true; // Return true
    }

    int dequeue(int m)
    {
        if (front[m - 1] == -1)
            return -1;

        int i = front[m - 1];
        front[m - 1] = next[i];

        next[i] = free;
        free = i;

        return arr[i];
    }

    // Destructor to free memory
    ~NQueue()
    {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] back;
    }
};

// Main function for testing
int main()
{
    int n, s, q;
    cout << "Enter number of queues, array size, and number of queries: ";
    cin >> n >> s >> q;

    NQueue nq(n, s);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            // Enqueue operation
            int x, m;
            cin >> x >> m;
            bool result = nq.enqueue(x, m);
            cout << (result ? "True" : "False") << endl;
        }
        else if (type == 2)
        {
            // Dequeue operation
            int m;
            cin >> m;
            int result = nq.dequeue(m);
            cout << result << endl;
        }
    }

    return 0;
}
