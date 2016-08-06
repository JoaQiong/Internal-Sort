//文件名:ShellSort.cpp
//希尔排序算法实现:读一串整型数据　进行排序　　最后输出
//基本思想：先将整个待排记录序列分割成若干子序列，分别进行直接插入排序，待整个序列基本有序时，
//再对全体记录进行一次直接插入排序
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void ShellSort(int array[],int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    ShellSort(IntegerArray,CurrentSize);
    PrintIntegerArray(IntegerArray,CurrentSize);

    return 0;
}

//函数：ReadIntegerArray
//作用：接收用户的输入，存入数组array，max是array的大小，flag是输入结束标记
//当输入数据个数达到最大长度或输入了flag时结束
int ReadIntegerArray(int array[],int max,int flag){
    int size=0;

    cout<<"请输入数组元素，以"<<flag<<"结束:  :";
    while(size<max){
    cin>>array[size];
        if(array[size]==flag) break;
        else ++size;
    }

    return size;
}

//函数：ShellSort
//作用：将array里的数据进行希尔排序，size为数组长度
//step为希尔增量，最后step为１，对全体序列进行直接插入排序
//对相距step的元素序列及性能直接插入排序
void ShellSort(int array[],int size){
    int temp;
    for(int step=size/2;step>0;step/=2){
        for(int i=step;i<size;i++){
            temp=array[i];
            if(array[i]<array[i-step]){
                int j;
                for(j=i-step;j>=0&&array[j]>temp;j-=step){
                    array[j+step]=array[j];
                }
                array[j+step]=temp;
            }
        }
    }
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"直接插入排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
