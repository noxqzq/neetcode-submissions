class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        }

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;

        if (size == 0) {
            tail = node;
        }
        size++;
    }

    void insertTail(int val) {
        Node* node = new Node(val);

        if (size == 0) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    bool remove(int index) {
        if (index >= size) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;

            if (size == 1) {
                tail = nullptr;
            }
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }

            Node* toDelete = curr->next;
            curr->next = toDelete->next;

            if (toDelete == tail) {
                tail = curr;
            }
            delete toDelete;
        }

        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head;

        while (curr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};
