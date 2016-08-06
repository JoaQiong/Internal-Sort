//文件名:StraightSelect.cpp
//直接选择排序算法实现:读一串整型数据　进行排序　　最后输出
//直接选择排序是最简单直观的排序算法，即从第０个位置起找出整个序列的最小值
//再一次找出第ｉ个位置对应的除i-1个位置之前的最小值，直至整个序列有序
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void StraightSelect(int array[],int size);
void StraightSelect2(int array[],int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    StraightSelect2(IntegerArray,CurrentSize);
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

//函数：StraightSelect
//作用：将array里的数据进行直接插入排序，size为数组长度
void StraightSelect(int array[],int size){
    int temp;
    for(int i=0;i<size;i++){
        int temp;
        for(int j=i;j<size;j++){
            if(array[i]>array[j]){
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
}

//函数：StraightSelect2
//作用：将array里的数据进行直接插入排序，size为数组长度
//用k记录选择过程中最小元素的位置，而无需比较过程中交换
void StraightSelect2(int array[],int size){
    int temp;
    int k;
    for(int i=0;i<size;i++){
        int temp;
        k=i;
        for(int j=i+1;j<size;j++){
            if(array[k]>array[j]){
                k=j;
            }
        }
        temp=array[k];
        array[k]=array[i];
        array[i]=temp;
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
