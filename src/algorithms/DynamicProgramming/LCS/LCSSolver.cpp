/*最大公共序列长度问题 递归和动态规划求解*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "common/Point.h"

using namespace std;

class LCSSolver{
    vector<vector<int> > matrix;
    vector<vector<Point> > infoMatrix;
    string str1,str2;
    int LCSLength;
public:
    LCSSolver(string& _str1,string& _str2)
    {
        LCSLength = -1;
        str1 = _str1; str2 = _str2;
        int len1=str1.length(),len2=str2.length();
        //infoMatrix初始化
        for(int i=0;i<=len1;i++)
            infoMatrix.push_back(vector<Point>(len2+1));
        for(int i=0;i<=len1;i++)
            matrix.push_back(vector<int>(len2+1));
    }
    int getLCSLength()
    {
        int len1=str1.length(),len2=str2.length();
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
                //第i个字符的下标为i-1
                if(str1[i-1]==str2[j-1]){
                    matrix[i][j] = matrix[i-1][j-1]+1;
                    infoMatrix[i][j] = Point(-1,-1);
                }
                else{
                    if(matrix[i-1][j]>matrix[i][j-1]){
                        matrix[i][j] = matrix[i-1][j];
                        infoMatrix[i][j] = Point(-1,0);
                    }else{
                        matrix[i][j] = matrix[i][j-1];
                        infoMatrix[i][j] = Point(0,-1);
                    }
                }
            }
        }
        LCSLength = matrix[len1][len2];
        return matrix[len1][len2];
    }

    string getLCS()
    {
        if(LCSLength==-1)
            getLCSLength();

        string ans(LCSLength,' ');
        int count = LCSLength-1;

        int i=str1.length(),j=str2.length();
        while(i>0&&j>0)
        {
            int di=infoMatrix[i][j].getX(),dj=infoMatrix[i][j].getY();
            if(di==-1&&dj==-1){
                ans[count] = str1[i-1];
                count--;
            }
            i += di;
            j += dj;
        }
        return ans;
    }
};
void testLCSSolver(string str1,string str2)
{
    LCSSolver lcsolver(str1,str2);
    int LCSlength = lcsolver.getLCSLength();
    cout << str1 << " and " << str2 << "的最大公共子序列 长度为" << LCSlength << "\n";

    cout << "一个最大公共子序列为" << lcsolver.getLCS() << "\n";
}