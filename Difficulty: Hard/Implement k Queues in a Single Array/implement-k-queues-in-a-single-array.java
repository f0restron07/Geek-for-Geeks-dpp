class kQueues {
    int[] a, nx, fr, re;
    int f;
    
    kQueues(int n, int k) {
        a = new int[n];
        nx = new int[n];
        fr = new int[k];
        re = new int[k];
        
        // Initialize all queues as empty
        for(int i = 0; i < k; i++) {
            fr[i] = -1;
            re[i] = -1;
        }

        f = 0;
        for(int i = 0; i < n - 1; i++) {
            nx[i] = i + 1;
        }
        nx[n - 1] = -1;
    }
    
    void enqueue(int x, int i) {
        if(f == -1) return; 
        

        int idx = f;
        f = nx[idx];

        a[idx] = x;
        nx[idx] = -1;

        if(fr[i] == -1) {

            fr[i] = idx;
        } else {

            nx[re[i]] = idx;
        }
        re[i] = idx;
    }
    
    int dequeue(int i) {
        if(fr[i] == -1) return -1; 

        int idx = fr[i];
        int val = a[idx];

        fr[i] = nx[idx];
        if(fr[i] == -1) {
            re[i] = -1; 
        }

        nx[idx] = f;
        f = idx;
        
        return val;
    }
    
    boolean isEmpty(int i) {
        return fr[i] == -1;
    }
    
    boolean isFull() {
        return f == -1;
    }
}