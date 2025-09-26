class Solution {
public:
    //Create a list that will store the solution
    vector<string> sol;
    
    void generator(int op, int cl, string str, int n) {
        //Check the base case.
        //If number of opening and closing parentheses are equal to n..
        if(op == n && cl == n) {
            //add the string(str) to the list
            sol.push_back(str);
            return;
        }
        //if no. of opening parentheses(op) is less than n...
        if(op < n)
            //add '(' to the current string and increment the count of opening parenthesis(op)
            generator(op + 1, cl, str + '(', n);
        //if no. of closing parentheses is less than open parentheses...
        if(cl < n && op > cl)
            //add ')' to the current string and increment the count of closing parentheses(cl)
            generator(op, cl + 1, str + ')', n);
    }
    vector<string> generateParenthesis(int n) {
        //Recursively call backtracking function
        generator(0, 0, "", n);
        return sol;   
    }
};