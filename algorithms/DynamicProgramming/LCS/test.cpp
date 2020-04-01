#include<iostream>
#include<string>

using namespace std;

extern void testLCSSolver(string str1,string str2);

int main()
{
    string str1("program"),str2("algorithm");
    testLCSSolver(str1,str2);
    return 0;
}
// int getLCS(string& str1,string& str2,int len1,int len2)
// {
//     if(len1==0||len2==0)
//         return 0;
//     if(str1[len1-1]==str2[len2-1])
//         return getLCS_R(str1,str2,len1-1,len2-1)+1;//减而治之
//     else
//     {
//         int ans1=getLCS_R(str1,str2,len1,len2-1);
//         int ans2=getLCS_R(str1,str2,len1-1,len2);
//         return ans1>ans2?ans1:ans2;//分而治之
//     }
// }