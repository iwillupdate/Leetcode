class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1 ; i>=0 ; i--){
            if((num[i]-'0')%2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
        
    }
};



// class Solution {
// public:
//     string largestOddNumber(string num) {
//         int index = -1;
//         int i;
//         for(i=num.length()-1 ; i>=0 ; i--){
//             if((num[i] - '0') % 2 == 1){
//                 index=i;
//                 break;
//             }
//         }
//         //skip leading 0s
//         i=0;
//         while(i<=index and num[i]=='0'){
//             i++;
//         }
//         //return largest odd number substring
//         return num.substr(i,index-i+1);
        

//     }
// };