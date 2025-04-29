using System.Threading;
    
public class Foo1 {
    
    private readonly Semaphore  _sign1;
    private readonly Semaphore  _sign2;

    public Foo() {
        _sign1 = new Semaphore (0, 1);
        _sign2 = new Semaphore (0, 1);
    }

    public void First(Action printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        _sign1.Release();
    }

    public void Second(Action printSecond) {
        _sign1.WaitOne();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        _sign2.Release();
    }

    public void Third(Action printThird) {
        _sign2.WaitOne();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}