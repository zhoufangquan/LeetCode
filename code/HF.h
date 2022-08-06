#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *get_tree(string data){
    if(data.length() == 2) return NULL;
    queue<string> arr;
    string temp = "";
    for(int i=1;i<data.length()-1;i++){
        if(data[i] == ','){
            arr.push(temp);
            temp = "";
        }
        else{
            temp += data[i];
        }
    }
    arr.push(temp);
    
    TreeNode *ans = new TreeNode(stoi(arr.front()));
    arr.pop();
    queue<TreeNode *> Q;
    Q.push(ans);

    while(!Q.empty() && !arr.empty()){
        TreeNode *root = Q.front(); Q.pop();
        string l = arr.front(); arr.pop();
        string r;
        if(arr.size() > 0){
            r = arr.front(); arr.pop();
        }
        else{
            r = "null";
        }
        if(l == "null"){
            root->left = NULL;
        }
        else{
            root->left = new TreeNode(stoi(l));
            Q.push(root->left);
        }
        if(r == "null"){
            root->right = NULL;
        }
        else{
            root->right = new TreeNode(stoi(r));
            Q.push(root->right);
        }
    }

    return ans;
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<vector<char> > get_CharVec(int r, int c){
    vector<vector<char> > ans;
    for(int i=0;i<r;i++){
        vector<char> temp(c);
        for(int j=0;j<c;j++){
            cin>>temp[j];
        }
        ans.push_back(temp);
    }
    return ans;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}
