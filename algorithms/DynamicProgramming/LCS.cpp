/*最大公共序列长度问题 递归和动态规划求解*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int getLCS_R(string& str1,string& str2,int len1,int len2)
{
    if(len1==0||len2==0)
        return 0;
    if(str1[len1-1]==str2[len2-1])
        return getLCS_R(str1,str2,len1-1,len2-1)+1;//减而治之
    else
    {
        int ans1=getLCS_R(str1,str2,len1,len2-1);
        int ans2=getLCS_R(str1,str2,len1-1,len2);
        return ans1>ans2?ans1:ans2;//分而治之
    }
}
int getLCS_I(string& str1,string& str2,int len1,int len2)
{
    vector<vector<int> > matrix;
    for(int i=0;i<=len1;i++)
        matrix.push_back(vector<int>(len2+1));
    //边界哨兵初始化
    for(int i=0;i<=len1;i++)
        matrix[i][0] = 0;
    for(int i=0;i<=len2;i++)
        matrix[0][i] = 0;
    //分两种情况进行填表
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                matrix[i][j] = matrix[i-1][j-1]+1;
            else
                matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
        }
    }
    return matrix[len1][len2];
}

int main()
{
    string str1("program"),str2("algorithm");
    cout << getLCS_R(str1,str2,str1.length(),str2.length())<<"\n";
    cout << getLCS_I(str1,str2,str1.length(),str2.length())<<"\n";
    return 0;
}