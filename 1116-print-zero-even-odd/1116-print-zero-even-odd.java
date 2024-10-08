class ZeroEvenOdd {
    private int n;
    private int counter = 1;
    private boolean lock = false;
    // false zero can enter and odd and even no need to be stooped
    // true even or odd will run and zero must wait
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        while(counter <= n){
            if(lock == true){
                this.wait();
                continue;
            }
            printNumber.accept(0);
            lock = true;
            this.notifyAll();
        }
    }

    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        while(counter <= n){
            if(lock == false || counter % 2 == 1){
                this.wait();
                continue;
            }
            printNumber.accept(counter);
            counter++;
            lock = false;
            this.notifyAll();
        }
    }

    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        while(counter <= n){
            if(lock == false || counter % 2 == 0){
                this.wait();
                continue;
            }
            printNumber.accept(counter);
            counter++;
            lock = false;
            this.notifyAll();
        }
    }
}