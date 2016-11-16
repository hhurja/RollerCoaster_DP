// [Hunter] [Hurja] [2049410015]
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <iostream>
// put other includes here
using namespace std;

// Please fill in your USC username
const string USCusername = "hurja";

using namespace std;

struct sortByThrill {
    bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second < right.second;
    }
};

// void printVector(vector<pair<int, int> > v){
// 	cout << "coasters: " << v.size() << endl;
// 	if(v.size() > 0){
// 		for(int i = 0; i < v.size(); i++){
// 			cout << "(" << v[i].first << "," << v[i].second << ") ";
// 		}
// 		cout << endl;

// 	}
// }

int maxRollercoasters(vector < pair <int, int> > &RCs)
{
	//sorts the coasters by order of thrill factor in nlogn time
	sort(RCs.begin(), RCs.end(), sortByThrill());

	//Array keeping track of longest increasing subsequence at each position
	int *LIS = new int[RCs.size()];

	//longest increasing subsequence problem -- n^2 runtime
	int max = 0;
	int temp_max;
	for (int i = RCs.size()-1; i >= 0; i--){
		temp_max = 0;
		for (int j = i+1; j < RCs.size(); j++){
			if(RCs[j].first > RCs[i].first && LIS[j] > temp_max) temp_max = LIS[j];

		}
		LIS[i] = 1 + temp_max;
		if (LIS[i] > max) max = LIS[i];
	}

	delete [] LIS;
	return max;
}



// DO NOT EDIT BELOW THIS LINE

int main(int argc, char *argv[])
{
	vector<pair<int, int> > RCs;

	for (int i = 1; i < (argc + 1) / 2; i++)
	{
		int ti = atoi(argv[2 * i - 1]);
		int fi = atoi(argv[2 * i]);
		RCs.push_back(make_pair(ti, fi));
	}
	int answer = maxRollercoasters(RCs);
	std::ofstream out;
	out.open(USCusername + ".txt", std::ios::app);
	out << answer << endl;
	return 0;
}