//文件名:BucketSort.cpp
// 冒泡排序算法实现:读一串整型数据　进行排序　　最后输出
//冒泡排序思想：从头到尾比较相邻的两个元素，小的放前面，大的放后面，这样一次冒泡后最大的就是最后一个
//再从头开始到size-1比较相邻的元素，这样比较的冒泡次数为size-１，比较次数为size-(本次冒泡第i次)
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void BucketSort(int array[],int size);
void bucketSort(int array[],int max,int min,int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    BucketSort(IntegerArray,CurrentSize);
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

//函数：BubbleSort
//作用：将array里的数据进行冒泡排序，size为数组长度
//i表示冒泡次数，j表示比较次数
void BucketSort(int array[],int size){
    int i;
    int min,max;
    min=max=array[0];
    for(i=1;i<size;i++){
        if(array[i]>max)  max=array[i];
        if(array[i]<min)  min=array[i];
    }
    bucketSort(array,max,min,size);
}

//这里以5，４，２，４，１为例
void bucketSort(int array[],int max,int min,int size){
    int *buckets=new int[max-min+1];     //可枚举范围内定义的这么max-min+1个桶
    int *temp=new int[size];
    int i;

    //统计每个元素出现次数，第０个桶对应数组里最小的数，最后一个桶对应最大的数，桶里的数据为该桶对应数组值在数组中出现的次数
    //其中array[i]-min对应于temp[i]-min]，能保证从小到大排列的桶与我们待排数据的对应关系不变
    //这里有点儿位运算的意思，只是一个数可能不止存在一次
    for(i=0;i<size;i++){
        buckets[array[i]-min]++;
    }
    //各个桶里的值分别为：１，１，０，２，１

    //重新计算buckets数组里的值，每个桶内
    for(i=1;i<max-min+1;i++){
        buckets[i]=buckets[i]+buckets[i-1];
    }
    //各个桶里的值分别为：1，２，２，４，５，每个桶中保存了落入当前桶和落入前面所有桶中元素的总数目

    //用temp暂时保存array里的数据
    for(i=0;i<size;i++){
        temp[i]=array[i];
    }
    //根据buckets里的值将待排数组的数据放到相应的位置上
    //本质还是根据temp[i]-min]找的
    for(i=size-1;i>=0;i--){
        array[--buckets[temp[i]-min]]=temp[i];
    }
    //用于理解调试，各个桶里的值分别为：０，１，２，２，４，说明每个桶所对应的值都根据数组元素出现的个数相应减少了
    for(i=0;i<max-min+1;i++){
        cout<<buckets[i]<<'\t';
    }
    cout<<endl;
    delete [] temp;
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"桶式排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
