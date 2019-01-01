/** Never thought of using a stack (never used it before). Good to know.

	Probably should watch for order in an if statement: if(case 1 || case 2)
**/

class Solution {
    public:
    bool isValid(string s) {
        stack<char> bracket_stack;

        for(char c : s) {
            switch(c) {
				// Pushing opposite bracket for simplicity (to reduce the number of cases).
                case '(': bracket_stack.push(')'); break;
                case '[': bracket_stack.push(']'); break;
                case '{': bracket_stack.push('}'); break;
                default:
					// Had wrong order in an 'if' statement which caused a lot of problems.
                    if(bracket_stack.empty() || bracket_stack.top() != c) return false;
                    else bracket_stack.pop();
            }
        }
        return bracket_stack.empty();
    }
};
