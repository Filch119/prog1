#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

struct CollatzInfo
{
int startingNumber;
int length;
vector<int> sequence;
};

vector<CollatzInfo>generateCollatzSequences(int start, int end);
CollatzInfo findLongestSequence(const vector<CollatzInfo>& sequences);
void storeIn1DArray(const vector<CollatzInfo>& sequences, int arr[]);
void storeIn2DArray(const vector<CollatzInfo>& sequences, int arr[][2]);
void writeResultsToFile(const
vector<CollatzInfo>& sequences, int arr1D[],int arr2D[][2], CollatzInfo longest, string fileName);

int index =0;
int main()
{
//    ifstream input;
//    input.open("CollatzInput.txt");
    int s;
    int e;

    cout<<"Enter Starting Number:"<<endl;
    cin>>s;
    cout<<endl<<"Enter Starting Number:"<<endl;
    cin>>e;
//    if (input.is_open())
//    {
//        while(!input.eof())
//        {
//            input>>s;
//            input>>e;
//        }
//    }
//    else
//        cout<<"File cannot be opened.";

    vector<CollatzInfo> collatz;

    collatz = generateCollatzSequences(s,e);
    CollatzInfo longest = findLongestSequence(collatz);

    int arr[100];
    storeIn1DArray(collatz, arr);

    int arr2D[collatz.size()][2];
    storeIn2DArray(collatz, arr2D);
    writeResultsToFile(collatz, arr, arr2D, longest, "CollatzAnalysis.txt");
}

vector<CollatzInfo>generateCollatzSequences(int start, int end)
{
    CollatzInfo temp;
    vector<CollatzInfo> cInfo;
    vector<int>seq;
    for (int i = start; i<=end; i++)
    {
        temp.startingNumber = i;
        int ctr = 0;

        if (i == 1)
            seq.push_back(i);
        int tempNum = i;
        while (tempNum != 1)
        {
            seq.push_back(tempNum);
            ctr++;
            if (tempNum%2 == 0)
                tempNum/=2;
            else
                tempNum=3*tempNum+1;
        }
        temp.length = ctr;
        temp.sequence = seq;
        seq.clear();
        cInfo.push_back(temp);
    }
    //cout<<"successful"<<endl;
    return cInfo;
}

CollatzInfo findLongestSequence(const vector<CollatzInfo>& sequences)
{
    int high = 0;
    for (int i=0; i<sequences.size()-1; i++)
    {
        if (sequences.at(i).length > sequences.at(high).length)
            high = i;
    }

    //cout<<"successful2"<<endl;
    return sequences.at(high);
}

void storeIn1DArray(const vector<CollatzInfo>& sequences, int arr[])
{
    index = 0;
    //cout<<sequences.size();
    for (int i=0; i<sequences.size(); i++)
    {
        if (sequences.at(i).length>20)
        {
            cout<<sequences.at(i).length<<",";
            arr[index++] = sequences.at(i).length;
        }
    }
    //cout<<sizeof(arr)/sizeof(int);
    //cout<<endl<<"successful3"<<endl;
}

void storeIn2DArray(const vector<CollatzInfo>& sequences, int arr[][2])
{
    for (int i=0; i<sequences.size(); i++)
    {
        arr[i][0] = sequences.at(i).startingNumber;
        arr[i][1] = sequences.at(i).length;
    }
    //cout<<"successful4"<<endl;

}

void writeResultsToFile(const vector<CollatzInfo>& sequences, int arr1D[], int arr2D[][2], CollatzInfo longest, string fileName)
{
    ofstream output;
    output.open(fileName);

    if (output.is_open())
    {
        output<<"Collatz Sequence Analysis"<<endl;
        output<<"Number \t Length"<<endl;
        cout<<"Collatz Sequence Analysis"<<endl;
        cout<<"Number \t Length"<<endl;
        for (int i=0; i<sequences.size(); i++)
        {
            for (int j=0; j<2; j++)
            {
                output<<arr2D[i][j]<<'\t';
                cout<<arr2D[i][j]<<'\t';

            }
            output<<endl;
            cout<<endl;
        }


        output<<endl;
        output<<"1D Array (Numbers with Sequence Length > 20):"<<endl;
        cout<<endl<<"1D Array (Numbers with Sequence Length > 20):"<<endl;
        for(int i=0; i<index; i++){
            output<<arr1D[i]<<"  ";
            cout<<arr1D[i]<<" ";

        }
        output<<endl;
        output<<"Longest Sequence:"<<endl;
        output<<"Starting Number: "<<longest.startingNumber<<endl;
        output<<"Length: "<<longest.length<<endl;

        cout<<endl<<endl;
        cout<<"Longest Sequence:"<<endl;
        cout<<"Starting Number: "<<longest.startingNumber<<endl;
        cout<<"Length: "<<longest.length<<endl;
    }
    else
        cout<<"Cannot open file.";
    //cout<<"successful5"<<endl;

}
