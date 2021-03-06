/**
* 深度优先搜索
**/

/**
* 问题：有n件物品，每件物品的重量为w[i]，价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中
*       使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品的价值之和最大，求最大价值（1≤n≤20）
**/
#include <cstdio>
const int maxn = 30;

int n, V, maxValue = 0; //物品件数n，背包容量V，最大价值maxValue
int w[maxn], c[maxn]; //每件物品重量w[i]，每件物品价值c[i]

//DFS,index为当前处理的物品编号
//sumW,sumC分别为当前总重量和当前总价值
void DFS(int index, int sumW, int sumC) {
    //已经完成对n件物品的选择（死胡同）
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC; //不超过背包容量时更新最大价值maxValue
        }
        return;
    }
    //岔道口
    DFS(index + 1, sumW, sumC); //不选第index件物品
    DFS(index + 1, sumW + w[index], sumC + c[index]); //选第index件物品
}

//使用剪枝的方法优化DFS
void DFS(int index, int sumW, int sumC) {
    if (index == n)
        return; //已经完成对n件物品的选择
    DFS(index + 1, sumW, sumC); //不选第index件物品
    //只有加入第index件物品后未超过容量V才能继续
    if (sumW + w[index] <= V) {
        if (sumC + c[index] > ans)
            ans += sumC + c[index]; //更新最大价值maxValue
        DFS(index + 1, sumW + w[index], sumC + c[index]); //选第index件物品
    }
}

int main() {
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]); //每件物品的重量
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]); //每件物品的价值
    DFS(0, 0, 0); //初始时为第0件物品，当前总重量和总价值为0
    printf("%d\n", maxValue);
    return 0;
}
