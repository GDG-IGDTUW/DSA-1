class Solution {
    public:
        int romanToInt(string s) {
    
            int num = 0;
            int i=0;
            while (i < s.size()) {
                if (s[i]=='M'){
                    num+=1000;
                }else if(i + 1 < s.size() && s[i]=='C' && s[i+1]=='M'){
                    i++;
                    num+=900;
                }else if(s[i]=='D'){
                    num+=500;
                }else if(i + 1 < s.size() && s[i]=='C' && s[i+1]=='D'){
                    i++;
                    num+=400;
                }else if(s[i]=='C'){
                    num+=100;
                }else if(i + 1 < s.size() && s[i]=='X' && s[i+1]=='C'){
                    i++;
                    num+=90;
                }else if(s[i]=='L'){
                    num+=50;
                }else if(i + 1 < s.size() && s[i]=='X' && s[i+1]=='L'){
                    i++;
                    num+=40;
                }else if(s[i]=='X'){
                    num+=10;
                }else if(i + 1 < s.size() && s[i]=='I' && s[i+1]=='X'){
                    i++;
                    num+=9;
                }else if(s[i]=='V'){
                    num+=5;
                }else if(i + 1 < s.size() && s[i]=='I' && s[i+1]=='V'){
                    i++;
                    num+=4;
                }else if(s[i]=='I'){
                    num+=1;
                }
                i++;
            }
        return num;
        }
    
    };