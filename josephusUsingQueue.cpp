#include<iostream>
#include<queue>
using namespace std;

int findWinner(int n, int k) {
	queue<int> q; // create a queue to store the players
	// add all players to the queue
	
	int i=1;
	while(i<=n){
		q.push(i);
		i++;
	}
	
	// loop until there is only one player left in the queue
	while(q.size()!=1){
	// move the first k-1 players from front to back of the queue in circular manner
		int j=1;
		while(j<k){
			int temp=q.front();
			q.push(temp);
			q.pop();
			j++;
		}
		// remove the kth player from the front of the queue and eliminate them
		q.pop();
	}
	// return the last remaining player as the winner of the game
	return q.front();
}

int main() {
	int n,k;
    cout<<"Enter the value of n and k:";
    cin>>n>>k;
	
	// call the findTheWinner function and store the result in ans
	int ans = findWinner(n,k);
	
	// print the winner to the console
	cout << "The winner is player " << ans << endl;
	return 0;
}