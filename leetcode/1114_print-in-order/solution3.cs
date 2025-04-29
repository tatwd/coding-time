using System.Threading;
    
public class Foo3 {
    
    private readonly AutoResetEvent    _sign1;
    private readonly AutoResetEvent    _sign2;

    public Foo() {
        _sign1 = new AutoResetEvent(false);
        _sign2 = new AutoResetEvent(false);
    }

    public void First(Action printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        _sign1.Set();
    }

    public void Second(Action printSecond) {
        _sign1.WaitOne();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        _sign2.Set();
    }

    public void Third(Action printThird) {
        _sign2.WaitOne();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}