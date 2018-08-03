
#include <stdio.h>
#include <string.h>
#include <iostream>

#include <string>

using namespace std;

#define T_MAX 	10
#define N_MAX	50 	// 1 ~ 50
#define LEN		100

#define debug	printf

int board[N_MAX][N_MAX];
int t;
int n;

string pattern, word;
int cache[LEN+1][LEN+1]; 

bool match2(int p, int s)
{
	int i;
	int& ret = cache[p][s];

	if (ret != -1)
		return ret;

	while (p < pattern.size() && s < word.size()
			&& (word[s] == '?' || pattern[p] == word[s]))
	{
		++p;
		++s;
	}

	if (p == pattern.size())
		return ret = (s == word.size());

	if (pattern[p] == '*')
		for (i=0; s + i <= word.size(); i++)
			if (match2(p + 1, s + i))
				return ret = 1;

	return ret = 0;
}

bool match3(int p, int s)
{
	int i;
	int& ret = cache[p][s];

	if (ret != -1)
		return ret;

	if (p < pattern.size() && s < word.size()
			&& (word[s] == '?' || pattern[p] == word[s]))
		return ret = match3(p+1, s+1);

	if (p == pattern.size())
		return ret = (s == word.size());

	if (pattern[p] == '*')
		if (match3(p + 1, s) || (s < word.size() && match3(p, s+1)))
			return ret = 1;

	return ret = 0;
}

bool match(const string& p, const string& s)
{
	int i, pos = 0;
	while (pos < p.size() && pos < s.size()
			&& (p[pos] == '?' || p[pos] == s[pos]))
		++pos;


	if (pos == p.size())
		return pos == s.size();

	if (p[pos] == '*')
		for (i=0; pos + i <= s.size(); i++)
			if (match(p.substr(pos+1), s.substr(pos + i)))
				return true;

	return false;
}

int main()
{
	int i, j, k, n;

	// Read from file
	freopen("wildcard_sample.txt", "r", stdin);

	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		// match()
		/*
		string pattern, word;
		cin >> pattern;
		scanf("%d", &n);

		for (j=0; j<n; j++)
		{
			cin >> word;
			if (match(pattern, word))
				cout << word << endl;
		}
		*/

		// match2
		cin >> pattern;
		scanf("%d", &n);

		memset(cache, -1, sizeof(cache));
		for (j=0; j<n; j++)
		{
			word.clear();
			cin >> word;
			if (match(0, 0))
				cout << word << endl;
		}

	}

	return 0;
}

