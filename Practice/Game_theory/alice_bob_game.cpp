#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the sillyGame function below.
 */
string sillyGame(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime)); 

    prime[0] = false;
    prime[1] = false;
    int numPrimes = 0;
    cout << "n is : " << n << endl; 
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        {
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) if (prime[p] == true) numPrimes++;
    
    if (numPrimes%2)
    {
        return "Alice";
    }
    else
    {
        return "Bob";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = sillyGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
