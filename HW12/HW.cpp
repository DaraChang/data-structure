#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define epsilon 1E-8
int main(){
    int testNum;
    cin>>testNum;
    vector<int> listX;
    vector<int> listY;
    int *result = new int[testNum];
    for(int i=0;i<testNum;i++){
        //cout<<"testCase"<<i<<endl;
        result[i] = 0;
        int pointNum;
        int possible[3][2];
        //cout<<"pointNum: ";
        cin>>pointNum;
        //Cor* list = new Cor[pointNum];
        for(int j=0;j<pointNum;j++){
            int temp;
            //cout<<"point"<<j<<": ";
            cin>>temp;
            listX.push_back(temp);
            cin>>temp;
            listY.push_back(temp);
        }
        for(int j=0;j<pointNum-2;j++){
            for(int k=j+1;k<pointNum-1;k++){
                for(int l=k+1;l<pointNum;l++){
                    //cout<<j<<", "<<k<<", "<<l<<endl;
                    double slope1 = ((double)(listY[j] - listY[k] + epsilon))/((double)(listX[j] - listX[k] + epsilon));
                    double slope2 = ((double)(listY[k] - listY[l] + epsilon))/((double)(listX[k] - listX[l] + epsilon));
                    //cout<<slope1<<endl<<slope2<<endl;
                    if( abs(slope1-slope2) >= 1E-5){
                        //cout<<"begin find pair"<<endl;
                        possible[0][0] = listX[j]+listX[k]-listX[l];
                        possible[0][1] = listY[j]+listY[k]-listY[l];
                        possible[1][0] = listX[j]+listX[l]-listX[k];
                        possible[1][1] = listY[j]+listY[l]-listY[k];
                        possible[2][0] = listX[k]+listX[l]-listX[j];
                        possible[2][1] = listY[k]+listY[l]-listY[j];
                        for(int m=0;m<3;m++){
                            //cout<<"find "<<m;
                            vector<int>::iterator itX, itY;
                            itX = find(listX.begin()+l+1, listX.end(),possible[m][0]);
                            itY = find(listY.begin()+l+1, listY.end(),possible[m][1]);
                            //cout<<"itX"<<*itX<<", itY"<<*itY<<endl;
                            //cout<<(distance(listX.begin(),itX))<<", "<<(distance(listY.begin(),itY))<<endl;
                            if((itX!=listX.end())&&(itY!=listY.end())){
                                bool findY = false;
                                while(itX!=listX.end()){
                                    if(listY[distance(listX.begin(), itX)]==possible[m][1]){
                                        findY = true;
                                        break;
                                    }
                                    else{
                                        itX = find(itX+1, listX.end(), possible[m][0]);
                                    }
                                }

                                if(findY){
                                    result[i]++;
                                    //cout<<"result++"<<endl;
                                }
                                else{
                                    while(itY!=listY.end()){
                                        if(listX[distance(listY.begin(), itY)]==possible[m][0]){
                                            findY = true;
                                            break;
                                        }
                                        else{
                                            itY = find(itY+1, listY.end(), possible[m][1]);
                                        }
                                    }
                                    if(findY){
                                        result[i]++;
                                        //cout<<"result++"<<endl;
                                    }
                                }
                                
                            }
                        } 
                    }  
                }
            }
        }
        //cout<<"result: "<<result[i]<<endl;
        listX.clear();
        listY.clear();
    }
    for(int i=0;i<testNum;i++)
        cout<<result[i]<<endl;
    return 0;
}