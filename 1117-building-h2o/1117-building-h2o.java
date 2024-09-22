class H2O {
    private int hydrogen = 0;
    private int oxygen = 0;
    public synchronized void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		while(oxygen == 0 && hydrogen == 2){
            wait();
        }

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        hydrogen++;
        if(hydrogen == 2 && oxygen == 1){
            hydrogen = oxygen = 0;
        }
        this.notifyAll();
    }

    public synchronized void oxygen(Runnable releaseOxygen) throws InterruptedException {
        while(oxygen == 1 && hydrogen < 2){
            wait();
        }
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        oxygen++;
        if(hydrogen == 2 && oxygen == 1){
            hydrogen = oxygen = 0;
        }
        this.notifyAll();
    }
}