#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize){
  int minLen = 200;

  for(int i = 0; i < strsSize; i++){
    int currLen = strlen(strs[i]);
    if(currLen  < minLen) minLen = currLen;
  }
char *res = calloc(minLen + 1, 1);

  for(int i = 0; i < minLen; i++){
    char c = strs[0][i];

    for(int j = 0; j < strsSize; j++){
      if(strs[j][i] != c)
        return res;
    }

    res[i] =  c;
  }

  return res;
}
