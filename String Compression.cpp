#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0;
        int size = chars.size();

        for (int readStart = 0, readEnd = readStart + 1; readStart < size;){
            while (readEnd < size && chars[readEnd] == chars[readStart]){
                readEnd++;
            }
            chars[writeIndex++] = chars[readStart];

            int runLength = readEnd - readStart;
            if (runLength > 1){
                for (char countChar: to_string(runLength)){
                    chars[writeIndex++] = countChar;
                }
            }
            readStart = readEnd;
        }
        return writeIndex;
    }
};