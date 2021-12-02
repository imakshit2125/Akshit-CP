#include<iostream>
#include <queue>
using namespace std;
 
// An entry in queue used in BFS
struct queue_entry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};
 
// This function returns minimum number of dice throws required to
// Reach last cell from 0'th cell in a snake and ladder game.
// move[] is an array of size N where N is no. of cells on board
// If there is no snake or ladder from cell i, then move[i] is -1
// Otherwise move[i] contains cell to which snake or ladder at i
// takes to.
int getMinDiceThrows(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    queue<queue_entry> q;
 
    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queue_entry s = {0, 0};  // distance of 0't vertex is also 0
    q.push(s);  // Enqueue 0'th vertex
 
    // Do a BFS starting from vertex at index 0
    queue_entry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry
 
        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;
 
        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queue_entry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
 
    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return qe.dist;
}
 
// Driver program to test methods of graph class
int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int move[N];
    for (int i = 0; i<N; i++)
        move[i] = -1;
 
    // Ladders
    move[2] = 21;
    move[4] = 7;
    move[10] = 25;
    move[19] = 28;
 
    // Snakes
    move[26] = 0;
    move[20] = 8;
    move[16] = 3;
    move[18] = 6;
 
    cout << "Min Dice throws required is " << getMinDiceThrows(move, N);
    return 0;
}