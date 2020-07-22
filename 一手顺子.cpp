#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isNStraightHand(vector<int>& hand, int w);
int main()
{
    int S[]={1,2,3,4,5};
    vector<int> hand(S,S+5);
    int w=3;
    bool result=isNStraightHand(hand,w);
    cout<<"result="<<result;
    return 0;
}
 

 
 
 
 
 bool isNStraightHand(vector<int>& hand, int w) {
        map<int,int> cunt;
        int i=0;
        for(int k=hand[0];i<hand.size();i++){
            k=hand[i];
            cunt[k]++;
            cout<<"cunt="<<cunt[k]<<endl;
        }
        while(!cunt.empty())
        {
            int start=cunt.begin()->first;
            for(int j=0;j<w;j++)
            {
                if(cunt.find(start+j)==cunt.end())return false;
                //if(!cunt.count(start+j))return false;
                if(--cunt[start+j]==0)
                    cunt.erase(start+j);
            }
        }
        return true;
    }

