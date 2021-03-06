/**
* 二叉树的静态实现：对指针不自信，可以完全用数组实现
**/

//用静态二叉链表定义二叉树
struct node {
    typename data; //数据域
    int lchild; //指向左子树的指针域
    int rchild; //指向右子树的指针域
} Node[maxn]; //结点数组，maxn为结点数量上限

//结点的动态生成转变为静态指定
int index = 0; //分配一个Node数组中的结点给新的结点，index为其下标
int newNode(int v) {
    Node[index].data = v; //数据域为v
    //以-1或maxn表示空，因为数组范围是0 - maxn-1
    Node[index].lchild = -1;
    Node[index].rchild = -1;
    return index++;
}

//查找，root为根结点在数组中的下标
void search(int root, int x, int newdata) {
    if (root == -1) { //用-1来代替NULL
        return; //空树，死胡同（递归边界）
    }
    if (Node[root].data == x) {
        Node[root].data = newdata; //找到数据域为x的结点，把它修改成newdata
    }
    search(Node[root].lchild, x, newdata); //往左子树搜索x（递归式）
    search(Node[root].rchild, x, newdata); //往右子树搜索x（递归式）
}

//插入，root为根结点在数组中的下标
void insert(int &root, int x) { //记得加引用
    //空树，说明查找失败，也即插入位置（递归边界）
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (由二叉树的性质，x应该插在左子树) {
        insert(Node[root].lchild, x); //往左子树搜索（递归式）
    } else {
        insert(Node[root].rchild, x); //往右子树搜索（递归式）
    }
}

//二叉树的建立，函数返回根结点root的下标
int Create(int data[], int n) {
    node* root = -1; //新建空根结点root
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //将data[0]-data[n-1]插入二叉树中
    }
    return root; //返回根结点
}

//先序遍历
void preorder(int root) {
    if (root == -1) {
        return; //到达空树，递归边界
    }
    printf("%d\n", Node[root].data); //访问根结点root，例如将其数据域输出
    preorder(Node[root].lchild); //访问左子树
    preorder(Node[root].rchild); //访问右子树
}

//中序遍历
void inorder(int root) {
    if (root == -1) {
        return; //到达空树，递归边界
    }
    inorder(Node[root].lchild); //访问左子树
    printf("%d\n", Node[root].data); //访问根结点root，例如将其数据域输出
    inorder(Node[root].rchild); //访问右子树
}

//后序遍历
void postorder(int root) {
    if (root == -1) {
        return; //到达空树，递归边界
    }
    postorder(Node[root].lchild); //访问左子树
    postorder(Node[root].rchild); //访问右子树
    printf("%d\n", Node[root].data); //访问根结点root，例如将其数据域输出
}

//层序遍历
void LayerOrder(int root) {
    queue<int> q; //此处队列里存放结点下标
    q.push(root); //将根结点地址入队
    while (!q.empty()) {
        node* now = q.front(); //取出队首元素
        q.pop();
        printf("%d\n", Node[now].data); //访问队首元素
        if (Node[now].lchild != -1)
            q.push(Node[now].lchild); //左子树非空
        if (Node[now].rchild != -1)
            q.push(Node[now].rchild); //右子树非空
    }
}
