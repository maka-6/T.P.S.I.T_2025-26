public class Player2 implements Runnable{

    @Override
    public void run() {
        for (int i = 0; i < 250; i++) {
            System.out.println("Pong");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}