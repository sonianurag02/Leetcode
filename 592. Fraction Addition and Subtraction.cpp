// ------------------------------- Approach - 1 ---------------------------------

class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0;
        int deno = 1;

        int n = expr.length();
        int i = 0;

        while(i < n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if(expr[i] == '+' || expr[i] == '-'){
                i++;
            }

            // Build the current numerator
            while(i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++; // Numerator / Denominator // Skipping the divisor character '/'

            if(isNeg){
                currNume *= -1;
            }

            // Build the current Denominator
            while(i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currDeno = (currDeno*10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        int GCD = abs(__gcd(nume, deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};