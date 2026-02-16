public class Player1 implements Runnable{

    @Override
    public void run() {
        for (int i = 0; i < 250; i++) {
            System.out.println("Ping");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}