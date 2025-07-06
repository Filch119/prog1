#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct student
{
     string studentName;
     double score;
};

vector<student> readFromRecord (string fileName);
double recAverage (vector<student> S);
double recSTDev(vector<student> S);
double recPearCorr(vector<student> S1, vector <student> S2);
void writeToRecord(vector<student> S);
int main()
{
    vector<student> S1;
    vector<student> S2;

    S1 = readFromRecord("StudentScore1.txt");
    S2 = readFromRecord("StudentScore2.txt");

    cout<<"Mean of Record 1:"<<recAverage(S1)<<endl<<endl;
    cout<<"Mean of Record 2:"<<recAverage(S2)<<endl<<endl;
    cout<<"SD of Record 1:"<<recSTDev(S1)<<endl<<endl;
    cout<<"SD of Record 2:"<<recSTDev(S2)<<endl<<endl;

    cout<<"Pearsons Correlation:"<<recPearCorr(S1, S2);
    writeToRecord(S1);
}

vector<student> readFromRecord (string fileName)
{
    ifstream inRec;
    vector<student> s;
    student temp;
    inRec.open(fileName);

    if (inRec.is_open())
    {
        while (!inRec.eof())
        {
            getline(inRec, temp.studentName, '\t');
            inRec >> temp.score;
            inRec.ignore();
            s.push_back(temp);
        }
    }
    inRec.close();

    return s;
}

double recAverage (vector<student> S)
{
    double average=0;
    for (int i=0; i<S.size(); i++)
    {
        average+=S.at(i).score;
    }
    return average/S.size();
}

double recSTDev(vector<student> S)
{
    double sd=0;
    double mean = recAverage(S);
    for (int i=0; i<S.size(); i++)
    {
        sd += pow(S.at(i).score - mean, 2);
    }
    sd/=S.size();

    return sqrt(sd);
}

double recPearCorr(vector<student> S1, vector <student> S2)
{
    double r=0;

    for (int i=0; i<S1.size(); i++)
    {
        r += ((S1.at(i).score - recAverage(S1)) * (S2.at(i).score - recAverage(S2)))
            /(recSTDev(S1)*recSTDev(S2));
    }

    return r*1/S1.size();
}


void writeToRecord(vector<student> S)
{
    ofstream outRec;
    outRec.open("StudentScore3.txt");

    if (outRec.is_open())
    {
        /*for (int i=0; i<S.size(); i++)
        {
            outRec<<S.at(i).studentName<<'\t';
            outRec<<S.at(i).score-5<<endl;
        }*/
        for (student stu : S)
        {
            outRec<<stu.studentName<<',';
            outRec<<stu.score+1<<endl;
        }
    }
    outRec.close();
}
