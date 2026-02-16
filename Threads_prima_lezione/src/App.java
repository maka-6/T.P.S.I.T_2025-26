
public class App {
    public static void main(String[] args) {
        //FirstThread firstThread = new FirstThread("galactus");
        //FirstThread secondThread = new FirstThread("stefanus");

        //firstThread.start();
        //secondThread.start();

        //System.out.println(firstThread.getName());
        //System.out.println(secondThread.getName());


        Thread p1 = new Thread(new Player1());
        Thread p2 = new Thread(new Player2());

        p1.start();
        p2.start();
    }
}