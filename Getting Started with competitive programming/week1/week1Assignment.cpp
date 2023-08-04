//Code by Pranav Naik
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> play_game(int t, vector<pair<pair<int, int>, pair<vector<int>, vector<int>>>>& test_cases) {
    vector<string> results;
    
    for (int i = 0; i < t; i++) {
        int n = test_cases[i].first.first;
        int m = test_cases[i].first.second;
        vector<int>& yudhisthira_asthras = test_cases[i].second.first;
        vector<int>& duryodhana_asthras = test_cases[i].second.second;
        
        sort(yudhisthira_asthras.rbegin(), yudhisthira_asthras.rend());
        sort(duryodhana_asthras.rbegin(), duryodhana_asthras.rend());
        
        int yudhisthira_count = n;
        int duryodhana_count = m;
        
        while (yudhisthira_count > 0 && duryodhana_count > 0) {
            int yudhisthira_chosen = yudhisthira_asthras.back();
            int duryodhana_chosen = duryodhana_asthras.back();
            
            yudhisthira_asthras.pop_back();
            duryodhana_asthras.pop_back();
            
            int ability_value_1 = yudhisthira_chosen - duryodhana_chosen;
            int ability_value_2 = duryodhana_chosen - yudhisthira_chosen;
            
            if (ability_value_1 > 0) {
                yudhisthira_asthras.push_back(ability_value_1);
                yudhisthira_count++;
            }
            
            if (ability_value_2 > 0) {
                duryodhana_asthras.push_back(ability_value_2);
                duryodhana_count++;
            }
            
            yudhisthira_count--;
            duryodhana_count--;
            
            sort(yudhisthira_asthras.rbegin(), yudhisthira_asthras.rend());
            sort(duryodhana_asthras.rbegin(), duryodhana_asthras.rend());
        }
        
        if (yudhisthira_count > 0 && duryodhana_count == 0) {
            results.push_back("Yudhisthira");
        } else if (yudhisthira_count == 0 && duryodhana_count > 0) {
            results.push_back("Duryodhana");
        } else {
            results.push_back("Draw");
        }
    }
    
    return results;
}

int main() {
    int t;
    cin >> t;
    
    vector<pair<pair<int, int>, pair<vector<int>, vector<int>>>> test_cases;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        vector<int> yudhisthira_asthras(n);
        vector<int> duryodhana_asthras(m);
        
        for (int j = 0; j < n; j++) {
            cin >> yudhisthira_asthras[j];
        }
        
        for (int j = 0; j < m; j++) {
            cin >> duryodhana_asthras[j];
        }
        
        test_cases.push_back(make_pair(make_pair(n, m), make_pair(yudhisthira_asthras, duryodhana_asthras)));
    }
    
    vector<string> results = play_game(t, test_cases);
    
    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}

/*
sample test cases:
Sample Input
6
1 3
9
1 2 3
2 3
1 2
1 1 1
3 2
1 2 3
1 1
3 3
1 1 1
2 2 2
10 10
1 2 3 3 2 2 1 1 2 2
3 3 3 3 2 1 1 1 1 1
10 10
1 2 3 4 5 6 7 8 9 10
6 7 8 9 10 11 1 1 1 1


Sample Output
Yudhisthira
Draw
Yudhisthira
Duryodhana
Draw
Draw

Public test cases : 
Test Case 1	
10
39 6
84 94 10 90 30 64 37 35 27 3 54 47 57 17 96 86 74 84 64 37 85 98 82 15 35 1 94 73 13 67 7 92 1 45 96 42 85 77 16 
2 29 48 34 40 89 
50 5
79 75 99 1 28 12 63 69 48 41 50 94 58 22 73 44 50 97 81 25 88 78 31 72 15 89 25 30 20 72 15 45 70 59 26 34 81 48 50 89 17 61 19 62 54 70 72 29 14 71 
5 19 98 4 89 
44 14
58 100 21 23 67 4 50 11 14 67 85 22 65 100 32 93 77 5 65 71 15 52 40 29 3 58 34 84 50 85 74 88 27 25 20 24 53 24 56 5 57 75 29 10 
75 28 88 98 89 82 59 59 36 37 66 44 19 92 
23 10
27 18 55 64 36 73 11 54 28 73 34 93 56 95 68 100 39 79 2 12 93 27 14 
84 57 90 11 5 9 52 51 37 15 
2 1
68 64 
43 
39 10
45 25 97 44 17 67 60 66 40 32 57 1 87 46 87 80 56 2 93 93 59 87 42 100 74 67 47 85 62 91 1 93 24 30 26 79 18 33 42 
68 76 23 63 86 6 72 28 31 42 
24 13
32 15 80 59 74 50 96 23 82 51 38 11 14 23 100 32 79 56 78 76 25 79 53 14 
18 22 5 67 39 64 80 3 62 94 31 31 43 
13 25
21 81 35 67 17 55 14 40 18 4 45 54 39 
82 29 3 27 96 40 1 2 93 63 29 49 78 92 99 27 99 61 54 47 38 66 51 7 76 
29 34
95 18 19 76 25 24 25 54 89 86 83 85 75 67 18 57 68 74 72 6 22 26 88 45 55 94 58 61 46 
38 28 91 89 63 36 16 20 51 35 10 100 18 40 18 20 1 90 58 95 53 90 34 93 82 5 29 58 84 75 15 82 43 97 
45 29
59 85 52 32 83 88 90 75 44 87 47 6 78 91 84 60 44 82 27 67 65 39 90 63 23 15 90 53 85 58 5 25 53 90 61 46 60 3 92 39 48 73 91 19 99 
95 20 66 63 91 65 63 57 34 7 57 12 64 53 20 79 45 61 52 67 15 11 25 79 49 15 13 5 2
Yudhisthira\n
Yudhisthira\n
Yudhisthira\n
Yudhisthira\n
Yudhisthira\n
Yudhisthira\n
Yudhisthira\n
Duryodhana\n
Duryodhana\n
Yudhisthira

Test Case 2	
10
7 6
16 42 85 42 26 42 29 
38 7 45 21 83 83 
7 9
6 21 92 81 61 61 14 
24 15 18 20 94 83 94 65 98 
7 2
44 23 26 11 63 99 45
164 147
5 1
54 50 73 95 47
319
6 10
36 40 76 54 3 69
220 20 16 6 10 2 4 0 0 0
3 10
29 41 66 
51 100 40 94 29 71 35 87 91 65 
2 9
9 56
40 25 0 0 0 0 0 0 0
5 3
81 39 93 86 44 
2 82 74 
8 3
64 19 22 91 87 84 28 31 
3 72 87 
5 2
80 95 98 99 96 
71 60
Yudhisthira\n
Duryodhana\n
Draw\n
Draw\n
Draw\n
Duryodhana\n
Draw\n
Yudhisthira\n
Yudhisthira\n
Yudhisthira

*/