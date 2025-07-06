#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

struct DataPoint
{
    double x;
    double y;
};

vector<DataPoint> readData(string fileName);
double calculateSlope(const vector<DataPoint>& data);
double calculateIntercept(const vector<DataPoint>&data, double slope);
vector<double> predictValues(const vector<DataPoint>& data, double a, double b);
void writeResultsToFile(const vector<DataPoint>& data, double a, double b, vector<double> predictedY, string fileName);

int main()
{
    vector<DataPoint> points;

    points = readData("RegressionData.txt");
    for (DataPoint p: points)
    {
        cout<<"["<<p.x<<","<<p.y<<"]"<<endl;
    }

    double b = calculateSlope(points);
    double a = calculateIntercept(points,b);
    vector<double> predicted;
    predicted = predictValues(points,a,b);
    writeResultsToFile(points, a, b, predicted, "RegressionResults.txt");

}

vector<DataPoint> readData(string fileName)
{
    ifstream input;
    input.open(fileName);

    vector<DataPoint> dVec;
    DataPoint temp;
    if(input.is_open())
    {
        while(!input.eof())
        {
            input>>temp.x;
            input>>temp.y;
            dVec.push_back(temp);
        }
        input.close();

        return dVec;
    }
    else
        cout<<"File cannot be opened.";
}

double calculateSlope(const vector<DataPoint>& data)
{
    double slope = 0;
    double n = data.size();
    double sumXY = 0;
    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    for(DataPoint p: data)
    {
        sumXY+=p.x*p.y;
        sumX+=p.x;
        sumY+=p.y;
        sumX2+=pow(p.x,2);
    }

    slope = ((n*sumXY)-(sumX*sumY))/((n*sumX2)-(pow(sumX,2)));

    return slope;
}

double calculateIntercept(const vector<DataPoint>&data, double slope)
{
    double sumX = 0;
    double sumY = 0;
    double n = data.size();

    for(DataPoint p: data)
    {
        sumX+=p.x;
        sumY+=p.y;
    }

    return (sumY-(slope*sumX))/n;
}

vector<double> predictValues(const vector<DataPoint>& data, double a, double b)
{
    vector<double> predictedY;

    double pY;

    for (DataPoint d: data)
    {
        pY = a + (b*d.x);
        predictedY.push_back(pY);
    }
    return predictedY;
}

void writeResultsToFile(const vector<DataPoint>& data, double a, double b, vector<double> predictedY, string fileName)
{
    ofstream output;
    output.open(fileName);

    if (output.is_open())
    {
        output<<"Linear Regression Analysis:"<<endl;
        output<<"Equation: Y = "<<a<<"+ "<<b<<"X"<<endl;
        output<<"X\tObserved Y\tPredicted Y"<<endl;
        cout<<"Linear Regression Analysis:"<<endl;
        cout<<"Equation: Y = "<<a<<"+ "<<b<<"X"<<endl;
        cout<<"X\tObserved Y\tPredicted Y"<<endl;
        for (int i=0; i<data.size(); i++)
        {
           output<<data.at(i).x<<"\t"<<data.at(i).y<<"\t\t"<<predictedY.at(i)<<endl;
           cout<<data.at(i).x<<"\t"<<data.at(i).y<<"\t\t"<<predictedY.at(i)<<endl;

        }
        output.close();
        //cout<<"Writing successful!";
    }
    else
        cout<<"File cannot be opened";
}

