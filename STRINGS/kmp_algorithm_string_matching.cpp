// COUNTING OCCURENCES OF ALL THE PATTERNS IN A GIVEN TEXT.
// CAN BE MODIFIED TO FIND INDEX OF ALL OCCURENCES BY USING (I-J) KIND OF LOGIC.
// CAN BE USED TO CHECK THE PRESENCE OF PATTERN IN A GIVEN TEXT.

vector<int> lps(string str){
  int n = str.length();
  vector<int> lparray(n, 0);
  lparray[0] = 0;
  
  int j=0;
  for(int i=1; i<n; i++){
    while(str[i]!=str[j] and j) 
      j = lparray[j-1];
    
    if(str[i]==str[j]) {
      lparray[i] = j+1;
      j++;
    }
  }
  return lparray;
}
 
int kmp(string txt, string pat){
  int n = txt.length(), m = pat.length();
  int ans = 0;
  
  vector<int> lparray = lps(pat);
  
  int i = 0, j = 0;
  while(i<n){
    while(txt[i]!=pat[j] and j){
      j = lparray[j-1];
    } 
    if(txt[i]==pat[j]) j++;
    
    if(j==m){
      ans++;
      j = lparray[j-1];
    }
    i++;
  }
  
  return ans;
}
