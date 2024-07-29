struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
if (!head || !head->next) {
return false;
}

ListNode *slow = head;
ListNode *fast = head->next;

while (slow != fast) {
if (!fast || !fast->next) {
return false;
}
slow = slow->next;
fast = fast->next->next;
}

return true;
}


int main() {
// Example 1: Create a linked list with a cycle
ListNode *head1 = new ListNode(20);
head1->next = new ListNode(30);
head1->next->next = new ListNode(40);
head1->next->next->next = new ListNode(60);
head1->next->next->next->next = new ListNode(80);
head1->next->next->next->next->next = head1->next->next; // create a cycle

std::cout << "Example 1: ";
if (hasCycle(head1)) {
std::cout << "Cycle detected\n";
} else {
std::cout << "No cycle detected\n";
}

// Example 2: Create a linked list without a cycle
ListNode *head2 = new ListNode(6);
head2->next = new ListNode(4);
head2->next->next = new ListNode(2);
head2->next->next->next = new ListNode(8);

std::cout << "Example 2: ";
if (hasCycle(head2)) {
std::cout << "Cycle detected\n";
} else {
std::cout << "No cycle detected\n";
}

// Clean up memory
ListNode *current = head1;
while (current != nullptr) {
ListNode *temp = current;
current = current->next;
delete temp;
}

current = head2;
while (current != nullptr) {
ListNode *temp = current;
current = current->next;
delete temp;
}

return 0;
}
