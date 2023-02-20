// Java thread intercommunication

class Processor {
  public void produce() throws InterruptedException {
    synchronized (this) {
      System.out.println("Producer thread running ...");
      wait();
      System.out.println("Resumed.");
    }
  }

  public void consume() throws InterruptedException {
    Thread.sleep(1000);
    synchronized (this) {
      System.out.println("Consumer thread running ...");
      notify();
      System.out.println("Notify sent.");
    }
  }
}

public class Main {
  public static void main(String[] args) {
    Processor processor = new Processor();

    Thread t1 = new Thread(new Runnable() {
      public void run() {
        try {
          processor.produce();
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    });

    Thread t2 = new Thread(new Runnable() {
      public void run() {
        try {
          processor.consume();
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    });

    t1.start();
    t2.start();

    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
