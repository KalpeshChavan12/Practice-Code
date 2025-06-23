// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

void reverse(char *s, char* e)
{
    if(!(*s))
        return;
    
    while(s < e)
    {
        char tmp = *s;
        *s = *e;
        *e = tmp;
        s++;
        e--;
    }
}

void reverse2(char* str)
{
    char * s1=str;
    char *s=s1, *e;
    while(*s1)
    {
        if(*s1 == ' ')
        {
            reverse(s, s1 - 1);
            s = s1+1;
        }
        s1++;
    }
    reverse(s, s1-1);
}


char* reverseWords(char* s) {
    int scount =0, len=0;
    char *s1=s;
    char *source=s;
    while(*s1 && *source)
    {
        *s1 = *source; 
        if(*s1 == ' ')
        {   
            while(*source && *source == ' ')
                source++;
        }
        else
            source++;
        s1++;
        len++;
    }
    
    *s1 = 0;

    if(*s == ' ')
    { 
        s++;
        len--;
    }
    if(s[len-1] == ' ')
    {
        s[len-1] = 0;
        len--;
    }

    //printf("|%s| %d", s, len);
    reverse2(s);
    //printf("|%s| %d", s, len);
    reverse(s, s+len-1);
    return s;
}

