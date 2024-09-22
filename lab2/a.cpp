#include<iostream>
#include<cmath>
using namespace std;
struct Node
{
    int val;  
    Node * next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void isNearest(Node * head, int c){
    Node * cur = head;
    int otv = 0;
    int pos = 0;
    int min = abs(head->val - c); // 7 8 -10 4 1   5
    while (cur != NULL)
    {
        if (min > abs(cur->val - c))
        {
            min = abs(cur->val - c);
            otv = pos;
        }  
        cur = cur->next;
        pos++;
    }
    cout << otv;
}
int main(){
    int n;cin >> n;
    Node * head;
    Node * tail;
    Node * vre;
    for (int i = 0; i < n; i++)
    {
        int nums;
        cin >> nums;
        if (i == 0)
        {
            head = new Node(nums);
            tail = head;
        }
        else
        {
            vre = new Node(nums);
            tail->next = vre;
            tail = vre;
        }  
    }
    int finder;
    cin >> finder;
    isNearest(head, finder); 
}