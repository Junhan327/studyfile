#include<iostream>
using namespace std;

class term
{
    public:
        int row,col;
        int value;

};
class sparseMatrix
{
    public:
        sparseMatrix(){rows=0;cols=0;terms = new term[10000];}
        void reset();
        void transpose(sparseMatrix &b);
        void add(sparseMatrix &a , sparseMatrix &b);
    private:
        int rows,cols;
        term* terms;
};
void sparseMatrix::reset()
{
    int mrows,mcols;
    cin>>mrows>>mcols;
    int m;
    for(int i=0;i<mrows;i++)
    {
        for(int j=0;i<mcols;j++)
        {
            int temp;
            cin>>temp;
            if(temp != 0)
            {
                terms[m].row=i;
                terms[m].col=j;
                terms[m].value=temp;
                m++;
            }
        }
    }
}