//文件名:MultiKeyRadixSort.cpp
// 冒泡排序算法实现:读一串整型数据　进行排序　　最后输出
//冒泡排序思想：从头到尾比较相邻的两个元素，小的放前面，大的放后面，这样一次冒泡后最大的就是最后一个
//再从头开始到size-1比较相邻的元素，这样比较的冒泡次数为size-１，比较次数为size-(本次冒泡第i次)
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void MultiKeyRadixSort(int array[],int size);
void MultiKeyRadixSort(int array[],int d,int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    MultiKeyRadixSort(IntegerArray,CurrentSize);
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

//
void MultiKeyRadixSort(int array[],int size){
    int d=0;
    int max=array[0];

    for(int i=1;i<size;i++){
        if(array[i]>max)    max=array[i];
    }
    while(max>0){
        d++;
        max/=10;
    }
    //cout<<d<<endl;
    MultiKeyRadixSort(array,d,size);
}

//函数：BubbleSort
//作用：将array里的数据进行冒泡排序，size为数组长度
//i表示冒泡次数，j表示比较次数
void MultiKeyRadixSort(int array[],int d,int size){
    int *buckets=new int[10];     //可枚举范围内定义的这么max-min+1个桶
    int *temp=new int[size];
    int i,j,count;
    count=1;

    for(i=0;i<d;i++){
        int subKey;
        memset(buckets,0,10*sizeof(int));

        for(j=0;j<size;j++){
            subKey=(array[j]/count)%10;
            buckets[subKey]++;
        }
       // PrintIntegerArray(buckets,10);

        //重新计算buckets数组里的值
        for(j=1;j<10;j++){
            buckets[j]=buckets[j]+buckets[j-1];
        }
    //    PrintIntegerArray(buckets,10);
        //每个桶中保存了落入当前桶和落入前面所有桶中元素的总数目

        //用temp暂时保存array里的数据
        for(j=0;j<size;j++){
            temp[j]=array[j];
        }
        //根据buckets里的值将待排数组的数据放到相应的位置上
        //本质还是根据temp[i]-min]找的
        for(j=size-1;j>=0;j--){
            subKey=(temp[j]/count)%10;
            //cout<<buckets[subKey]-1<<" "<<subKey<<" "<<temp[0];
            array[--buckets[subKey]]=temp[j];
          //  PrintIntegerArray(buckets,10);
         //   cout<<" \n";
        }
        count*=10;
    //    PrintIntegerArray(array,size);
   }
   delete [] temp;
   delete [] buckets;
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"基数排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
