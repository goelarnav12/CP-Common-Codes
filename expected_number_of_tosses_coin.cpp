int main(){
	cin.tie(0)->sync_with_stdio(0);

	string S;
	cin >> S;

	int n = S.size();

	vector<int> LPS(n), LIPS(n), LPSH(n), LPST(n);

	//initialize base cases
	LIPS[0] = 0;
	LPS[0] = 0;
	if(S[0] == 'H'){
		LPSH[0] = 0;
		LPST[0] = -1;
	} else {	// S[0] == 'T'
		LPSH[0] = -1;
		LPST[0] = 0;
	}

	for(int i=1; i<n; i++){

		// set LPS[i] and LIPS[i]
		if(S[i] == 'H'){
			LPS[i] = LPSH[i-1] + 1;
			LIPS[i] = LPST[i-1] + 1;
		} else {	// S[i] == 'T'
			LPS[i] = LPST[i-1] + 1;
			LIPS[i] = LPSH[i-1] + 1;
		}

		// set LPSH[i] and LPST[i]
		if(S[LPS[i]] == 'H'){
			LPSH[i] = LPS[i];
			LPST[i] = (LPS[i] > 0 ? LPST[LPS[i]-1] : -1);
		} else {	// S[LPS[i]] == 'T'
			LPST[i] = LPS[i];
			LPSH[i] = (LPS[i] > 0 ? LPSH[LPS[i]-1] : -1);
		}
	}

	vector<int> val(n);  // the (n+1)th column of the matrix
	vector<int> pref(n);	// prefix sums of val
	pref[0] = 2;
	val[0] = 2;

	for(int i=1; i<n; i++){
		val[i] = 2 + pref[i-1] - (LIPS[i]-1 >= 0 ? pref[LIPS[i]-1] : 0);
		pref[i] = pref[i-1] + val[i];
	}

	cout << pref[n-1] << "\n";
}
