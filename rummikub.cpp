#include <iostream>
#include <vector>
using namespace std;

struct Player
{
	string name;
	int score;
};

int main() {

	// Introduction:
	cout << "Welcome to the RUMMIKUB score keeper program!" << endl;
	cout << "I'll keep score for you since subtracting is hard!" << endl;
	cout << "If you do not want to add up all of your tiles then " << endl;
	cout << "you can enter -1 when entering a player's score and " << endl;
	cout << "I'll add up each tile for you!" << endl;
	cout << "Okay! Let's start!" << endl << endl;

	int player_count;

	int win;

	int score_limit = 0;

	bool over = false;

	int adder = 100;

	cout << "Enter player count: " << endl;

	string name;

	cin >> player_count;

	cout << "Enter score limit: " << endl;

	cin >> score_limit;

	vector<Player> players;
	vector<int> scores;

	Player temp;

	for(int i = 0; i < player_count; i++) {
		cout << "Enter player " << i + 1 << "'s name: " << endl;
		cin >> temp.name;
		temp.score = 0;
		players.push_back(temp);
		scores.push_back(0);
	}

	while(!over){
		for(int i = 0; i < player_count; i++) {
			cout << players[i].name << "\t\t| ";
		}
		cout << endl;

		for(int i = 0; i < player_count; i++) {
			cout << players[i].score << "\t\t| ";
		}
		cout << endl;

		for(int i = 0; i < player_count; i++) {
			cout << players[i].name << "'s score: " << endl;
			cin >> scores[i];
			if(scores[i] == 0) {
				win = i;
			} else if (scores[i] == -1) {
				scores[i] = 0;
				while(adder != 0) {
					cin >> adder;
					scores[i] += adder;
				}
				adder = 100;
			}
		}
		for(int i = 0; i < player_count; i++) {
			if(scores[i] != 0) {
				players[i].score -= scores[i];
			} else {
				for(int j = 0; j < player_count; j++) {
					players[i].score += scores[j];
				}
			}
		}
		for(int i = 0; i < player_count; i++) {
			if(players[i].score > score_limit) {
				over = true;;
			}
		}
	}

	for(int i = 0; i < player_count; i++) {
		cout << players[i].name << "\t\t| ";
	}
	cout << endl;

	win = score_limit;
	for(int i = 0; i < player_count; i++) {
		cout << players[i].score << "\t\t| ";
		if(players[i].score < score_limit) {
			score_limit = players[i].score;
			win = i;
		}
	}
	cout << endl;

	cout << players[win].name << " WON!!!" << endl;

	return 0;
}