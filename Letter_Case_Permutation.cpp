#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string str) {
        // Resultant vector to store all permutations
        std::vector<std::string> permutations;

        // Utility lambda function to perform a Depth-First Search (DFS) for all possible letter case combinationss
        std::function<void(int)> dfs = [&](int index) {
            // Base case: if we reach the end of the string, add the current permutation to the results
            if (index >= str.size()) {
                permutations.emplace_back(str);
                return;
            }

            // Recursive case: continue with the next character without changing the current one
            dfs(index + 1);

            
            // Only if the current character is alphabetical (either uppercase or lowercase)
            // we toggle its case and recursively continue
            if (isalpha(str[index])) {
                // Toggle the case of the current character: lowercase to uppercase or vice versa
                // XOR with 32 takes advantage of the fact that the ASCII values of upper and lower case
                // letters differ by exactly 32
                str[index] ^= 32;

                // Recursive call with the case of the current character toggled
                dfs(index + 1);

                // Optional: Toggle the case back if you want to use the original string elsewhere
                // after this function call. If str is not used after this, you can omit this step.
                // str[index] ^= 32;
            }
        };

        // Start DFS from index 0
        dfs(0);

        // Return all generated permutations
        return permutations;
    }

};

