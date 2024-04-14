// // C++ program for Knight Tour problem
// #include <bits/stdc++.h>
// using namespace std;

// #define N 8

// int solveKTUtil(int x, int y, int movei, int sol[N][N],
// 				int xMove[], int yMove[]);

// /* A utility function to check if i,j are
// valid indexes for N*N chessboard */
// int isSafe(int x, int y, int sol[N][N])
// {
// 	return (x >= 0 && x < N && y >= 0 && y < N
// 			&& sol[x][y] == -1);
// }

// /* A utility function to print
// solution matrix sol[N][N] */
// void printSolution(int sol[N][N])
// {
// 	for (int x = 0; x < N; x++) {
// 		for (int y = 0; y < N; y++)
// 			cout << " " << setw(2) << sol[x][y] << " ";
// 		cout << endl;
// 	}
// }

// /* This function solves the Knight Tour problem using
// Backtracking. This function mainly uses solveKTUtil()
// to solve the problem. It returns false if no complete
// tour is possible, otherwise return true and prints the
// tour.
// Please note that there may be more than one solutions,
// this function prints one of the feasible solutions. */
// int solveKT()
// {
// 	int sol[N][N];

// 	/* Initialization of solution matrix */
// 	for (int x = 0; x < N; x++)
// 		for (int y = 0; y < N; y++)
// 			sol[x][y] = -1;

// 	/* xMove[] and yMove[] define next move of Knight.
// 	xMove[] is for next value of x coordinate
// 	yMove[] is for next value of y coordinate */
// 	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
// 	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 	// Since the Knight is initially at the first block
// 	sol[0][0] = 0;

// 	/* Start from 0,0 and explore all tours using
// 	solveKTUtil() */
// 	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
// 		cout << "Solution does not exist";
// 		return 0;
// 	}
// 	else
// 		printSolution(sol);

// 	return 1;
// }

// /* A recursive utility function to solve Knight Tour
// problem */
// int solveKTUtil(int x, int y, int movei, int sol[N][N],
// 				int xMove[8], int yMove[8])
// {
// 	int k, next_x, next_y;
// 	if (movei == N * N)
// 		return 1;

// 	/* Try all next moves from
// 	the current coordinate x, y */
// 	for (k = 0; k < 8; k++) {
// 		next_x = x + xMove[k];
// 		next_y = y + yMove[k];
// 		if (isSafe(next_x, next_y, sol)) {
// 			sol[next_x][next_y] = movei;
// 			if (solveKTUtil(next_x, next_y, movei + 1, sol,
// 							xMove, yMove)
// 				== 1)
// 				return 1;
// 			else

// 			// backtracking
// 				sol[next_x][next_y] = -1;
// 		}
// 	}
// 	return 0;
// }

// // Driver Code
// int main()
// {
// 	// Function Call
// 	solveKT();
// 	return 0;
// }

// // This code is contributed by ShubhamCoder


// C++ program to find minimum steps to reach to
// specific cell in minimum moves by Knight

#include <bits/stdc++.h>
using namespace std;

// structure for storing a cell's data
struct cell {
	int x, y;
	int dis;
	cell() {}
	cell(int x, int y, int dis)
		: x(x)
		, y(y)
		, dis(dis)
	{
	}
};

// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}

// Method returns minimum step
// to reach target position
int minStepToReachTarget(int knightPos[], int targetPos[],
						int N)
{
	// x and y direction, where a knight can move
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// queue for storing states of knight in board
	queue<cell> q;

	// push starting position of knight with 0 distance
	q.push(cell(knightPos[0], knightPos[1], 0));

	cell t;
	int x, y;
	bool visit[N + 1][N + 1];

	// make all cell unvisited
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;

	// visit starting state
	visit[knightPos[0]][knightPos[1]] = true;

	// loop until we have one element in queue
	while (!q.empty()) {
		t = q.front();
		q.pop();

		// if current cell is equal to target cell,
		// return its distance
		if (t.x == targetPos[0] && t.y == targetPos[1])
			return t.dis;

		// loop for all reachable states
		for (int i = 0; i < 8; i++) {
			x = t.x + dx[i];
			y = t.y + dy[i];

			// If reachable state is not yet visited and
			// inside board, push that state into queue
			if (isInside(x, y, N) && !visit[x][y]) {
				visit[x][y] = true;
				q.push(cell(x, y, t.dis + 1));
			}
		}
	}
}

// Driver code
int main()
{
	int N = 30;
	int knightPos[] = { 1, 1 };
	int targetPos[] = { 30, 30 };

	// Function call
	cout << minStepToReachTarget(knightPos, targetPos, N);
	return 0;
}
