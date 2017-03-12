#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){

    //declare
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *now = head;
    ListNode *node = NULL;
    int ifmorethanten = 0;
    int l1value;
    int l2value;
    int sum;
    while (l1!=NULL || l2!=NULL || ifmorethanten!=0){
        if (l1 == NULL){
            l1value = 0;
        } else{
            l1value = l1->val;
        }
        if (l2 == NULL){
            l2value = 0;
        } else{
            l2value = l2->val;
        }

        sum = l1value+l2value+ifmorethanten;
        if (sum<10){
            node = (ListNode*)malloc(sizeof(ListNode));
            node->val = sum;
            ifmorethanten = 0;
            now->next = node;
            now = node;

        } else{
            node = (ListNode*)malloc(sizeof(ListNode));
            node->val = sum%10;
            ifmorethanten = 1;
            now->next = node;
            now = node;
        }
        l1 = (l1 == NULL ? NULL : l1->next);
        l2 = (l2 == NULL ? NULL : l2->next);



    }
    return head->next;

}

int main() {
    //give the test data
    int A[] = {9,1,0,6};
    int B[] = {4,8,4};
    ListNode *head = NULL;
    ListNode *head1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head1->next = NULL;
    head2->next = NULL;
    ListNode *node;
    ListNode *now = head1;
    for(int i = 0;i < 4;i++){
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val = A[i];
        node->next = NULL;
        now->next = node;
        now= node;
    }
    now = head2;
    for(int i = 0;i < 3;i++){
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val = B[i];
        node->next = NULL;
        now->next = node;
        now = node;
    }
    head = addTwoNumbers(head1->next,head2->next);
    printf("%s ","reslut");
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}

