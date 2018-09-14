//
//  main.cpp
//  zuoye
//
//  Created by 赵家仪 on 2018/9/14.
//  Copyright © 2018年 赵家仪. All rights reserved.
//

#include<iostream>
using namespace std;

struct myList{
    int id;
    myList* next;
};

/*myList* createList(int n, myList* head){
    myList* temp;
    temp = head;
    for(int i = 0; i < n - 1; i ++){
        temp -> id = i + 1;
        temp -> next = (myList*)malloc(sizeof(myList));
        temp = temp -> next;
    }
    temp -> id = n;
    temp -> next = head;
    return head;
}
*/
int main() {
    int m,n;
    cin>>n>>m;
    myList* head = (myList*)malloc(sizeof(myList));
    head -> next = head;
    //head = createList(n, head);
    myList* temp;
    temp = head;
    for(int i = 0; i < n - 1; i ++){
        temp -> id = i + 1;
        temp -> next = (myList*)malloc(sizeof(myList));
        temp = temp -> next;
    }
    temp -> id = n;
    temp -> next = head;
   
    
    int count = n;
    int counter = 0;
    
    myList* after = head;
    myList* temp1 = head;
    
    while(count != 1){
        while(counter < m - 1){
            temp1 = after;
            after = after -> next;
            counter ++;
        }
        temp1 -> next = temp1 -> next -> next;
        after = temp1 -> next;
        count --;
        counter = 0;
    }
    cout<<after->id<<endl;
    free(head);
    return 0;
}

