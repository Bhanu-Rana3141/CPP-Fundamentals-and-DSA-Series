        sum = a+b;
        cout << sum << " ";
    }cout << endl;
    return sum;
}

int fibo(int n) {
    if(n == 0) 
        return 0;
    if(n == 1)
        return 1;
    
    return fibo(n-1) + fibo(n-2);