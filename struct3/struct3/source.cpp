#include <iostream>
#include <vector>

struct Node 
{ 
	int value; 
	Node* left = nullptr; 
	Node* right = nullptr; 
	Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

int f(const int* a, int index) 
{
    int c = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < index; i++) 
    {
        //дл€ палиндромов с нечетной длиной
        left = i;
        right = i;

        while ((left >= 0 && right < index) && (a[left] == a[right]))
        {
            if ((right - left + 1 > 2) && (a[left] != 0))
                c++;
            left--;
            right++;
        }
        //дл€ палиндромов с четной длиной
        if (i + 1 < index) //проверка на центр из двух цифр
        {
            left = i;
            right = i + 1;
            while (left >= 0 && right < index && a[left] == a[right])
            {
                if ((right - left + 1 >= 2) && (a[left] != 0))
                    c++;
                left--;
                right++;
            }
        }
    }

    for (int i = 0; i < index; i++)
        std::cout << a[i];
    std::cout << std::endl;
    return c;
}

int countPal(Node* node, int* a, int result, int index)
{
    if (node == nullptr) return 0;

    a[index] = node->value;
    index += 1;

    if (node->left == nullptr && node->right == nullptr)
    {
        result = f(a, index);
    }

    result += countPal(node->left, a, result, index) + countPal(node->right, a, result, index);

    return result;
}

int countPal(Node* node)
{
    int* a = new int[50];
    int result = 0;
    int index = 0;
    return countPal(node, a, result, index);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->left->left->left = new Node(2);
    root->left->left->left->right = new Node(1);
    int result = countPal(root);
    std::cout << result << std::endl;
    return 0;
}

