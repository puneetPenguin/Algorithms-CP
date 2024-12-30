// USED FOR - PATTERN MATCHING, COUNTING OCCURENCES OF PATTERN, CHECKING IF PATTERN EXISTS OR NOT, FINDING INDEX OF ALL OCCURENCES OF PATTERNS

vector<int> RabinKarp(string txt, string pat){
	int mod = 1e9+9;
	int p = 53;

	int n = txt.length(), m = pat.length();
	
	// Calculating p^i for all i's for precomputation
	vector<long long> p_pow(max(n, m));
	p_pow[0] = 1;
	for(int i=1; i<max(n, m); i++){
		p_pow[i] = (p_pow[i-1] * p) % mod;
	}

	// Calculating hash for all prefix substrings
	// hash(0..n) = sum i (0 to n)  ((s[i]-'a'+1)*p^i) % m;
	vector<long long> hash(n+1, 0);
	for(int i=0; i<n; i++){
		hash[i+1] = (hash[i] + (p_pow[i] * (txt[i]-'a'+1)) % mod) % mod;
	}
	// Calculating hash for the pattern
	long long hash_pattern = 0;
	for(int i=0; i<m; i++){
		hash_pattern += (pat[i]-'a'+1)*p_pow[i];
		hash_pattern %= mod;
	}

	// Find the occurences index
	vector<int> occurences;
	for(int i=0; i<n-m+1; i++){
		long long curr_hash = (hash[i+m] - hash[i] + mod) % mod;
		long long relative_patt_hash = (hash_pattern * p_pow[i]) % mod;
		if(curr_hash==relative_patt_hash){
			occurences.push_back(i);
		}
	}
	return occurences;
}
