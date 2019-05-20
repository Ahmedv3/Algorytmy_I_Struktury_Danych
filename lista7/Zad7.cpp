#include <iostream>


    class UnionFind 
    {
        public:
             UnionFind(int n) : m_parent{new int[n]},m_rank{new int[n]}
            {
                for(int i = 0; i < n; ++i)
                {
                    m_parent[i] = i;
                    m_rank[i]   = 0;
                }
            }
            int find(int i)
            {
                if(m_parent[i] == i)
                    return i;
                return m_parent[i] = find(m_parent[i]);
            }
            void make_union(int i, int j)
            {
                int a = find(i);
                int b = find(j); 
                if(a!=b)
                    if(m_rank[a] < m_rank[b])
                        m_parent[a] = b;
                    else if(m_rank[b] < m_rank[a])
                        m_parent[b] = a;
                    else
                    {
                        m_parent[a] = b;
                        ++m_rank[b];
                    }
            }
            ~UnionFind()
            {
                delete[] m_parent;
                delete[] m_rank;
            }
        private:
            int* m_parent;
            int* m_rank;
    };
    int countIslands(int n, const bool a[][5])
    {
        UnionFind obj(n*n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(!a[i][j])
                    continue;
                if(i+1 < n && a[i+1][j])
                    obj.make_union(i*n+j,(i+1)*n+j);
                if(i-1 >= 0 && a[i-1][j])
                    obj.make_union(i*n+j,(i-1)*n+j);
                if(j-1 >= 0 && a[i][j-1])
                    obj.make_union(i*n+j,i*n+j-1);
                if(j+1 < n && a[i][j+1])
                    obj.make_union(i*n+j,i*n+j+1); 
            }
        bool temp[n*n] = {0};
        int numberOfIslands = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(a[i][j])
                {
                    int x = obj.find(i*n+j);
                    if(!temp[x])
                    {
                        ++numberOfIslands;
                        temp[x] = 1;
                    }
                        
                }  
        return numberOfIslands;
    }

int main()
{
    const int n = 5;
    bool t[n][n] = {{1,1,0,0,0},
                    {0,1,0,0,0},
                    {0,0,1,0,0},
                    {0,0,0,1,0},
                    {1,0,1,0,1}};
    std::cout << countIslands(n,t) << std::endl;
}