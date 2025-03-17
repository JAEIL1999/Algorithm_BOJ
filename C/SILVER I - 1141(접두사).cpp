#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[50][52];
    int number;
    int ans = 0;
    scanf("%d",&number);

    for(int i=0;i<number;i++) scanf("%s",word[i]);

    for(int i=0;i<number-1;i++) {
        for(int j=i+1;j<number;j++) {
            if(strlen(word[i])>strlen(word[j])) {
                char temp[52];
                strcpy(temp,word+i);
                strcpy(word+i,word+j);
                strcpy(word+j,temp);
            }
        }
    }

    for(int i=0;i<number;i++) {
        int ans_count = 0;
        int len = strlen(word[i]);
        int cut = 0;
        if(i==number-1) {ans++;break;}
        for(ans_count=i+1;ans_count<number;ans_count++) {
            if(strncmp(word[i],word[ans_count],len)==0) {cut = 1;break;}
        }
        if(ans_count==number && cut == 0) ans++;
    }

    printf("%d",ans);

    return 0;
}
