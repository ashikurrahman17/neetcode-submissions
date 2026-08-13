struct Node{
    int val;
    Node* nxt;
    Node(int v, Node* n = nullptr) : val(v), nxt(n) {}
};
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    ~LinkedList(){
        Node* curr = head;
        while(curr){
            Node* tmp = curr;
            curr = curr->nxt;
            delete tmp;
        }
    }

    int get(int index) {
        Node *curr = head->nxt;
        int i = 0;
        while(curr){
            if(i == index) return curr->val;
            curr = curr->nxt;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* tmp = new Node(val, head->nxt);
        head->nxt = tmp;
        if(tail == head) tail = tmp;
    }
    
    void insertTail(int val) {
        tail->nxt = new Node(val);
        tail = tail->nxt;
    }

    bool remove(int index) {
       Node* curr = head;
       int i = 0;
       while(curr and i<index){
        curr = curr->nxt;
        i++;
       } 

       if(!curr or !curr->nxt) return false;

       Node* del = curr->nxt;
       if(del == tail) tail = curr;

       curr->nxt = del->nxt;
       delete del;
       return true;

    }

    vector<int> getValues() {
        vector<int> ans;
        Node* curr = head->nxt;
        while(curr){
            ans.push_back(curr->val);
            curr = curr->nxt;
        }
        return ans;
    }
};
