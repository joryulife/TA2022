class Quiz {
    int[] val = {0,0};

    synchronized void shift(int from,int to){
        val[from]--;
        val[to]++;
    }

    public Thread startJob (final int from,final int to){
        Thread th = new Thread(){
            public void run(){
                for(int i = 0;i < 10000;i++){
                    shift(from, to);
                }
            }
        };
        th.start();
        return th;
    }

    public static void main(String[] args){
        Quiz q = new Quiz();
        Thread th1 = q.startJob(0,1);
        Thread th2 = q.startJob(1, 0);
        try{
            th1.join();
            th2.join();
        }catch(InterruptedException e){

        }
        System.out.printf("val = {%d,%d}\n",q.val[0],q.val[1]);
    }
}