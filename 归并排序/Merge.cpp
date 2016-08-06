//文件名:Merge.cpp
// 归并排序算法实现:读一串整型数据　进行排序　　最后输出
//归并排序思想：合并两个已排好序的有序表.如果A B分别是两张待归并的表，由于它们均有序，因此只要从表头开始：顺序比较表头元素，
//小者移入另一表C中．反复如此，直至其中一表为空为止，将另一表中剩余元素自左至右复制到表C的剩余位置．
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void MergeSort(int array[],int size);
void MergeSort(int array[],int left,int right);
void Merge(int array[],int left,int mid,int right);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    MergeSort(IntegerArray,CurrentSize);
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

//函数：MergeSort
//作用：包裹函数，与之前的排序算法保持一致
//将array里的数据进行归并排序，size为数组长度
void MergeSort(int array[],int size){
    MergeSort(array,0,size-1);
}

//
void MergeSort(int array[],int left,int right){
    int mid;
    mid=(left+right)/2;

    if(left==right) return;    //必要的，如果只有一个元素，那么该元素就是一个已排好序的序列，排序结束
    //如果不止一个元素，则对前一半和后一半分别递归调用归并排序函数进行排序
    MergeSort(array,left,mid);
    MergeSort(array,mid+1,right);
    //将排好序的两个序列归并起来，就完成了整个序列的排序
    //这里传入mid+1是因为Merge里遍历左边的变量i的初始值为left，现假设传入为left=mid=0,right=1;
    //则不进去第一个while循环进行比较,直接进入第三个while，默认array[0]比array[1]小，导致出错
    Merge(array,left,mid+1,right);
}

//合并两个已排好序的有序表，以mid为中值将array看成是两张表
void Merge(int array[],int left,int mid,int right){
    int i,j;
    int k;
    int *temp=new int[right-left+1];

    i=left;
     j=mid;
     k=0;

     while(i<mid&&j<=right){
         if(array[i]<=array[j]) temp[k++]=array[i++];
         else temp[k++]=array[j++];
     }
     while(i<mid) temp[k++]=array[i++];       //左边的记录没有结束
     while(j<=right) temp[k++]=array[j++];   //右边的记录没有结束

     //这里array下标的范围应是left---right
     for(i=0,k=left;k<=right;)                            //将临时数组里的值送回array中
         array[k++]=temp[i++];

    delete [] temp;
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"归并排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
