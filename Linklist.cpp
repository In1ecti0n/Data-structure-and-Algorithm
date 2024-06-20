#include<bits/stdc++.h>
using namespace std;

struct Node { //khởi tạo linked list với dữ liệu và con trỏ;
	int val;
	Node* next;
	Node(int value){   // hàm khởi tạo một node mới
		val = value;
		next = NULL;
	}
};

void push_front(Node** head, int new_val){
	Node* new_node = new Node(new_val);  //con trỏ Node trỏ tới new_node, con trỏ được cấp bộ nhớ kiểu struct Node được định nghĩa ở trên 
	new_node->next = *head;  // con trỏ next (định nghĩa hàm struct) trỏ tới vị trí đầu tiên mà con trỏ head chỉ
	*head = new_node; //con trỏ head sẽ chỉ tới newnode;
}
void push_back(Node** head, int new_val){
    Node* new_node = new Node(new_val);
    if (head == NULL){
        head = new_node;
    }else{
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp ->next;
        }
        temp->next = new_node;
    }
}

void printList(Node* head){
	Node* i = head;
	while(i){
		cout<<i->val;
		i = i->next;
	}
	cout<<"\n";
}

void reverse(Node** head){
	Node* pre = NULL;
	Node* current = *head;
	Node* next = NULL;
	while (current != NULL){
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	*head = pre;
}

// function to add 2 numbers given as linked lists
Node* add(Node* l1, Node* l2){
	Node* ans = new Node(0);
	Node* curr = ans;
	int carry = 0;
	while(l1 || l2){
		int sum = 0;
		if(l1) sum += l1->val;
		if(l2) sum += l2->val;
		sum += carry;

		curr->next = new Node(sum%10);
		curr = curr->next;

		carry = sum/10;

		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;
	}

	if(carry){
		curr->next = new Node(carry);
	}
	ans = ans->next;
	return ans;
}
/*
int main(){
    int t; cin>>t;
    string s; 
    while(t--){
        cin>>s;
        size_t pos = s.find("+");
		Node* l1 = NULL;
		for (int i = 0; i < pos; i++){
			int temp = s[i] - '0';
			push_front(&l1, temp);
		}
		Node* l2 = NULL;
		for (int i = pos + 1; i < s.size(); i++){
			int temp2 = s[i] - '0';
			push_front(&l2, temp2);
		}
		Node* sum = add(l1,l2);
		reverse(&sum);
		printList(sum);
	}
}
*/
	
