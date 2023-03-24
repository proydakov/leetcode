class Solution final
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<std::vector<int>> mat(text1.size(), std::vector<int>(text2.size(), 0));

        if (text1.front() == text2.front())
        {
            mat[0][0] = 1;
        }

        for(size_t i1 = 1; i1 < text1.size(); i1++)
        {
            if (mat[i1 - 1][0] == 1 || text1[i1] == text2.front())
            {
                mat[i1][0] = 1;
            }
        }

        for(size_t i2 = 1; i2 < text2.size(); i2++)
        {
            if (mat[0][i2 - 1] == 1 || text2[i2] == text1.front())
            {
                mat[0][i2] = 1;
            }
        }

        for(size_t i1 = 1; i1 < text1.size(); i1++)
        {
            for(size_t i2 = 1; i2 < text2.size(); i2++)
            {
                if (text1[i1] == text2[i2])
                {
                    mat[i1][i2] = mat[i1 - 1][i2 - 1] + 1;
                }
                else
                {
                    mat[i1][i2] = std::max(mat[i1][i2 - 1], mat[i1 - 1][i2]);
                }
            }
        }

        return mat.back().back();
    }
};

//
// text1 = "bcde", text2 = "ace" -> 2?
// text1 = "eca", text2 = "ace" 
//

//   c a
// a * 1
// c 1 

//
//   a b c d e
// a 1 * * ? ?
// c ? * ? ? ?
// e ? ? ? ? ?
//

