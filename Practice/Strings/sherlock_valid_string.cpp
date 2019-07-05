#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	unordered_map<char, int> umap; 	
	for(char& c : s)
	{
		if (umap.find(c) == umap.end())
		{
			umap[c] = 1;
		}
		else
		{
			umap[c] += 1 ; 
		}
	}
	int total_num_count = 0;
	int num_count = -1; 
	int greater_count = -1; 
	int total_greater_count = 0;
	
	for (auto& elem : umap)
	{
		if (num_count == -1)
		{
			num_count = elem.second;
			total_num_count ++;
		}
		else if ( ( elem.second == num_count + 1 || (num_count == 1 && total_num_count == 1 && elem.second != num_count)) && greater_count == -1 ) 
		{
			greater_count = elem.second;
			total_greater_count++;
		}
		else if (elem.second == num_count - 1 && total_greater_count == 0)
		{   // swap in this case
			greater_count = num_count; 
			num_count = elem.second;
			total_greater_count = total_num_count; 
			total_num_count = 1;
		}
		else if (elem.second == num_count) {
			total_num_count ++;
		}
		else if (elem.second == greater_count) {
			total_greater_count ++;
		}
		else
		{
			return "NO";
		}
	}

	if ( total_greater_count > 1 && (total_num_count > 1  || num_count !=1) || 
		(total_num_count > 1 && (greater_count != num_count + 1 && greater_count != -1)) )
	{
		return "NO";
	}
	else 
		return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";
    fout.close();

    return 0;
}
