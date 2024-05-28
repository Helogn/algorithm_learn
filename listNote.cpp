#include<iostream>
using namespace std;
struct listNode
{
    int val;
    listNode *next;
    listNode (int input_val): val(input_val), next(nullptr) {}
    listNode (): val(0), next(nullptr) {}
};

// ostream& operator<<(ostream& os, const listNode& node)
//     {
//         os<< node.val<<endl;
//         return os;
//     }

class question
{
    private:
    listNode *head;
    listNode *endNote;
    public:
    question(int val)
    {
        head = new listNode(val);
        this->endNote = head;
        cout << "create class successfully" <<endl;
    }
    
    listNode* new_listnode(int val)
    {
        listNode *n1 = new listNode(val);
        return n1;
    }

};

// 给定一个链表，反转链表
listNode* create_three_listNode()
{
    listNode *head = new listNode(0);
    listNode *end = head;
    int length = 0;
    for(int i = 1; i<5; i++)
    {
        listNode *new_listNode = new listNode(i);
        end->next = new_listNode;
        end = end->next;
        length++;
    }

    return head;
}

listNode* reverseList(listNode* head)
{
    listNode *headNode = head;
    listNode *endNode = nullptr;
    listNode *newNode = nullptr;
    while (headNode != nullptr)
    {
        newNode = headNode->next;
        newNode->next = endNode;
        endNode = newNode;
        headNode = headNode->next;
    }
    return newNode;

}

void coutNote(listNode* input1)
{
    while(input1 != nullptr)
    {
        cout<<input1->val<<endl;
        input1 = input1->next;
    }
}


int main()
{
    // input
    listNode *input1 = create_three_listNode();
    listNode *resNode = reverseList(input1);
    // question n1 = question(1);
    // n1.new_listnode(3);
    cout<<"successfully!"<<endl;
    // coutNote(input1);
    cout<<"result here"<<endl;
    coutNote(resNode);
    return 0;
}